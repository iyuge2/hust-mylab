#include"mipscode.h"

#define M 24/*自己分配的寄存器个数,只使用2-15号寄存器*/

_pregUse R = NULL;
_pVarInf vHead = NULL;//变量信息的头指针

void GetMipsCode()
{
    printf("开始生成目标代码...\n");
    //InitReg();//初始化可用的寄存器
    //MipsCode();//生成目标代码
    printf("...目标代码生成完毕\n");
}

void MipsCode()
{
    char t[10];
    int size = 0,presize = 0;
    int t1 = 0,t2 = 0,t3 = 0;
    int tc = 0,tn = 0;
    _pVarInf tp1 = NULL,tp2 = NULL,tp3 = NULL;
    _pMiddleCode tempCode = CodeHead;
    while(tempCode){
        tc = GetVarType(tempCode->res);
        tn = GetNum(tempCode->res);
        if(tc != -1){
            tp1 = findVarInf(tempCode->res);
            if(tp1 && tp1->type == 1){//局部变量
                t1 = SelectReg(0);
            }
            else if(tc == 2){//临时变量
                if(tp1){
                    t1 = tp1->addr;
                }
                else{
                    t1 = SelectReg(tn);
                    tp1 = InsertVarInf(2,tn,t1);
                }
            }
        }
        tc = GetVarType(tempCode->id1);
        tn = GetNum(tempCode->id1);
        if(tc != -1){
            tp2 = findVarInf(tempCode->id1);
            if(tp2 && tp2->type == 1){//局部变量
                t2 = SelectReg(0);
            }
            else if(tc == 2){//临时变量
                if(tp2){
                    t2 = tp2->addr;
                }
                else{
                    t2 = SelectReg(tn);
                    tp2 = InsertVarInf(2,tn,t2);
                }
            }
        }
        tc = GetVarType(tempCode->id2);
        tn = GetNum(tempCode->id2);
        if(tc != -1){
            tp3 = findVarInf(tempCode->id2);
            if(tp3 && tp3->type == 1){//局部变量
                t3 = SelectReg(0);
            }
            else if(tc == 2){//临时变量
                if(tp3){
                    t3 = tp3->addr;
                }
                else{
                    t3 = SelectReg(tn);
                    tp3 = InsertVarInf(2,tn,t3);
                }
            }
        }
        switch(tempCode->kind){
            case 0://x := #k
                if(tempCode->id2[0] == '#'){
                    CharSet(t,tempCode->id2);
                    fprintf(fmips,"  li $%d,%s\n",t3,t);
                    R[t3-2].use = 0;//立即数分配到的寄存器直接解除占用
                    if(tp2->type == 1){//局部变量
                        fprintf(fmips,"  addi $sp,$fp,-%d\n",tp2->addr);
                        fprintf(fmips,"  sw $%d,$sp\n",t3);
                    }
                    else if(tp2->type == 0){
                        fprintf(fmips,"  addi $gp,%d\n",tp2->addr);
                        fprintf(fmips,"  sw $%d,$gp\n",t2);
                    }
                }
                else{//x := y
                    if(tp3->type == 1){//局部变量
                        fprintf(fmips,"  addi $sp,$fp,-%d\n",tp3->addr);
                        fprintf(fmips,"  lw $%d,$sp\n",t3);
                    }
                    fprintf(fmips,"  or $%d,$%d\n",t2,t3);
                    if(tp2->type == 1){
                        fprintf(fmips,"  addi $sp,$fp,-%d\n",tp2->addr);
                        fprintf(fmips,"  sw $%d,$sp\n",t2);
                    }
                }
                if(tp2->type != 2){
                    DelTempVarInf();
                }
                break;
            case 1://x := y + #k x := y + z
            case 10://x := #0 - y
                if(tp1->type == 1){//局部变量
                    fprintf(fmips,"  addi $sp,$fp,-%d\n",tp2->addr);
                    fprintf(fmips,"  lw $%d,$sp\n",t1);
                }
                if(tp2->type == 1){//局部变量
                    fprintf(fmips,"  addi $sp,$fp,-%d\n",tp2->addr);
                    fprintf(fmips,"  lw $%d,$sp\n",t2);
                }
                if(tp3->type == 1){//局部变量
                    fprintf(fmips,"  addi $sp,$fp,-%d\n",tp3->addr);
                    fprintf(fmips,"  lw $%d,$sp\n",t3);
                }
                if(tempCode->id2[0] == '#'){
                    t3 = SelectReg(0);
                    CharSet(t,tempCode->id2);
                    fprintf(fmips,"  li $%d,%s\n",t3,t);
                    R[t3-2].use = 0;
                }
                if(tempCode->id1[0] == '#'){
                    t2 = SelectReg(0);
                    CharSet(t,tempCode->id1);
                    fprintf(fmips,"  li $%d,%s\n",t2,t);
                    R[t2-2].use = 0;
                }
                switch(tempCode->op){
                    case '+':
                        fprintf(fmips,"  add $%d,$%d,$%d\n",t1,t2,t3);
                        break;
                    case '-':
                        fprintf(fmips,"  sub $%d,$%d,$%d\n",t1,t2,t3);
                        break;
                    case '*':
                        fprintf(fmips,"  mul $%d,$%d,$%d\n",t1,t2,t3);
                        break;
                    case '/':
                        fprintf(fmips,"  div $%d,$%d\n",t2,t3);
                        fprintf(fmips,"  mflo $%d\n",t1);
                }
                break;
            case 2://IF
                switch(tempCode->id1[0]){
                    case '1'://>
                        fprintf(fmips,"  bgt $%d,$%d,%s\n",t2,t3,tempCode->id2);
                        break;
                    case '2'://<
                        fprintf(fmips,"  blt $%d,$%d,%s\n",t2,t3,tempCode->id2);
                        break;
                    case '3'://>=
                        fprintf(fmips,"  bge $%d,$%d,%s\n",t2,t3,tempCode->id2);
                        break;
                    case '4'://<=
                        fprintf(fmips,"  ble $%d,$%d,%s\n",t2,t3,tempCode->id2);
                        break;
                    case '5'://==
                        fprintf(fmips,"  beq $%d,$%d,%s\n",t2,t3,tempCode->id2);
                        break;
                    case '6'://!=
                        fprintf(fmips,"  bne $%d,$%d,%s\n",t2,t3,tempCode->id2);
                        break;
                    default:
                        break;
                }
                break;
            case 3://DEC
            case 4://PARAM
                //fprintf(fmips,"  DEC %s %s\n",tempCode->id1,tempCode->id2);
                presize = size;
                size += atoi(tempCode->id2);
                if(GetVarType(tempCode->id1) == 0){
                    if(tempCode->next && tempCode->next->kind != 3){
                        fprintf(fmips,".data\n");
                        fprintf(fmips,".space %d\n",size);
                        fprintf(fmips,".globl main\n");
                        fprintf(fmips,".text\n");
                        size = 0;
                    }
                    InsertVarInf(0,GetNum(tempCode->id1),presize);
                }
                else{
                    InsertVarInf(1,GetNum(tempCode->id1),presize);
                    if(tempCode->next && ((tempCode->next->kind != 3) && (tempCode->next->kind != 4))){
                        fprintf(fmips,"  or $fp,$sp,$0\n");
                        fprintf(fmips,"  addi $sp,$sp,-%d\n",size);
                        size = 0;
                    }
                }
                break;
                //fprintf(fmips,"  PARAM %s %s\n",tempCode->id1,tempCode->id2);
            case 5://RETURN
                if(tempCode->id1[0] == '#'){
                    CharSet(t,tempCode->id1);
                    fprintf(fmips,"  li $%d,%s\n",t2,t);
                }
                fprintf(fmips,"  move $v0,$%d\n",t2);
                fprintf(fmips,"  jr $ra\n");
                break;
            case 6://Function
                fprintf(fmips,"%s:\n",tempCode->id1);
                break;
            case 7://换行
                fprintf(fmips,"\n");
                break;
            case 8://GOTO
                fprintf(fmips,"  j %s\n",tempCode->id1);
                break;
            case 9://LABEL
                fprintf(fmips,"%s:\n",tempCode->id1);
                break;
            case 11://CALL
                fprintf(fmips,"  sw $ra,0($sp)");
                fprintf(fmips,"  jal %s\n",tempCode->id2);
                fprintf(fmips,"  lw $ra,0($sp)");
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

/*获取变量编号*/
int GetNum(char *s)
{
    char st[128];
    int lenth = strlen(s),i = 0;
    strcpy(st,s);
    for(i = 1;i <= lenth;++i){
        st[i-1] = st[i];
    }
    return atoi(st);
}

/*返回变量类型
 * 0--gv
 * 1--v
 * 2--t
 * */
int GetVarType(char *s)
{
    if(s[0] == '$'){
        return -1;
    }
    if(s[0] == 'g'){
        return 0;
    }
    else if(s[0] == 'v'){
        return 1;
    }
    else if(s[0] == 't'){
        return 2;
    }
    else{
        return -1;
    }
}

/*初始化可用的寄存器*/
void InitReg()
{
    int i = 0;
    R = (_pregUse)malloc(sizeof(_regUse)*(M));
    for(i = 0;i < M;++i){
        R[i].regnum = i + 2;
        R[i].use = 0;
    }
}

/*
 * 分配寄存器
 * op = 0--对非临时变量分配
 * op != 0--对临时变量分配,此时存放临时变量编号
 * */
int SelectReg(int op)
{
    int i = 0;
    _pVarInf vtemp = vHead;
    if(op){//对临时变量
        while(vtemp){
            if(vtemp->num == op){
                if(vtemp->addr == -1){
                    vtemp->addr = SelectReg(0);
                }
                return vtemp->addr;
            }
            vtemp = vtemp->next;
        }
    }
    for(i = 0;i < M;++i){
        if(!R[i].use){
            R[i].use = 1;
            return R[i].regnum;
        }
    }
    return -1;
}

/*插入一个变量信息*/
_pVarInf InsertVarInf(int op,int num,int addr)
{
    _pVarInf tp= (_pVarInf)malloc(sizeof(_VarInf));
    tp->type = op;
    tp->num = num;
    tp->addr = addr;
    tp->next = NULL;
    if(!vHead){
        vHead = tp;
    }
    else{
        tp->next = vHead->next;
        vHead->next = tp;
    }
    return tp;
}

/*删除一个变量信息*/
void DelVarInf(int op,int num)
{
    _pVarInf tp = vHead,tpre = vHead;
    while(tp){
        if(tp->type == op && tp->num == num){
            tpre->next = tp->next;
            if(tpre == vHead){
                vHead = tpre->next;
            }
            free(tp);
            return;
        }
        tpre = tp;
        tp = tp->next;
    }
}

/*删除所有临时变量信息*/
void DelTempVarInf()
{
    _pVarInf tp = vHead,tpre = vHead;
    while(tp){
        tpre = vHead;
        if(tp->type == 2){
            R[tp->addr].use = 0;//释放该临时变量所占用的寄存器
            tpre->next = tp->next;
            if(tpre == vHead){
                vHead = tpre->next;
            }
            free(tp);
            tp = tpre->next;
        }
        if(tp)
            tp = tp->next;
    }
}

/*查找变量*/
_pVarInf findVarInf(char *s)
{
    int type = GetVarType(s);
    int num = GetNum(s);
    _pVarInf tp = vHead;
    while(tp){
        if(tp->type == type && tp->num == num){
            return tp;
        }
        tp = tp->next;
    }
    return NULL;
}
