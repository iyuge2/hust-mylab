#ifndef _TRANS_H
#define _TRANS_H
#include<stdio.h>
#include<stdlib.h>
#include"../syntax/syntaxTree.h"
#include"../semantic/semantic_analyse.h"

extern FILE* ftrans;
extern unsigned int hashcalc(char *name);
extern _pFuncTable currentFunc;

typedef struct LabelList _LabelList;
typedef struct LabelList* _pLabelList;

struct LabelList{//标签的链表域
    int labelNum[4];//if-else-if 最多需要存放的标签个数不超过3个
    int whileNum;//记录while前面那个标签号
    int lenth;//标签个数,不包括whileNum
    _pLabelList next;
};

void translate();//中间代码生成主函数
void GetMiddleCode(GrammaNode* currentNode);//遍历语法树,获得中间代码
void translate_gVar();//翻译所有的全局变量
void translate_param(_pFuncTable tFunc);//翻译函数形参
void translate_localVar(_pFuncTable tFunc);//翻译函数的局部变量
void translate_stmt(GrammaNode* currentNode);//翻译函数内的语句
void translate_exp(GrammaNode* currentNode);//翻译表达式
void translate_args(GrammaNode* currentNode);//翻译函数实参

int GetVarNum(char* id);//获得变量的编号
int GetVarSize(_pVarTable var);//获得变量的大小
int GetStructSize(char* structId);//获取结构体的大小

void AddLabel();//新增一个标签域
void DestoryLabel();//销毁一个标签域
void addALabel(int num);//增加一个标签元素
int deleteALabel();//删除第一个标签元素并返回
#endif
