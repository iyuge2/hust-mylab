#ifndef _POSTK
#define _POSTK
#include<stdio.h>
#include<stdlib.h>
struct POSTk{
    int *elems;//申请内存存放数据
    int max;
    int pos;
};

void initPOSTK(POSTk *const p,int m);//初始化栈
void initPOSTK_s(POSTk *const p,const POSTk *s);//用栈s初始化栈p
int size(const POSTk *const p);//返回p所指向的栈的元素的max
int howMany(const POSTk *const p);//返回p所指向的栈的实际元素个数
int getelem(const POSTk* const p,int x);//取下标x处的元素
POSTk *const push(POSTk *const p,int e);//将值e压栈
POSTk *const pop(POSTk *const p,int *e);//将出栈值赋给e
POSTk *const assign(POSTk *const p,const POSTk *s);//赋s给p所指向的栈,返回p值
void print(const POSTk *const p);//打印p所指向的栈
void destroyPostk(POSTk *const p);//销毁p所指向的栈

#endif
