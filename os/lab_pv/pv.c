#include"pv.h"

int main()
{
    int mykey = 1234;
    semid=semget((key_t)mykey,2,IPC_CREAT|0666);
    if(semid==-1){
        return -1;
    }
    if(sem_init() == 0){//初始化信号量
        printf("init error!\n");
    }
    if((pthread_create(&p1,NULL,(void*)subp1,NULL))!=0){
        return -1;
    }
    if((pthread_create(&p2,NULL,(void*)subp2,NULL))!=0){
        return -1;
    }
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    sem_del();//删除信号灯
}

//执行计算功能
void* subp1()
{
    int i = 0;
    for(i = 1; i <= 100 ;++i){
        P(semid,0);
        share += i;
        V(semid,1);
    }
    pthread_exit(0);
}

//执行打印功能
void* subp2()
{
    int i = 0;
    int j = 0;
    for(i = 0;i < 100;++i){
        P(semid,1);
        printf("%d ",share);
        j++;
        if(j == 10){
            printf("\n");
            j = 0;
        }
        V(semid,0);
    }
    pthread_exit(0);
}

void P(int semid,int index)
{
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = -1;
    sem.sem_flg = 0; //0/IPC_NOWAIT等
    semop(semid,&sem,1);//1--执行命令的个数
}

void V(int semid,int index)
{
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = 1;
    sem.sem_flg = 0; //0/IPC_NOWAIT等
    semop(semid,&sem,1);//1--执行命令的个数
}

int sem_init()
{
    union semun sem_union;
    unsigned short a[2] = {1,0};
    sem_union.array = a;
    if(semctl(semid,1,SETALL,sem_union) == -1)
        return 0;
    else
        return 1;
}

void sem_del()
{
    if(semctl(semid,1,IPC_RMID) == -1){
        printf("del error!\n");
    }
}
