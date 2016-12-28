#include<stdio.h>
#include<string.h>
#include"../translate/trans.h"

extern FILE* fmips;
extern _pMiddleCode CodeHead;

void GetMipsCode();//得到Mips指令代码
void MipsCode();//Mips指令代码

void CharSet(char*id1,char*id2);//将id2中的首字符去掉存入id1中
