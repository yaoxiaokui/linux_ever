#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include "myipc_sem.h"


union semun {
int              val;    /* Value for SETVAL */
struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
unsigned short  *array;  /* Array for GETALL, SETALL */
struct seminfo  *__buf;  /* Buffer for IPC_INFO
                           (Linux specific) */
};

//@返回值 0 正确 其他错误
int sem_creat(int key, int *semid)
{
	int 	ret = 0;
	//int 	tmpsemid = 0;
	
	if (semid == NULL)
	{
		ret = SEMERR_PARAM;
		printf("func sem_creat() err:%d\n", ret);
		return ret;
	}
	ret = semget(key, 1, 0666| IPC_CREAT | IPC_EXCL); 
	if (ret == -1)
	{
			ret = errno;
			//perror("semget");
			if (errno == EEXIST) 
			{
				ret = SEMERR_EEXIST;
				printf("func sem_creat() 检测到信号量集已经存在:%d\n", ret);
				return ret;
			}
	}
	*semid = ret;
	
	ret = sem_setval(*semid, 1);
	if (ret != 0)
	{
		printf("func sem_setval() err:%d\n", ret);
		return ret;
	}
	ret = 0;
	return ret;
}   

int sem_open(int key, int *semid)
{
	int ret = 0;
	
	if (semid == NULL)
	{
		ret = SEMERR_PARAM;
		printf("func sem_open() err:%d\n", ret);
		return ret;
	}
	
	ret = semget(key, 0, 0); 
	if (ret == -1)
	{
			ret = errno;
			printf("func sem_open() 失败:%d\n", ret);
			return ret;	
	}
	*semid = ret;
	ret = 0;
	return ret;
}  

int sem_setval(int semid, int val)
{
	int ret = 0;
	union semun su;
	su.val = val;
	ret = semctl(semid, 0,  SETVAL, su);
	return ret;
}

/*
int sem_getval(int semid, int *val)
{
	int ret = 0;
	int tmpval;
	if (val == NULL)
	{
		ret = SEMERR_PARAM;
		printf("func sem_getval() err:%d\n", ret);
		return ret;
	}
	union semun su;
	tmpval = su.val ;
	ret = semctl(semid, 0, GETVAL, su);
	*val = tmpval  ;
	printf("val:%d\n", tmpval);
	return ret;
}
*/
int sem_getval(int semid, int *myval)
{
	int ret = 0;
	int val;
	union semun su;
	val = su.val ;
	//信号量 计数值
	ret = semctl(semid, 0, GETVAL, su);
	//printf("val:%d\n", val);
	
	*myval = ret;
	ret = 0;
	return ret;
}

//信号量p操作时候，需要传递好几个信息给linux内核
//所以linux内核定义了一个结构
//我要操作信号量集的下标 0
//我要执行什么操作 -1 +1
//我按照什么策略执行操作 0  UNDO NOWAITing
int sem_p(int semid)
{
	struct sembuf buf = {0, -1, 0};
	int ret = 0;
	ret = semop(semid, &buf, 1);
	return ret;
}

int sem_v(int semid)
{
	struct sembuf buf = {0, 1, 0};
	int ret = 0;
	ret = semop(semid, &buf, 1);
	return ret;
}


/*
int main()
{
	
	//IPC_CREAT and IPC_EXCL a
	int semid;
	semid  = sem_creat(0x1111);
	//sem_setval(semid, 1);
	//sem_getval(semid);
	
	
	int pid = 0;
	pid = fork();
	

	//sem_p(semid);
		int i=0;
	//	printf("i:%d pid:%d \n", i++, getpid());
	//	sleep(3);
	//	printf("i:%d pid:%d \n", i++, getpid());
		
	//sem_v(semid);
	
	
	
	return 0;
}
*/

