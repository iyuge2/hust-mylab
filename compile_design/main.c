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
        if(!strcmp(argv[i],"-S")){//判断是否打印语法树
            SemanToggle = 1;
            fseman = fopen(argv[i+1],"w");
        }
    }
    yyrestart(fd);
//    yydebug = 1;
    yyparse();//进行语法分析
    semantic();//进行语义分析
    if(TransToggle){
        if(!(ftrans = fopen(translateName,"w"))){
            exit(1);
        }
        translate();//进行中间语言制导翻译
    }
    fclose(fd);
    if(WordToggle){
        fclose(fword);
    }
    if(GrammaToggle){
        fclose(fgramma);
    }
    if(SemanToggle){
        fclose(fseman);
    }
    if(TransToggle){
        fclose(ftrans);
    }
    return 0;
}
