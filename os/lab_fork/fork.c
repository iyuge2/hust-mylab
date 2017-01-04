#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>

void myfunc1();
void myfunc2();

void handleParent();//父进程信号处理函数
void handle1();//子进程1信号处理函数
void handle2();//子进程2信号处理函数

int pipefd[2];//管道读写
pid_t p1,p2;//子进程标识符
int status = -1;//设置进程退出码

int main()
{
    pipe(pipefd);//pipefd[0]用于读,pipefd[1]用于写
    signal(SIGINT,handleParent);
    p1 = fork();//创建子进程1
    if(p1 == 0){
        close(pipefd[0]);//关闭子进程1的读的通道
        myfunc1();
    }
    else{
        p2 = fork();//创建子进程2
        if(p2 == 0){
            close(pipefd[1]);//关闭子进程2的写通道
            myfunc2();
        }
        else{
            wait(&status);//等待子进程1退出
            wait(&status);//等待子进程2退出
        }
    }
    //关闭父进程的读写描述符
    close(pipefd[0]);
    close(pipefd[1]);
    printf("\nParent Process is Killed.");
    return 0;
}

void myfunc1()
{
    int i = 1;//计数器
    signal(SIGINT,SIG_IGN);//忽略信号SIGINT
    signal(SIGUSR1,handle1);//设置接收信号SIGUSR1
    while(1){
        write(pipefd[1],&i,sizeof(int));//往管道中写内容
        i++;//计数器加1
        sleep(1);
    }
}

void myfunc2()
{
    int m;//用于接收管道中的值
    signal(SIGINT,SIG_IGN);//忽略信号SIGINT
    signal(SIGUSR2,handle2);//设置接收信号SIGUSR1
    while(1){
        read(pipefd[0],&m,sizeof(int));//往管道中读内容
        printf("I send you %d times\n",m);
    }
}

void handleParent()
{
    kill(p1,SIGUSR1);//发送信号SIGUSR1给进程p1
    kill(p2,SIGUSR2);//发送信号SIGUSR2给进程p2
}

void handle1()
{
    close(pipefd[1]);
    printf("\nChild Process 1 is Killed by Parent!");
    exit(0);//0代表正常退出
}

void handle2()
{
    close(pipefd[0]);
    printf("\nChild Process 2 is Killed by Parent!");
    exit(0);
}
