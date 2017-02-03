#ifndef _QUE2S_H
#define _QUE2S_H
#include<iostream>
#include"STACK.h"

using namespace std;

class QUE2S{
    STACK s1,s2;//栈s1,s2
public:
    QUE2S(int m):s1(m),s2(m){}; //初始化队列:每栈最多 m 个元素
    QUE2S(const QUE2S &q):s1(q.s1),s2(q.s2){}; //用队列 q 拷贝构造新队列
    operator int()const; //返回队列的实际元素个数
    QUE2S& operator<<(int e); //将 e 入队列,并返回当前队列
    QUE2S& operator>>(int &e); //出队列到 e,并返回当前队列
    QUE2S& operator=(const QUE2S &q);//赋 q 给当前队列并返回该队列
    void print( )const; //打印队列
    ~QUE2S(){}; //销毁队列
};
#endif
