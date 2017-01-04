#include"pv.h"

int main()
{
    int mykey = 1234;/*信号量标识码*/
    /*创建两个信号量
     * 0--代表计算
     * 1--代表打印
     * */
    semid=semget((key_t)mykey,2,IPC_CREAT|0666);
    if(semid==-1){
        return -1;
    }
    /*对信号量赋初始值*/
    semctl(semid,0,SETVAL,1);
    semctl(semid,1,SETVAL,0);
    //if(sem_init() == 0){//初始化信号量
    //    printf("init error!\n");
    //}
    /*创建两个线程,线程1执行计算函数,线程2执行打印输出函数*/
    if((pthread_create(&p1,NULL,(void*)subp1,NULL))!=0){
        return -1;
    }
    if((pthread_create(&p2,NULL,(void*)subp2,NULL))!=0){
        return -1;
    }
    /*等待两个线程运行结束*/
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    /*删除两个信号灯*/
    semctl(semid,0,IPC_RMID);
    semctl(semid,1,IPC_RMID);
    return 0;
}

//执行计算功能
void* subp1()
{
    int i = 0;
    for(i = 1; i <= 100 ;++i){
        P(semid,0);/*检测是否可以计算*/
        share += i;
        V(semid,1);
    }
    pthread_exit(0);/*0代表正常退出*/
}

//执行打印功能
void* subp2()
{
    int i = 0;
    int j = 0;
    for(i = 0;i < 100;++i){
        P(semid,1);/*检测是否可以进行打印*/
        printf("%4d ",share);
        j++;
        if(j == 10){/*每打印十个数,换行*/
            printf("\n");
            j = 0;
        }
        V(semid,0);
    }
    pthread_exit(0);/*0代表正常退出*/
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
