#ifndef _OOSTK_H
#define _OOSTK_H
#include<iostream>

using namespace std;

class OOSTK{
    int *const elems; //申请内存用于存放栈的元素
    const int max; //栈能够存放的最大元素个数
    int pos; //栈实际已有元素个数
public:
    OOSTK(int m);//初始化栈，最多m个元素
    OOSTK(const OOSTK& s);//深拷贝s
    int size()const;//返回max
    int howMany()const;//返回pos
    int getelem(int x)const;//取下标x处的栈元素
    OOSTK& push(int e);//将e压栈
    OOSTK& pop(int &e);//出栈到e
    OOSTK& assign(const OOSTK& s);//赋s给栈
    void print()const;//打印栈
    ~OOSTK(); //销毁栈
};
#endif
