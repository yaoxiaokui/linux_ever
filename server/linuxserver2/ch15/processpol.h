#ifndef PROCESSPOOL_H
#define PROCESSPOOL_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;


/**********************************************************
类名称：进程类process
类功能：抽象一个进程
类成员：m_pid是目标子进程的PID
		m_pipefd是父进程和子进程通信用的管道
类方法：
***********************************************************/
class process
{
public:
    process() : m_pid( -1 ){}

public:
    pid_t m_pid;
    int m_pipefd[2];
};

/***********************************************************
类名称：进程池类processpool
类功能：使用单例模式创建一个进程池
		在子进程中都会有一个processpool对象(每个子进程都有m_idx这些非静态的成员变量)，
		但是所有的processpool对象只有一个m_instance指向的进程池
类成员：模版参数T是处理逻辑任务的类	
		m_instance指向的是创建的进程池
类方法：create方法返回指向进程池的指针
***********************************************************/
template< typename T >
class processpool
{
private:
	//进程池的构造函数
    processpool( int listenfd, int process_number = 8 );
public:
	//使用单例模式，保证程序最多只能创建一个processpool实例
    static processpool< T >* create( int listenfd, int process_number = 8 )
    {
        if( !m_instance )
        {
            m_instance = new processpool< T >( listenfd, process_number );
        }
        return m_instance;
    }

	//进程池的析构函数
    ~processpool()
    {
        delete [] m_sub_process;
    }

	//启动进程池
    void run();

private:
    void setup_sig_pipe();
    void run_parent();
    void run_child();

private:
	//进程池允许的最大的子进程的数量
    static const int MAX_PROCESS_NUMBER = 16;

	//每个子进程最多能够处理的客户数量
    static const int USER_PER_PROCESS = 65536;

	//epoll最多能处理的事件数量
    static const int MAX_EVENT_NUMBER = 10000;

	//进程池中进程总数
    int m_process_number;

	//子进程在进程池中的序号，从0开始
    int m_idx;

	//每个进程都有一个epoll内核事件表，用m_epollfd标识
    int m_epollfd;

	//监听socket
    int m_listenfd;

	//子进程通过m_stop来决定是否停止运行
    int m_stop;

	//保存所有的子进程的描述信息
    process* m_sub_process;

	//进程池静态实例
    static processpool< T >* m_instance;
};

template< typename T >
processpool< T >* processpool< T >::m_instance = NULL;

//用于处理信号的管道，以实现统一事件源。也称之为信号管道
static int sig_pipefd[2];

//将文件描述符fd设置为非阻塞
static int setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

//将文件描述符fd的可读事件注册到epollfd指向的epoll内核事件表
static void addfd( int epollfd, int fd )
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}

//从epollfd指向的epoll内核事件表中移除文件描述符fd上所有注册事件
static void removefd( int epollfd, int fd )
{
    epoll_ctl( epollfd, EPOLL_CTL_DEL, fd, 0 );
    close( fd );
}

//信号处理函数,将信号值写入到信号管道中
static void sig_handler( int sig )
{
    int save_errno = errno;
    int msg = sig;
    send( sig_pipefd[1], ( char* )&msg, 1, 0 );
    errno = save_errno;
}

//注册信号sig的信号处理函数
static void addsig( int sig, void( handler )(int), bool restart = true )
{
    struct sigaction sa;
    memset( &sa, '\0', sizeof( sa ) );
    sa.sa_handler = handler;
    if( restart )
    {
        sa.sa_flags |= SA_RESTART;
    }
    sigfillset( &sa.sa_mask );
    assert( sigaction( sig, &sa, NULL ) != -1 );
}

