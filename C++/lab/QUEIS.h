#ifndef _QUEIS_H
#define _QUEIS_H
#include<iostream>
#include"STACK.h"

using namespace std;

class QUEIS:public STACK{
    STACK s;//s作为构成队列的第二个队列
public:
    QUEIS(int m):s(m),STACK(m){}; //初始化队列:每栈最多 m 个元素
    QUEIS(const QUEIS &q):s(q.s),STACK(q){}; //用队列 q 拷贝构造新队列
    virtual operator int()const; //返回队列的实际元素个数
    virtual QUEIS& operator<<(int e); //将 e 入队列,并返回当前队列
    virtual QUEIS& operator>>(int &e); //出队列到 e,并返回当前队列
    virtual QUEIS& operator=(const QUEIS &q);//赋 q 给当前队列并返回该队列
    virtual void print( )const; //打印队列
    virtual ~QUEIS(){}; //销毁队列
};
#endif
