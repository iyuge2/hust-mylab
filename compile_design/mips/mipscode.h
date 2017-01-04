#include<stdio.h>
#include<string.h>
#include"../translate/trans.h"

extern FILE* fmips;
extern _pMiddleCode CodeHead;

typedef struct regUse _regUse;
typedef struct regUse* _pregUse;
typedef struct VarInf _VarInf;
typedef struct VarInf* _pVarInf;

struct regUse{
    int regnum;//寄存器编号
    int use;//寄存器是否被占用0--否 1--是
};

struct VarInf{
    int type;//变量的种类 0--全局变量gv 1--局部变量v 2--临时变量t
    int num;//变量编号
    int addr;//变量的地址,对临时变量存放寄存器编号(-1->代表此临时变量还没有分配寄存器)
    _pVarInf next;
};

void GetMipsCode();//得到Mips指令代码
void MipsCode();//Mips指令代码

void CharSet(char*id1,char*id2);//将id2中的首字符去掉存入id1中
void InitReg();//初始化可用的寄存器
int SelectReg(int op);//选择寄存器
int GetVarType(char *s);//返回变量类型

_pVarInf InsertVarInf(int op,int num,int addr);//插入一个变量信息
void DelVarInf(int op,int num);//删除一个变量信息
int GetNum(char *s);//得到变量编号
_pVarInf findVarInf(char *s);//查找变量
void DelTempVarInf();//删除所有的临时变量
