/*
 * Author: iyuge2
 * Creat-time: 2016/11/03 16:10
 * Update-time:
 * Function: 项目主函数文件,包括命令行参数的使用，文件打开和关闭以及功能函数调用
 */
#include"main.h"

int main(int argc,char** argv)
{
    int i = 0;
    varhead=(struct var*)malloc(sizeof(struct var));//变量符号表头指针
    vartail=varhead;//变量符号表尾指针

    funchead=(struct func*)malloc(sizeof(struct func));//函数符号表头指针
    functail=(struct func*)malloc(sizeof(struct func));//函数符号表头指针
    funchead->next=functail;//函数符号表尾指针
    functail->pnum=0;
    arrayhead=(struct array*)malloc(sizeof(struct array));//数组符号表头指针
    arraytail=arrayhead;

    struchead=(struct struc*)malloc(sizeof(struct struc));//结构体符号表头指针
    structail=struchead;//结构体符号表尾指针

    if(argc < 2){
        printf("please input filename\n");
        return 1;
    }
    if(!(fd = fopen(argv[1],"r"))){
        printf("can't open %s file\n",argv[1]);
        return 1;
    }
    for(i = 2;i < argc-1;++i){
        if(!strcmp(argv[i],"-W")){//判断是否打印词法分析结果
            WordToggle = 1;
            fword = fopen(argv[i+1],"w");
        }
        if(!strcmp(argv[i],"-G")){//判断是否打印语法树
            GrammaToggle = 1;
            fgramma = fopen(argv[i+1],"w");
        }
    }
    yyrestart(fd);
//    yydebug = 1;
    yyparse();
    fclose(fd);
    if(WordToggle){
        fclose(fword);
    }
    if(GrammaToggle){
        fclose(fgramma);
    }
    return 0;
}
