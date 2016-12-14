/*
 * Author: iyuge2
 * Creat-time: 2016/11/03 16:05
 * Update-time:
 * Function: 项目主函数的头文件
 * */
#ifndef _MAIN_H
#define _MAIN_H

#include<stdio.h>
#include<stdlib.h>

extern void yyrestart(FILE*);
extern int yyparse(void);
extern void semantic();
extern void translate();
//extern int yydebug;
int WordToggle = 0;
int GrammaToggle = 0;
int SemanToggle = 0;
int TransToggle = 1;

const char *translateName = "translate.txt";
FILE *fd=NULL,*fword=NULL,\
     *fgramma=NULL,*fseman=NULL,\
     *ftrans=NULL;

#endif
