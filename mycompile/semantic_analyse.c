#include"semantic_analyse.h"

Hstack sk;//符号表栈
pHTable currentHTable; //当前作用域下的符号表

unsigned int hashtemp;
char currentType[10];

/*语义分析*/
void semantic()
{
    /*初始化符号表栈*/
    sk.base = (pHTable*)malloc(sizeof(pHTable)*STACK_SIZE);
    sk.top = sk.base;
    sk.size = 0;
    CreatSimbolTable(grammaTreeHead,0);
}

/*符号表入栈*/
void push(pHTable ph)
{
    if(sk.size < STACK_SIZE){
        *sk.top++ = ph;
        sk.size += 1;
    }
    else{
        printf("Simbol Stack Full!!!\n");
    }
}

/*符号表出栈*/
void pop(pHTable* ph)
{
    if(sk.size){
        if(*ph)
            free(*ph);//释放原符号表
        *ph = *--sk.top;
        sk.size -= 1;
    }
    else{
        printf("Stack error!\n");
    }
}

/*得到栈顶元素*/
void GetTop(pHTable* ph)
{
    if(sk.size){
        *ph = *(sk.top-1);
    }
    else{
        printf("Stack error!\n");
    }
}

/*hash值计算*/
unsigned int hashcalc(char *name)
{
    unsigned int val = 0,i;
    for(; *name; ++name){
        val = (val << 2) + *name;
        if(i = val & ~0xff)
            val = (val ^ (i >> 12)) & 0xff;
    }
    return val;
}

/*初始化hush表*/
void InitHashTable(pHTable* pH)
{
    int i = 0;
    for(i = 0;i < TABLE_MAX;++i){
        *pH -> hash = 0;
        *pH -> Sptr = NULL;
        *pH -> Fptr = NULL;
    }
}

/*
 * 遍历语法树, level为树的层数
 * 构建符号表,同时进行语义分析
 * */
void CreatSimbolTable(GrammaNode *currentNode,int level)//先序遍历抽象语法树
{
    int i = 0;
    if(currentNode)
    {
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Program")){//创建全局符号栈
                currentHTable = (pHTable)malloc(sizeof(HTable)*TABLE_MAX);
                InitHashTable(&currentHTable);
            }
            else if(!strcmp(currentNode->name,"LC")){
                push(currentNode);//将当前符号表入栈
                //创建一个当前作用域的符号表
                currentHTable = (pHTable)malloc(sizeof(HTable)*TABLE_MAX);
            }
            else if(!strcmp(currentNode->name,"RC")){
                if(sk.size){//将上一层符号表作为当前符号表
                    pop(&currentHTable);
                }
            }
            //全局变量结构,函数的定义
            else if(!strcmp(currentNode->name,"ExtDef")){
                if(currentNode){
                    if(!strcmp(currentNode->lchild->rchild->name,"ExtDefList")){
                        //全局变量定义

                    }
                    if(!strcmp(currentNode->lchild->rchild->name,"SEMI")){
                        //结构的定义

                    }
                    if(!strcmp(currentNode->lchild->rchild->name,"FunDec")){
                        //函数的定义

                    }
                }
            }
        }
        eval(currentNode->lchild,level+1);//遍历左子树
        eval(currentNode->rchild,level);//遍历右子树
    }
}

/*变量*/
void evalGvar(GrammaNode *currentNode)
{
    if(currentNode)
    {
        if(currentNode->currentLine != -1){
            if(!(strcmp(currentNode->name,"TYPE"))){
                strcpy(currentType,currentNode->idType);
            }
            else if(!(strcmp(currentNode->name,"ID"))){
                hashtemp = hashcalc(currentNode->name);
                if(!currentHTable[hashtemp].Sptr){
                    currentHTable[hashtemp].Sptr = (pSTable)malloc(sizeof(STable));
                    strcpy(currentHTable[hashtemp].Sptr->name,currentNode->name);

                }
                currentHTable[hashtemp].
            }
        }
        eval(currentNode->lchild,level+1);//遍历左子树
        eval(currentNode->rchild,level);//遍历右子树
    }
}
