#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/sem.h>

/*P,V操作函数*/
void P(int semid,int index);
void V(int semid,int index);

int semid; /*信号灯句柄*/
pthread_t p1,p2; /*线程句柄*/
void* subp1(); /*计算*/
void* subp2(); /*打印*/
int share = 0; /*共享变量*/
