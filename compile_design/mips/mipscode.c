#include"mipscode.h"

void GetMipsCode()
{
    printf("开始生成目标代码...\n");
    fprintf(fmips,".data\n");
    fprintf(fmips,".globl main\n");
    fprintf(fmips,".text\n");
    MipsCode();
    printf("...目标代码生成完毕\n");
}

void MipsCode()
{
    char t[10];
    _pMiddleCode tempCode = CodeHead;
    while(tempCode){
        switch(tempCode->kind){
            case 0:
                if(tempCode->id2[0] == '#'){//x := #k
                    CharSet(t,tempCode->id2);
                    fprintf(fmips,"  li $4,%s\n",t);
                }
                else{//x := y
                    fprintf(fmips,"  move $4,$5\n");
                }
                break;
            case 1:
            case 10://x := #0 - y
                if(tempCode->id2[0] == '#'){
                    CharSet(t,tempCode->id2);
                    fprintf(fmips,"  li $6,%s\n",t);
                }
                if(tempCode->id1[0] == '#'){
                    CharSet(t,tempCode->id1);
                    fprintf(fmips,"  li $5,%s\n",t);
                }
                switch(tempCode->op){
                    case '+':
                        fprintf(fmips,"  addi $4,$5,$6\n");
                        break;
                    case '-':
                        fprintf(fmips,"  addi $4,$5,$6\n");
                        break;
                    case '*':
                        fprintf(fmips,"  mul $4,$5,$6\n");
                        break;
                    case '/':
                        fprintf(fmips,"  div $5,$6\n");
                        fprintf(fmips,"  mflo $4\n");
                }
                break;
            case 2:
                switch(tempCode->id1[0]){
                    case '1'://>
                        fprintf(fmips,"  bgt $4,$5,%s\n",tempCode->id2);
                        break;
                    case '2'://<
                        fprintf(fmips,"  blt $4,$5,%s\n",tempCode->id2);
                        break;
                    case '3'://>=
                        fprintf(fmips,"  bge $4,$5,%s\n",tempCode->id2);
                        break;
                    case '4'://<=
                        fprintf(fmips,"  ble $4,$5,%s\n",tempCode->id2);
                        break;
                    case '5'://==
                        fprintf(fmips,"  beq $4,$5,%s\n",tempCode->id2);
                        break;
                    case '6'://!=
                        fprintf(fmips,"  bne $4,$5,%s\n",tempCode->id2);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                //fprintf(fmips,"  DEC %s %s\n",tempCode->id1,tempCode->id2);
                break;
            case 4:
                //fprintf(fmips,"  PARAM %s %s\n",tempCode->id1,tempCode->id2);
                break;
            case 5:
                if(tempCode->id1[0] == '#'){
                    CharSet(t,tempCode->id1);
                    fprintf(fmips,"  li $4,%s\n",t);
                }
                fprintf(fmips,"  move $v0,$4\n");
                break;
            case 6://Function
                fprintf(fmips,"%s:\n",tempCode->id1);
                break;
            case 7:
                fprintf(fmips,"\n");
                break;
            case 8://GOTO
                fprintf(fmips,"  j %s\n",tempCode->id1);
                break;
            case 9://LABEL
                fprintf(fmips,"%s:\n",tempCode->id1);
                break;
            case 11://CALL
                fprintf(fmips,"  jal %s\n",tempCode->id2);
                fprintf(fmips,"  move $4,$v0\n");
                break;
            case 12://ARG
                //fprintf(fmips,"  ARG %s\n",tempCode->id1);
                break;
            default:
                fprintf(fmips,"error!\n");
                break;
        }
        tempCode = tempCode->next;
    }
}

/*id2的首字符去掉存入id1中*/
void CharSet(char*id1,char*id2)
{
    int lenth = strlen(id2),i = 0;
    for(i = 1;i <= lenth;++i){
        id1[i-1] = id2[i];
    }
}
