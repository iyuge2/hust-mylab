#ifndef _STACK_H
#define _STACK_H
#include<iostream>

using namespace std;

class STACK{
    int *const elems; //申请内存用于存放栈的元素
    const int max; //栈能够存放的最大元素个数
    int pos; //栈实际已有元素个数
public:
    STACK(int m);//初始化栈，最多m个元素
    STACK(const STACK& s);//深拷贝s
    virtual int size()const;//返回max
    virtual operator int()const;//返回pos
    virtual int operator[](int x)const;//取下标x处的栈元素
    virtual STACK& operator<<(int e);//将e压栈
    virtual STACK& operator>>(int &e);//出栈到e
    virtual STACK& operator=(const STACK& s);//赋s给栈
    virtual void print()const;//打印栈
    virtual ~STACK(); //销毁栈
};
#endif

STACK(int m)
{
    int i = 0;
}
