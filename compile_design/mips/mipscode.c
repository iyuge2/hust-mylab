#include"mipscode.h"

void GetMipsCode()
{
    printf("开始生成目标代码...\n");
    fprintf(fmips,".data\n");
    fprintf(fmips,".global main\n");
    fprintf(fmips,".text\n");
    ;
    printf("...目标代码生成完毕\n");
}