/*******************************************************************************************
函数名称：processpool
函数功能：进程池类processpool的构造函数
参数列表：listenfd是监听socket，它必须在创建进程池之前被创建，否则子进程无法直接引用它。	
		  process_number参数指定进程池中子进程的数量
返回结果：create方法返回指向进程池的指针
*******************************************************************************************/
template< typename T >
processpool< T >::processpool( int listenfd, int process_number ) 
    : m_listenfd( listenfd ), m_process_number( process_number ), m_idx( -1 ), m_stop( false )
{
    assert( ( process_number > 0 ) && ( process_number <= MAX_PROCESS_NUMBER ) );

	//m_sub_process指向的数组保存进程池中所有进程的信息(pid和通信管道)
    m_sub_process = new process[ process_number ];
    assert( m_sub_process );

	//创建process_number个子进程,并建立它们和父进程之间的管道
	//父进程从管道中读出数据，子进程从管道中写入数据
    for( int i = 0; i < process_number; ++i )
    {
        int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, m_sub_process[i].m_pipefd );
        assert( ret == 0 );

        m_sub_process[i].m_pid = fork();
        assert( m_sub_process[i].m_pid >= 0 );
        if( m_sub_process[i].m_pid > 0 )//父进程关闭通信管道的读端
        {
            close( m_sub_process[i].m_pipefd[0] );
            continue;
        }
        else//子进程关闭通信管道的写端
        {
            close( m_sub_process[i].m_pipefd[1] );
            m_idx = i;
            break;
        }
    }
}


/*******************************************************************************************
函数名称：setup_sig_pipe
函数功能：统一事件源
参数列表：无
返回结果：void
*******************************************************************************************/
template< typename T >
void processpool< T >::setup_sig_pipe()
{
	//创建epoll事件监听表
    m_epollfd = epoll_create( 5 );
    assert( m_epollfd != -1 );

	//创建信号管道
    int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, sig_pipefd );
    assert( ret != -1 );

	//将信号的写端描述符设置为非阻塞
    setnonblocking( sig_pipefd[1] );

	//将信号的读端描述符添加到m_epollfd指向的epoll内核事件表中
	addfd( m_epollfd, sig_pipefd[0] );

	//添加信号处理，在信号处理函数中将信号直接写到信号管道sig_pipefd[1]中
    addsig( SIGCHLD, sig_handler );
    addsig( SIGTERM, sig_handler );
    addsig( SIGINT, sig_handler );

	//忽略信号SIGPIPE
    addsig( SIGPIPE, SIG_IGN );
}

/*******************************************************************************************
函数名称：run
函数功能：运行进程,父进程中m_idx=-1，子进程中m_idx大于等于0
参数列表：无
返回结果：void
*******************************************************************************************/
template< typename T >
void processpool< T >::run()
{
    if( m_idx != -1 )
    {
        run_child();
        return;
    }
    run_parent();
}

