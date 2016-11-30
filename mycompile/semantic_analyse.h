#ifndef _SEMANTIC_ANALYSE_H
#define _SEMANTIC_ANALYSE_H
#include<stdio.h>
#include"syntaxTree.h"

#define I_MAXLENTH 32
#define STACK_SIZE 100  //作用域的最大深度
#define TABLE_MAX  0xff //符号表的容量

/*定义C--的类型系统*/
typedef struct Type_ Type;
typedef struct Type_* pType;
typedef struct FieldList_  FieldList;
typedef struct FieldList_* pFieldList;

struct Type_
{
    enum {BASIC,ARRAY,STRUCTURE}kind;
    union
    {
        //基本类型-int float
        int basic;
        //数组类型信息包括元素类型与数组大小构成
        struct {pType elem; int size;} array;
        //结构体类型信息是一个链表
        pFieldList structure;
    } u;
};

struct FieldList_
{
    char* name; //域的名字
    pType type; //域的类型
    pFieldList tail; //下一个域
};

/*定义C--的符号表*/
typedef struct SimbolTable STable;
typedef struct SimbolTable* pSTable;
typedef struct FunTable FTable;
typedef struct FunTable* pFTable;
typedef struct HushTable HTable;
typedef struct HushTable* pHTable;

struct SimbolTable
{//变量名符号表
    char name[I_MAXLENTH];//名字
    Type type; //类型
    union//共用体用来存放TYPE结点的值
    {
        int integer;
        float fnum;
    };
    pSTable tail; //下一个符号
};

struct FunTable
{//函数表
    char name[I_MAXLENTH];//函数名
    pType type; //函数返回类型
    pSTable parameter; //参数表
    pFTable tail; //下一个函数
};

struct HushTable{
    unsigned int hash; //hash值
    pSTable Sptr; //指向符号的指针
    pFTable Fptr; //指向函数符号的指针
};

/*符号表栈*/
typedef struct HStack Hstack;
typedef struct HStack* pHstack;

struct HStack{
    pHTable* base;
    pHTable* top;
    int size; //栈的实际大小
};

void semantic();//语义分析主函数
void push(pHTable ph);//符号表入栈函数
void pop(pHTable* ph);//符号表出栈函数
void CreatSimbolTable(GrammaNode *currentNode,int level);//符号表创建函数
void CreatSimbolTable(GrammaNode *currentNode);//先序遍历ExtDef子树
void evalGvar(GrammaNode *currentNode);//全局变量的定义
void InitHashTable(pHTable* pH);//初始化hash表
#endif
