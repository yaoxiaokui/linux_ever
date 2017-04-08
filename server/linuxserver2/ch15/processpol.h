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
�����ƣ�������process
�๦�ܣ�����һ������
���Ա��m_pid��Ŀ���ӽ��̵�PID
		m_pipefd�Ǹ����̺��ӽ���ͨ���õĹܵ�
�෽����
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
�����ƣ����̳���processpool
�๦�ܣ�ʹ�õ���ģʽ����һ�����̳�
		���ӽ����ж�����һ��processpool����(ÿ���ӽ��̶���m_idx��Щ�Ǿ�̬�ĳ�Ա����)��
		�������е�processpool����ֻ��һ��m_instanceָ��Ľ��̳�
���Ա��ģ�����T�Ǵ����߼��������	
		m_instanceָ����Ǵ����Ľ��̳�
�෽����create��������ָ����̳ص�ָ��
***********************************************************/
template< typename T >
class processpool
{
private:
	//���̳صĹ��캯��
    processpool( int listenfd, int process_number = 8 );
public:
	//ʹ�õ���ģʽ����֤�������ֻ�ܴ���һ��processpoolʵ��
    static processpool< T >* create( int listenfd, int process_number = 8 )
    {
        if( !m_instance )
        {
            m_instance = new processpool< T >( listenfd, process_number );
        }
        return m_instance;
    }

	//���̳ص���������
    ~processpool()
    {
        delete [] m_sub_process;
    }

	//�������̳�
    void run();

private:
    void setup_sig_pipe();
    void run_parent();
    void run_child();

private:
	//���̳�����������ӽ��̵�����
    static const int MAX_PROCESS_NUMBER = 16;

	//ÿ���ӽ�������ܹ�����Ŀͻ�����
    static const int USER_PER_PROCESS = 65536;

	//epoll����ܴ�����¼�����
    static const int MAX_EVENT_NUMBER = 10000;

	//���̳��н�������
    int m_process_number;

	//�ӽ����ڽ��̳��е���ţ���0��ʼ
    int m_idx;

	//ÿ�����̶���һ��epoll�ں��¼�����m_epollfd��ʶ
    int m_epollfd;

	//����socket
    int m_listenfd;

	//�ӽ���ͨ��m_stop�������Ƿ�ֹͣ����
    int m_stop;

	//�������е��ӽ��̵�������Ϣ
    process* m_sub_process;

	//���̳ؾ�̬ʵ��
    static processpool< T >* m_instance;
};

template< typename T >
processpool< T >* processpool< T >::m_instance = NULL;

//���ڴ����źŵĹܵ�����ʵ��ͳһ�¼�Դ��Ҳ��֮Ϊ�źŹܵ�
static int sig_pipefd[2];

//���ļ�������fd����Ϊ������
static int setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

//���ļ�������fd�Ŀɶ��¼�ע�ᵽepollfdָ���epoll�ں��¼���
static void addfd( int epollfd, int fd )
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}

//��epollfdָ���epoll�ں��¼������Ƴ��ļ�������fd������ע���¼�
static void removefd( int epollfd, int fd )
{
    epoll_ctl( epollfd, EPOLL_CTL_DEL, fd, 0 );
    close( fd );
}

//�źŴ�����,���ź�ֵд�뵽�źŹܵ���
static void sig_handler( int sig )
{
    int save_errno = errno;
    int msg = sig;
    send( sig_pipefd[1], ( char* )&msg, 1, 0 );
    errno = save_errno;
}

//ע���ź�sig���źŴ�����
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
�������ƣ�processpool
�������ܣ����̳���processpool�Ĺ��캯��
�����б�listenfd�Ǽ���socket���������ڴ������̳�֮ǰ�������������ӽ����޷�ֱ����������	
		  process_number����ָ�����̳����ӽ��̵�����
���ؽ����create��������ָ����̳ص�ָ��
*******************************************************************************************/
template< typename T >
processpool< T >::processpool( int listenfd, int process_number ) 
    : m_listenfd( listenfd ), m_process_number( process_number ), m_idx( -1 ), m_stop( false )
{
    assert( ( process_number > 0 ) && ( process_number <= MAX_PROCESS_NUMBER ) );

	//m_sub_processָ������鱣����̳������н��̵���Ϣ(pid��ͨ�Źܵ�)
    m_sub_process = new process[ process_number ];
    assert( m_sub_process );

	//����process_number���ӽ���,���������Ǻ͸�����֮��Ĺܵ�
	//�����̴ӹܵ��ж������ݣ��ӽ��̴ӹܵ���д������
    for( int i = 0; i < process_number; ++i )
    {
        int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, m_sub_process[i].m_pipefd );
        assert( ret == 0 );

        m_sub_process[i].m_pid = fork();
        assert( m_sub_process[i].m_pid >= 0 );
        if( m_sub_process[i].m_pid > 0 )//�����̹ر�ͨ�Źܵ��Ķ���
        {
            close( m_sub_process[i].m_pipefd[0] );
            continue;
        }
        else//�ӽ��̹ر�ͨ�Źܵ���д��
        {
            close( m_sub_process[i].m_pipefd[1] );
            m_idx = i;
            break;
        }
    }
}


