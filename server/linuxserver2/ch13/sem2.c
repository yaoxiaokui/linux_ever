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
#include <errno.h>


//该结构体在使用semctl的时候使用
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};


/****************************************************************
*   函数名称：sem_create(key_t key, int sem_num)
*   功能描述: 创建一个键值为key的信号量集，信号量数目为sem_num
*   参数列表: key表示信号量集的唯一标识
*             sem_num指定一个信号量集合中创建几个信号量,
*   返回结果: -1表示失败，成功则返回信号量的唯一标识符 
*****************************************************************/
int sem_create(key_t key, int sem_num)
{
    return semget(key, sem_num, 0666 | IPC_CREAT | IPC_EXCL);
}

/****************************************************************
*   函数名称：sem_open(key_t key)
*   功能描述: 打开一个键值为key的信号量集
*   参数列表: key表示信号量集的唯一标识
*   返回结果: -1表示失败，成功则返回信号量的唯一标识符 
*****************************************************************/
int sem_open(key_t key)
{
    return semget(key, 0, 0666);
}

/****************************************************************
*   函数名称：sem_setval(int semid, int sem_num, int val)
*   功能描述: 将semid标识的信号量集的第sem_num个信号量的值设为val
*   参数列表: semid标识一个信号量集，sem_num指定一个信号量集合中第几个信号量,
*             val是将信号量设置的值,一般为1
*   返回结果: -1表示失败，成功则返回信号量的唯一标识符 
*****************************************************************/
int sem_setval(int semid, int sem_num, int val)
{
    union semun sem_un;
    sem_un.val = val;//将信号量的值设为val,一般为1

    return semctl(semid, sem_num, SETVAL, sem_un);
}


/****************************************************************
*   函数名称：sem_v(int semid, int sem_num)
*   功能描述: 对semid信号集中第sem_num个信号量执行V操作
*   参数列表: semid指定一个信号量集合,
*             sem_num指定一个信号量集合中第几个信号量,
*   返回结果: 0表示成功，-1表示失败 
*****************************************************************/
int sem_v(int semid, int sem_num)
{
    //假定的是对一个信号量进行操作，如果是对多个信号量进行操作，那么
    //sem_buf应该是数组，并且semop中第三个参数应该指定该数组的大小
    struct sembuf sem_buf;
    //0表示信号量集中的第一个信号量
    sem_buf.sem_num = sem_num;
    sem_buf.sem_op = 1;
    sem_buf.sem_flg = SEM_UNDO;

    //对信号量的值加上1
    return semop(semid, &sem_buf, 1);
}

/****************************************************************
*   函数名称：sem_p(int semid, int sem_num)
*   功能描述: 对semid信号集中第sem_num个信号量执行P操作或V操作
*   参数列表: semid指定一个信号量集合,
*             sem_num指定一个信号量集合中第几个信号量,
*   返回结果: 0表示成功，-1表示失败
*****************************************************************/
int sem_p(int semid, int sem_num)
{
    //假定的是对一个信号量进行操作，如果是对多个信号量进行操作，那么
    //sem_buf应该是数组，并且semop中第三个参数应该指定该数组的大小
    struct sembuf sem_buf;
    //0表示信号量集中的第一个信号量
    sem_buf.sem_num = sem_num;
    sem_buf.sem_op = -1;
    sem_buf.sem_flg = SEM_UNDO;

    //对信号量的值加上-1
    return semop(semid, &sem_buf, 1);
}

/****************************************************************
*   函数名称：sem_getval(int semid, int sem_num)
*   功能描述: 获得semid信号集中第sem_num个信号量的值
*   参数列表: semid指定一个信号量集合,
*             sem_num指定一个信号量集合中第几个信号量 
*   返回结果: 成功返回信号量的值，失败返回-1
*****************************************************************/
int sem_getval(int semid, int sem_num)
{
   return semctl(semid, sem_num, GETVAL); 
}

/****************************************************************
*   函数名称：sem_rm(int semid)
*   功能描述: 删除semid标识的信号量集
*   参数列表: semid标识一个信号量集合,
*   返回结果: 失败返回-1，成功返回0
*****************************************************************/
int sem_rm(int semid)
{
    return semctl(semid, 0, IPC_RMID, 0);
}


/*****************************************************************
*
*   主函数：main
*
******************************************************************/

int main(int argc, char * argv[])
{
    //创建key为0x1234，数量为5的信号量集
    int semid = sem_create(0x1234, 5);
    if(semid == -1){
        if(errno == EEXIST)
            semid = sem_open(0x1234);
        else{
            printf("sem_create error\n");
            return -1;
        }
    }
    
    //将信号量集中的第4个信号量的值设置为1
    int sem_num = 4;
    sem_setval(semid, sem_num, 1);

    
    pid_t pid = fork();
    if(pid < 0){
        printf("fork error\n");
        return -1;
    }
    else if(pid == 0){//子进程
        printf("-------------------------------------------------------------------\n");
        printf("子进程尝试获得信号量之前信号量的值是: %d\n", sem_getval(semid, sem_num));
        printf("子进程尝试获得信号量，执行P操作.\n");
        //P操作
        sem_p(semid, sem_num);
        printf("子进程获得了信号量，并等待2秒之后释放该信号量。\n");
        printf("子进程获得信号量之后信号量的值是: %d\n", sem_getval(semid, sem_num));
        sleep(2);
        sem_v(semid, sem_num);
        printf("子进程释放信号量之后信号量的值是: %d\n", sem_getval(semid, sem_num));
        printf("-------------------------------------------------------------------\n");
        exit(0);
    }
    else{//父进程
        printf("-------------------------------------------------------------------\n");
        printf("父进程尝试获得信号量之前信号量的值是: %d\n", sem_getval(semid, sem_num));
        printf("父进程尝试获得信号量，执行P操作.\n");
        //P操作
        sem_p(semid, sem_num);
        printf("父进程获得了信号量，并等待2秒之后释放该信号量。\n");
        printf("父进程获得信号量之后信号量的值是: %d\n", sem_getval(semid, sem_num));
        sleep(2);
        sem_v(semid, sem_num);
        printf("父进程释放信号量之后信号量的值是: %d\n", sem_getval(semid, sem_num));
        printf("-------------------------------------------------------------------\n");
            
    }

    sleep(5);
    waitpid(pid, NULL, 0);

    //semctl(semid, sem_num, IPC_RMID, sem_un);
    sem_rm(semid);


    return 0;
}
