
#define	_OS_LINUX_

#if defined _OS_LINUX_
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <memory.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include "myipc_shm.h" 

#endif

int shmflag = 0;
int shmkey;

/***********************************************************************
  ����������    ���������ڴ�
  ����˵����    shmname  [in]  �ǹ����ڴ���,ϵͳ��Ψһ��־
                shmsize  [in]  ��Ҫ�����Ĺ����ڴ�Ĵ�С��
                shmhdl   [out] �����ڴ�ľ��.
  ����ֵ��      ����0����ִ�гɹ�����0���ش�����
************************************************************************/
int IPC_CreatShm(char *shmseedfile, int shmsize, int *shmhdl)
{
    if(shmflag == 0)			//�жϽӿ��й����ڴ�key�Ƿ��Ѿ�����
    {
    	shmkey = ftok(shmseedfile, 'c');
    	if (shmkey == -1)
    	{
    		perror("ftok");
    		return -1;
    	}
    	    
    	shmflag = 1;
    }
    
    //���������ڴ�
    *shmhdl = shmget(shmkey,shmsize,IPC_CREAT|0666);
    if (*shmhdl == -1)			//����ʧ��
		return -2;
	return 0;

}
/***********************************************************************
  ����������    ���������ڴ�
  ����˵����    shmhdl	[in]  ����ľ��
                mapaddr [out] �����ڴ��׵�ַ
  ����ֵ��      ����0����ִ�гɹ�����0���ش�����
************************************************************************/
int
IPC_MapShm(int  shmhdl, void  **mapaddr)
{
    void *tempptr = NULL;

    //���ӹ����ڴ�
    tempptr = (void *)shmat(shmhdl,0,SHM_RND);
    if ((int)tempptr == -1)		//�����ڴ�����ʧ��
		return -1;
    *mapaddr = tempptr;			//���������ڴ���ָ��

    return 0;
}
/***********************************************************************
  ����������    ȡ�������ڴ����
  ����˵����    unmapaddr   [in] �����ڴ��׵�ַ
  ����ֵ��      ����0����ִ�гɹ�����0���ش�����
************************************************************************/
int IPC_UnMapShm(void *unmapaddr)
{
    int  rv;
    //ȡ�����ӹ����ڴ� 
    rv = shmdt((char *)unmapaddr);
    if (rv == -1)			//ȡ������ʧ��
		return -1;

    return 0;
}
/***********************************************************************
  ����������    ɾ�������ڴ�
  ����˵����    shmhdl	[in]  ����ľ��
  ����ֵ��      ����0����ִ�гɹ�����0���ش�����
************************************************************************/
int IPC_DelShm(int shmhdl)
{
    int  rv;
    //ɾ�������ڴ�
    rv = shmctl(shmhdl,IPC_RMID,NULL);
    if(rv < 0)				//ɾ�������ڴ�ʧ��
		return -1;
    return 0;
}
