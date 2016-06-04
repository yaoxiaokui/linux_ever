/*************************************************************************
	> File Name: sem.c
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Jun 2016 10:01:22 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

/****************************************************************
*   函数名称：pv(int semid, int sem_num, int op)
*   功能描述: 对semid信号集中第sem_num个信号量执行P操作或V操作
*   参数列表: semid指定一个信号量集合,
*             sem_num指定一个信号量集合中第几个信号量,
*             op为-1，表示执行P操作，将信号量的值减去1.
*             op为1，表示执行V操作，将信号量的值加1
*   返回结果: void
*****************************************************************/
void pv(int semid, int sem_num, int op)
{
    //假定的是对一个信号量进行操作，如果是对多个信号量进行操作，那么
    //sem_buf应该是数组，并且semop中第三个参数应该指定该数组的大小
    struct sembuf sem_buf;
    //0表示信号量集中的第一个信号量
    sem_buf.sem_num = sem_num;
    sem_buf.sem_op = op;
    sem_buf.sem_flg = SEM_UNDO;

    semop(semid, &sem_buf, 1);
}

/****************************************************************
*   函数名称：get_sem_val(int semid, int sem_num)
*   功能描述: 获得semid信号集中第sem_num个信号量的值
*   参数列表: semid指定一个信号量集合,
*             sem_num指定一个信号量集合中第几个信号量 
*   返回结果: 成功返回信号量的值，失败返回-1
*****************************************************************/
int get_sem_val(int semid, int sem_num)
{
   return semctl(semid, sem_num, GETVAL); 
}

/*****************************************************************
*
*   主函数：main
*
******************************************************************/

int main(int argc, char * argv[])
{
    //创建信号量
    //1表示信号量集中信号量的数目
    int semid = semget(IPC_PRIVATE, 1, 0666);
    
    union semun sem_un;
    sem_un.val = 1;//将信号量的值设为1

    semctl(semid, 0, SETVAL, sem_un);
    
    pid_t pid = fork();
    if(pid < 0){
        printf("fork error\n");
        return -1;
    }
    else if(pid == 0){//子进程
        printf("-------------------------------------------------------------------\n");
        printf("子进程尝试获得信号量之前信号量的值是: %d\n", get_sem_val(semid, 0));
        printf("子进程尝试获得信号量，执行P操作.\n");
        //P操作
        pv(semid, 0, -1);
        printf("子进程获得了信号量，并等待2秒之后释放该信号量。\n");
        printf("子进程获得信号量之后信号量的值是: %d\n", get_sem_val(semid, 0));
        sleep(2);
        pv(semid, 0, 1);
        printf("子进程释放信号量之后信号量的值是: %d\n", get_sem_val(semid, 0));
        printf("-------------------------------------------------------------------\n");
        exit(0);
    }
    else{//父进程
        printf("-------------------------------------------------------------------\n");
        printf("父进程尝试获得信号量之前信号量的值是: %d\n", get_sem_val(semid, 0));
        printf("父进程尝试获得信号量，执行P操作.\n");
        //P操作
        pv(semid, 0, -1);
        printf("父进程获得了信号量，并等待2秒之后释放该信号量。\n");
        printf("父进程获得信号量之后信号量的值是: %d\n", get_sem_val(semid, 0));
        sleep(2);
        pv(semid, 0, 1);
        printf("父进程释放信号量之后信号量的值是: %d\n", get_sem_val(semid, 0));
        printf("-------------------------------------------------------------------\n");
            
    }

    sleep(5);
    waitpid(pid, NULL, 0);

    semctl(semid, 0, IPC_RMID);


    return 0;
}
