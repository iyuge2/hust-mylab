#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/sem.h>

//P,V操作函数原型定义
void P(int semid,int index);
void V(int semid,int index);

//初始化信号量
int sem_init();
//删除信号量
void sem_del();

//信号灯句柄定义
int semid;
//线程句柄定义
pthread_t p1,p2;

//线程执行函数定义
void* subp1();
void* subp2();

int share = 0;
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

