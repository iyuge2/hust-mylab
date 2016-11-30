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
    int rulenum;//记录非终结符用的是第几条归约规则
    //1--int 2--float 3--struct
    int type;
    char name[15];//语法单元的名字
    union//共用体用来存放ID/TYPE/INTEGER结点的值
    {
        char idType[I_MAXLENTH];
        //>,<,>=,<=,==,!=//1-6
        int relop;
        int integer;
        float fnum;
    };
    struct GrammaNode *lchild;//左孩子
    struct GrammaNode *rchild;//右孩子
}GrammaNode;

GrammaNode* grammaTreeHead;

void yyerror(const char*s,...);
GrammaNode* InsertNode(char* name,int num,...);
void eval(GrammaNode*,int level);

#endif
