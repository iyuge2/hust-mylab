#include<stdio.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

#define M 10
#define _SPID 123456
#define _PVID 1234567

int main(int argc,char** argv)
{
    if(argc < 3){
        return 1;
    }
    pid_t readbuf,writebuf;
    int shmid = 0;//共享内存的标识符
    int semid = 0;//信号灯标识符
    char* S = NULL;//共享内存的首地址
    /*创建共享内存组--数组形式*/
    shmid = shmget(_SPID,M,IPC_CREAT|0666);
    S = (char*)shmat(shmid,NULL,SHM_R|SHM_W);
    /*创建两个信号灯
     * 信号灯0--代表缓冲区为空
     * 信号灯1--代表缓冲区为满
     */
	semid = semget(1234567,2,0666|IPC_CREAT);
    /*信号灯赋初值*/
    semctl(semid,0,SETVAL,M);//0号信号灯赋初值M
    semctl(semid,1,SETVAL,0);//1号信号灯赋初值0
    writebuf = fork(); /*创建写缓冲的进程*/
    if(writebuf == 0){
        char *const arg[] = {"write",argv[1],NULL};
        execv("./write",arg);//调用read
        exit(0);
    }
    else{
        readbuf = fork();/*创建读缓冲的进程*/
        if(readbuf == 0){
            char *const arg[] = {"read",argv[2],NULL};
            execv("./read",arg);//调用write
            exit(0);
        }
        else{
			waitpid(writebuf,NULL,0);
            waitpid(readbuf,NULL,0);
            /*删除信号灯*/
            semctl(semid,0,IPC_RMID);
			semctl(semid,1,IPC_RMID);
            shmctl(shmid,IPC_RMID,0);/*删除共享内存组*/
        }
    }
}