/*******************************************************************************************
函数名称：run_child
函数功能：运行子进程
参数列表：无
返回结果：void
*******************************************************************************************/
template< typename T >
void processpool< T >::run_child()
{
    //延迟m_idx*2秒，主要是为了打印下面的输出语句，否则有时候不会出现所有的子进程的输出
    sleep(m_idx*2);
    cout << "run_child " << m_idx << endl;
	//统一事件源
    setup_sig_pipe();

	//每个子进程都通过其在进程池中的序号值m_idx找到与父进程通信的管道
    int pipefd = m_sub_process[m_idx].m_pipefd[ 0 ];

	//子进程需要监听管道文件描述符pipefd，父进程将通过它来通知子进程accept新连接
    addfd( m_epollfd, pipefd );

    epoll_event events[ MAX_EVENT_NUMBER ];
    int number = 0;
    int ret = -1;

    while( ! m_stop )
    {
        number = epoll_wait( m_epollfd, events, MAX_EVENT_NUMBER, -1 );
        if ( ( number < 0 ) && ( errno != EINTR ) )
        {
            printf( "epoll failure\n" );
            break;
        }

        for ( int i = 0; i < number; i++ )
        {
            int sockfd = events[i].data.fd;

            if( ( sockfd == sig_pipefd[0] ) && ( events[i].events & EPOLLIN ) )//如果是收到信号
            {
                int sig;
                char signals[1024];
                ret = recv( sig_pipefd[0], signals, sizeof( signals ), 0 );//将信号管道中所有的信号全部取走，然后一个一个地处理
                if( ret <= 0 )
                {
                    continue;
                }
                else
                {
					//一个一个地处理所有的信号
                    for( int i = 0; i < ret; ++i )
                    {
                        switch( signals[i] )
                        {
                            case SIGCHLD:
                            {
                                pid_t pid;
                                int stat;
                                while ( ( pid = waitpid( -1, &stat, WNOHANG ) ) > 0 )
                                {
                                    continue;
                                }
                                break;
                            }
                            case SIGTERM:
                            case SIGINT:
                            {
                                m_stop = true;
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }

    close( pipefd );
    //close( m_listenfd );
    close( m_epollfd );
}


/*******************************************************************************************
函数名称：run_parent
函数功能：运行父进程
参数列表：无
返回结果：void
*******************************************************************************************/
template< typename T >
void processpool< T >::run_parent()
{
    cout << "run_parent............." << endl;

    setup_sig_pipe();

    addfd( m_epollfd, m_listenfd );

    epoll_event events[ MAX_EVENT_NUMBER ];
    int sub_process_counter = 0;
    int new_conn = 1;
    int number = 0;
    int ret = -1;

    while( ! m_stop )
    {
        number = epoll_wait( m_epollfd, events, MAX_EVENT_NUMBER, -1 );
        if ( ( number < 0 ) && ( errno != EINTR ) )
        {
            printf( "epoll failure\n" );
            break;
        }

        for ( int i = 0; i < number; i++ )
        {
            int sockfd = events[i].data.fd;

            if( ( sockfd == sig_pipefd[0] ) && ( events[i].events & EPOLLIN ) )//如果信号管道可读，则读取信号
            {
                int sig;
                char signals[1024];

				//读取信号管道中的所有信号，然后一个一个地处理这些信号
                ret = recv( sig_pipefd[0], signals, sizeof( signals ), 0 );
                if( ret <= 0 )
                {
                    continue;
                }
                else
                {
					//依次处理所有信号
                    for( int i = 0; i < ret; ++i )
                    {
                        switch( signals[i] )
                        {
                            case SIGCHLD:
                            {
                                pid_t pid;
                                int stat;
								//等待子进程终止
                                while ( ( pid = waitpid( -1, &stat, WNOHANG ) ) > 0 )
                                {
                                    for( int i = 0; i < m_process_number; ++i )
                                    {
										//如果进程池中的第i个子进程退出了，则主进程关闭相应的通信管道，
										//并设置相应的m_pid为-1，以标识该子进程已经退出
                                        if( m_sub_process[i].m_pid == pid )
                                        {
                                            printf( "child %d join\n", i );
                                            close( m_sub_process[i].m_pipefd[1] );
                                            m_sub_process[i].m_pid = -1;
                                        }
                                    }
                                }
                                m_stop = true;
								//如果所有子进程都退出了，则父进程也退出
                                for( int i = 0; i < m_process_number; ++i )
                                {
                                    if( m_sub_process[i].m_pid != -1 )
                                    {
                                        m_stop = false;
                                    }
                                }
                                break;
                            }
                            case SIGTERM:
                            case SIGINT:
                            {
								//如果父进程接收到终止信号，那么就杀死所有子进程，并等待它们结束(上面的对信号SIGCHLD的处理)
                                printf( "kill all the clild now\n" );
                                for( int i = 0; i < m_process_number; ++i )
                                {
                                    int pid = m_sub_process[i].m_pid;
                                    if( pid != -1 )
                                    {
                                        kill( pid, SIGTERM );
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }

    //close( m_listenfd );
    close( m_epollfd );
}

#endif
