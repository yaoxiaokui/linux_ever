/*************************************************************************
	> File Name: shm.c
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Jun 2016 09:45:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

const int BUFFER_SIZE = 1024;

void shm_print_info(int shmid)
{
    struct shmid_ds shm_info;

    int ret = shmctl(shmid, IPC_STAT, &shm_info);
    if(ret != 0){
        printf("shmctl error\n");
    }
    else{
        printf("----------------------------------------\n");
        printf("共享内存的大小:%d\n", shm_info.shm_segsz);
        printf("共享内存的创建进程的PID:%d\n", shm_info.shm_cpid);
        printf("共享内存的最后一次执行shmat或shmdt的进程的PID:%d\n", shm_info.shm_lpid);

        printf("----------------------------------------\n");
    }
}

int main(int argc, char *argv[])
{
    //创建共享内存
    int shmid = shmget(0x1234, BUFFER_SIZE, 0666 | IPC_CREAT | IPC_EXCL);
    if(shmid < 0){
        if(errno == EEXIST)//如果共享内存已经存在，则打开
            shmid = shmget(0x1234, 0, 0666);
        else{
            printf("shmget error\n");
            return -1;
        }
    }

    printf("当前进程的PID = %d\n", getpid());
    printf("shmid = %d\n", shmid);
    shm_print_info(shmid);

    //连接共享内存
    char * shmaddr = (char*)shmat(shmid, NULL, 0);
    if(shmaddr == (void*)-1){
        printf("shmat error\n");
        return -1;
    }

    //向共享内存中写入值
    strcpy(shmaddr, "Shared memory.");

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    //将共享内存中的数据拷贝到buffer中
    strcpy(buffer, shmaddr);
    printf("buffer = %s\n", buffer);

    //打印此时共享内存结构体内容
    shm_print_info(shmid);

    sleep(3);

    //脱离共享内存
    shmdt(shmaddr);

    //删除共享内存
    //shmctl(shmid, IPC_RMID, NULL);

    return 0;
}


