#ifndef _SEMANTIC_ANALYSE_H
#define _SEMANTIC_ANALYSE_H
#include<stdio.h>
#include"../syntax/syntaxTree.h"

#define I_MAXLENTH 32
#define LATMAX 5 //允许数组的最大维数
#define TABLE_MAX  0xff //符号表的容量

extern FILE* fseman;
extern int SemanToggle;
extern int TransToggle;

/*定义C--的类型系统*/
typedef struct ExpType _ExpType;
typedef struct ExpType* _pExpType;
typedef struct Type _Type;
typedef struct Type* _pType;
typedef struct VarTable _VarTable;
typedef struct VarTable* _pVarTable;
typedef struct StructTable _StructTable;
typedef struct StructTable* _pStructTable;
typedef struct FuncTable _FuncTable;
typedef struct FuncTable* _pFuncTable;
typedef struct HashTable _HashTable;
typedef struct HashTable* _pHashTable;

struct ExpType{
    //当kind>=4->array 其中kind%16==4->int 5->float 维度=kind/16
    int kind; //1--int 2--float 3--struct
    char id[I_MAXLENTH];//struct类型名 kind==3时有效
};

union u{
    //基本类型1--int 2--float
    int basic;
    //数组类型
    struct{
        union u* elem;//类型
        int lat;//维数
        int size[LATMAX];//每一维的元素个数,0代表高维
    }array;
    //结构体类型
    char structId[I_MAXLENTH];
};

struct Type
{
    //1--BASIC,2--BASIC_ARRAY,3--STRUCTURE,4--STRUCT_ARRAY
    int kind;
    union u typeSys;
};

/*定义C--的符号表*/
struct VarTable{
    char id[I_MAXLENTH]; //名字
    int num; //编号,用于后面中间代码生成时生成名字,全局变量<0,局部变量>0
    _pType type; //域的类型
    _pVarTable next; //下一个域
};

struct StructTable{
    char structName[I_MAXLENTH];//结构体名字
    int memnum;//成员数量
    _pVarTable head;//结构体中的数据成员
    _pStructTable next;//指向下一个结构体
};

struct FuncTable{
    int defineTag; //设置一个标记位,用于判断函数是否定义 1--已定义
    int kind; //返回类型1--int 2--float 3--struct
    char backName[I_MAXLENTH];//返回类型为struct时有用
    char funName[I_MAXLENTH];//函数名
    _pVarTable paraHead; //行参链表
    _pVarTable localHead; //局部变量链表
    _pFuncTable next;
};

//hash表的定义
struct HashTable{
    int Hash; //hash值
    _pFuncTable funHead; //指向函数定义
    _pVarTable varHead; //指向变量定义
    _pStructTable structHead; //指向结构体定义
};

extern _pHashTable HashHead;//指向当前hash表

void semantic();//语义分析主函数
void InitHashTable(_HashTable pH);//初始化hash表
unsigned int hashcalc(char *name); //计算hash值
void CreatNewHashTable(); //初始化新的符号表
void DestoryHashTable(); //销毁栈顶的符号表
void CreatSimbolTable(GrammaNode *currentNode);//先序遍历抽象语法树

void FindVar(GrammaNode* currentNode,int op);//寻找当前子树下的变量
void FindStructVar(GrammaNode* currentNode);//寻找当前子树下的结构体定义
void FindFunc(GrammaNode* currentNode,int op);//寻找函数定义

int FindExpType(GrammaNode* currentNode);//寻找Exp的类型
_pExpType FuncBackType(char *id);//函数的返回类型
_pExpType StructBackType(char *sname,char *memName);//判断结构中数据成员的类型
_pExpType VarBackType(char *vname);//返回变量的类型

void GetLat(GrammaNode* currentNode);//获取数组的维度
void CheckExpType(GrammaNode* currentNode);//检测Exp
void CheckFuncDef(GrammaNode* currentNode);//检测函数未定义的使用
//void CheckExpArrayType(GrammaNode* currentNode);//检测Exp中的数组

void addVar(_pVarTable pv); //新增一个变量
int exitVar(char*); //判断一个变量是否存在
void CopyVar(_pVarTable pt,_pVarTable ps);//ps->pt
void addLocalVar(_pVarTable pv);//新增一个局部变量
int isEqualVar(_pVarTable pt,_pVarTable ps);//判断两个变量是否等价

void addStruct(_pStructTable ps);//新增一个结构体定义
void addStructVar(_pVarTable pv); //新增一个结构体变量
int exitStruct(char *id);//判断一个结构体是否存在
int isEqualStruct(char* id1,char* id2,int op);//判断两个结构是否内容等价

void GetRealPara(GrammaNode* currentNode);//获取实参列表
int ComparePara(char *id);//比较实参和形参
void addFunc(_pFuncTable pf);//新增一个函数定义
void addFuncPara(_pVarTable pv); //新增一个函数形参
int exitFunc(char *id);//判断一个函数是否存在

void PrintFunSimbol();//打印函数符号表
void PrintStructSimbol();//打印结构符号表
void PrintVarSimbol();//打印变量符号表
void PrintError(int op,int line,char *s);//打印错误
#endif
