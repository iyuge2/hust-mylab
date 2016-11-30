#ifndef _SYNTAXTREE_H
#define _SYNTAXTREE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

#define I_MAXLENTH 32
extern int yylineno;
extern char* yytext;
extern FILE* fgramma;

/*抽象语法树的结点*/

typedef struct GrammaNode
{
    int currentLine; //行号
    char name[32];//语法单元的名字
    int tag;//1为变量，2为函数，3为常数,4为数组，5为结构体
    char content[32];//语法单元语义值(int i;i是一个ID，ID的content是‘i’)
    char *type;//语法单元数据类型:主要用于等号和操作符左右类型匹配判断
    union//共用体用来存放TYPE/INTEGER结点的值
    {
        int integer;
        float fnum;
    };
    struct GrammaNode *lchild;//左孩子
    struct GrammaNode *rchild;//右孩子
}GrammaNode;

GrammaNode* grammaTreeHead;
//用于记录上一个单词,以便确定当前标识符的类型
char preword[32];

/*变量符号表的结点*/
struct var
{
    char name[32];//变量名
    char type[10];//变量类型
    struct var *next;//指针
}*varhead,*vartail;

/*函数符号表的结点*/
struct func
{
    int tag;//0表示未定义，1表示定义
    char name[32];//函数名
    char type[10];//函数类型
    char rtype[10];//实际返回值类型
    int pnum;//形参数个数
    struct func *next;
}*funchead,*functail;
int rpnum;//记录函数实参个数

/*数组符号表的结点*/
struct array
{
    char name[32];//数组名
    char type[10];//数组类型
    struct array *next;
}*arrayhead,*arraytail;

/*结构体符号表的结点*/
struct struc
{
    char name[32];//结构体名
    char type[10];//数组类型
    struct struc *next;
}*struchead,*structail;

void yyerror(const char*s,...);
/*=====抽象语法树========================*/
/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
//struct ast *newast(char* name,int num,...);
GrammaNode* InsertNode(char* name,int num,...);


/*遍历抽象语法树，level为树的层数*/
//void eval(struct GrammaNode*,int level);
void eval(GrammaNode*,int level);

/*=====变量符号表========================*/
/*建立变量符号表*/
void newvar(int num,...);

/*查找变量是否已经定义,是返回1，否返回0*/
int  exitvar(struct GrammaNode*tp);

/*查找变量类型*/
char* typevar(struct GrammaNode*tp);

/*=================函数符号表==============*/
/*建立函数符号表,flag：1表示变量符号表，2表示函数符号表,num是参数个数*/
void newfunc(int num,...);

/*查找函数是否已经定义,是返回1，否返回0*/
int exitfunc(struct GrammaNode*tp);

/*查找函数类型*/
char* typefunc(struct GrammaNode*tp);

/*查找函数的形参个数*/
int pnumfunc(struct GrammaNode*tp);

/*=================数组符号表=<F3>=============*/
/*建立数组符号表*/
void newarray(int num,...);

/*查找数组是否已经定义,是返回1，否返回0*/
int exitarray(struct GrammaNode*tp);

/*查找数组类型*/
char* typearray(struct GrammaNode*tp);

/*=================结构体符号表==============*/
/*建立结构体符号表*/
void newstruc(int num,...);

/*查找结构体是否已经定义,是返回1，否返回0*/
int exitstruc(struct GrammaNode*tp);
#endif
