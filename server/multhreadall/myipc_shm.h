
#ifndef _WBM_MY_SHM_H_
#define _WBM_MY_SHM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus 
extern "C" {
#endif

int IPC_CreatShm(char *shmseedfile, int shmsize, int *shmhdl);

int IPC_MapShm(int shmhdl,void **mapaddr);

int IPC_UnMapShm(void *unmapaddr);

int IPC_DelShm(int shmhdl);


#ifdef __cplusplus
}
#endif
#endif