/*******************************************************************************************
�������ƣ�setup_sig_pipe
�������ܣ�ͳһ�¼�Դ
�����б���
���ؽ����void
*******************************************************************************************/
template< typename T >
void processpool< T >::setup_sig_pipe()
{
	//����epoll�¼�������
    m_epollfd = epoll_create( 5 );
    assert( m_epollfd != -1 );

	//�����źŹܵ�
    int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, sig_pipefd );
    assert( ret != -1 );

	//���źŵ�д������������Ϊ������
    setnonblocking( sig_pipefd[1] );

	//���źŵĶ�����������ӵ�m_epollfdָ���epoll�ں��¼�����
	addfd( m_epollfd, sig_pipefd[0] );

	//����źŴ������źŴ������н��ź�ֱ��д���źŹܵ�sig_pipefd[1]��
    addsig( SIGCHLD, sig_handler );
    addsig( SIGTERM, sig_handler );
    addsig( SIGINT, sig_handler );

	//�����ź�SIGPIPE
    addsig( SIGPIPE, SIG_IGN );
}

/*******************************************************************************************
�������ƣ�run
�������ܣ����н���,��������m_idx=-1���ӽ�����m_idx���ڵ���0
�����б���
���ؽ����void
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
�������ƣ�run_child
�������ܣ������ӽ���
�����б���
���ؽ����void
*******************************************************************************************/
template< typename T >
void processpool< T >::run_child()
{
    //�ӳ�m_idx*2�룬��Ҫ��Ϊ�˴�ӡ����������䣬������ʱ�򲻻�������е��ӽ��̵����
    sleep(m_idx*2);
    cout << "run_child " << m_idx << endl;
	//ͳһ�¼�Դ
    setup_sig_pipe();

	//ÿ���ӽ��̶�ͨ�����ڽ��̳��е����ֵm_idx�ҵ��븸����ͨ�ŵĹܵ�
    int pipefd = m_sub_process[m_idx].m_pipefd[ 0 ];

	//�ӽ�����Ҫ�����ܵ��ļ�������pipefd�������̽�ͨ������֪ͨ�ӽ���accept������
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

            if( ( sockfd == sig_pipefd[0] ) && ( events[i].events & EPOLLIN ) )//������յ��ź�
            {
                int sig;
                char signals[1024];
                ret = recv( sig_pipefd[0], signals, sizeof( signals ), 0 );//���źŹܵ������е��ź�ȫ��ȡ�ߣ�Ȼ��һ��һ���ش���
                if( ret <= 0 )
                {
                    continue;
                }
                else
                {
					//һ��һ���ش������е��ź�
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
�������ƣ�run_parent
�������ܣ����и�����
�����б���
���ؽ����void
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

            if( ( sockfd == sig_pipefd[0] ) && ( events[i].events & EPOLLIN ) )//����źŹܵ��ɶ������ȡ�ź�
            {
                int sig;
                char signals[1024];

				//��ȡ�źŹܵ��е������źţ�Ȼ��һ��һ���ش�����Щ�ź�
                ret = recv( sig_pipefd[0], signals, sizeof( signals ), 0 );
                if( ret <= 0 )
                {
                    continue;
                }
                else
                {
					//���δ��������ź�
                    for( int i = 0; i < ret; ++i )
                    {
                        switch( signals[i] )
                        {
                            case SIGCHLD:
                            {
                                pid_t pid;
                                int stat;
								//�ȴ��ӽ�����ֹ
                                while ( ( pid = waitpid( -1, &stat, WNOHANG ) ) > 0 )
                                {
                                    for( int i = 0; i < m_process_number; ++i )
                                    {
										//������̳��еĵ�i���ӽ����˳��ˣ��������̹ر���Ӧ��ͨ�Źܵ���
										//��������Ӧ��m_pidΪ-1���Ա�ʶ���ӽ����Ѿ��˳�
                                        if( m_sub_process[i].m_pid == pid )
                                        {
                                            printf( "child %d join\n", i );
                                            close( m_sub_process[i].m_pipefd[1] );
                                            m_sub_process[i].m_pid = -1;
                                        }
                                    }
                                }
                                m_stop = true;
								//��������ӽ��̶��˳��ˣ��򸸽���Ҳ�˳�
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
								//��������̽��յ���ֹ�źţ���ô��ɱ�������ӽ��̣����ȴ����ǽ���(����Ķ��ź�SIGCHLD�Ĵ���)
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
