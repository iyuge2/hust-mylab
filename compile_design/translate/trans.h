#ifndef _TRANS_H
#define _TRANS_H
#include<stdio.h>
#include<stdlib.h>
#include"../syntax/syntaxTree.h"
#include"../semantic/semantic_analyse.h"

#define LATMAX 5
#define IDLENTH 8

extern FILE* ftrans;
extern unsigned int hashcalc(char *name);
extern _pFuncTable currentFunc;

typedef struct LabelList _LabelList;
typedef struct LabelList* _pLabelList;
typedef struct ArrayLat _ArrayLat;
typedef struct ArrayLat* _pArrayLat;
typedef struct MiddleCode _MiddleCode;
typedef struct MiddleCode* _pMiddleCode;

struct LabelList{//标签的链表域
    int labelNum[4];//if-else-if 最多需要存放的标签个数不超过3个
    int whileNum;//记录while前面那个标签号
    int lenth;//标签个数,不包括whileNum
    _pLabelList next;
};

struct ArrayLat{
    int lat;//维度
    int size[LATMAX];//每维的大小
};

struct MiddleCode{//记录四元组--eg: (+ C D T1)
    int kind;
/*判断语句类型 0-:= 1-:= + 2-IF 3-DEC 4--PARAM 5-RETURN
 * 6--FUNCTION 7--换行 8--GOTO 9--LABEL 10-取负 11-CALL 12-ARG*/
    char op;//+
    char id1[IDLENTH];//C
    char id2[IDLENTH];//D
    char res[IDLENTH];//T1
    _pMiddleCode next;//指向下一个四元组
};
/*中间代码生成主函数*/
void translate();
/*遍历语法树,获得中间代码*/
void GetMiddleCode(GrammaNode* currentNode);
/*在四元组链中加入一个四元组*/
void AddACode();
/*输出四元组*/
void PrintCode();
/*翻译所有的全局变量*/
void translate_gVar();
/*翻译函数形参*/
void translate_param(_pFuncTable tFunc);
/*翻译函数的局部变量*/
void translate_localVar(_pFuncTable tFunc);
/*翻译函数内的语句*/
void translate_stmt(GrammaNode* currentNode);
/*翻译表达式*/
void translate_exp(GrammaNode* currentNode);
/*翻译函数实参*/
void translate_args(GrammaNode* currentNode);
/*获得变量的编号*/
int GetVarNum(char* id);
/*获得变量的大小*/
int GetVarSize(_pVarTable var);
/*获取结构体的大小*/
int GetStructSize(char* structId);
/*计算并返回数组的大小*/
int GetArrayAddr(GrammaNode* currentNode);
/*计算并返回结构成员的地址*/
int GetStructAddr(char *sname,char *mname);
/*新增一个标签域*/
void AddLabel();
/*销毁一个标签域*/
void DestoryLabel();
/*增加一个标签元素*/
void addALabel(int num);
/*删除第一个标签元素并返回*/
int deleteALabel();
#endif
