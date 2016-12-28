#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include"pv.c"

#define _SPID 123456
#define _PVID 1234567
#define M 10

int main(int argc,char** argv)
{
    int shmid = shmget(_SPID,M,IPC_CREAT|0666);
    char* S = (char*)shmat(shmid,NULL,SHM_R|SHM_W);
	int semid = semget(_PVID,2,0666|IPC_CREAT);
    int in = 0;
    FILE *fd = fopen(argv[1],"r");
    while(!feof(fd)){
        P(semid,0);
        S[in] = fgetc(fd);
        in = (in + 1) % M;
        V(semid,1);
    }
    fclose(fd);
    semctl(semid,0,IPC_RMID);
    semctl(semid,1,IPC_RMID);
    shmctl(shmid,IPC_RMID,0);/*删除共享内存组*/
    return 0;
}
