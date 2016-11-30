#include"syntaxTree.h"
/*
 * 在语法树中插入结点,变长参数
 * name:语法单元名字；
 * num:变长参数中语法结点个数
 * */
//自定义一个数值转换函数
int myatoi(char* s)
{
    unsigned int i;
    int temp = 0;
    if(s[0] != '0'){//十进制数
        return atoi(s);
    }
    else if(s[1] != 'x' && s[1] != 'X'){//八进制数
        for(i = 1;i < strlen(s);i++){
            if(s[i] >= '0' && s[i] <= '7')
                temp = temp * 8 + (s[i] - '0');
            else{
                return 0;
            }
        }
        return temp;
    }
    else{
        for(i = 2;i < strlen(s);i++){//十六进制数
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
                temp = temp * 16 + (s[i] & 15) + (s[i] >= 'A' ? 9 : 0);
            else{
                return 0;
            }
        }
        return temp;
    }
    return 0;
}

GrammaNode* InsertNode(char* name,int num,...)
{
    int i = 0;
    va_list valist; //定义变长参数列表
    GrammaNode *newNode=(GrammaNode*)malloc(sizeof(GrammaNode));//新生成的父节点
    GrammaNode *temp=(GrammaNode*)malloc(sizeof(GrammaNode));
    if(!newNode || !newNode)
    {
        yyerror("创建语法树时分配内存失败!");
        exit(0);
    }
    newNode->lchild = 0;
    newNode->rchild = 0;
    temp->lchild = 0;
    temp->rchild = 0;
    strcpy(newNode->name,name);//复制名字(非终结符)
    va_start(valist,num);//初始化变长参数为num

    if(num>0){//num>0为非终结符
        temp=va_arg(valist,GrammaNode*);
        newNode->lchild=temp;
        newNode->currentLine=temp->currentLine;//父节点a的行号等于左孩子的行号
        if(num>=2)
        {
            for(i=0; i < num-1; ++i)//取变长参数列表中的剩余结点，依次设置成兄弟结点
            {
                temp->rchild=va_arg(valist,GrammaNode*);
                temp=temp->rchild;
            }
        }
    }
    else{ //num==0为终结符或产生空的语法单元：第1个变长参数表示行号，产生空的语法单元行号为-1。
        int t=va_arg(valist, int); //取第1个变长参数
        newNode->currentLine = t;
        if(!strcmp(newNode->name,"ID")){
            strcpy(newNode->idType,yytext);
        }
        else if(!strcmp(newNode->name,"TYPE")){
            if(!strcmp(yytext,"int"))
                newNode->type = 1;
            else
                newNode->type = 2;
            strcpy(newNode->idType,yytext);
        }
        else if(!strcmp(newNode->name,"INT")){
            newNode->type = 1;
            newNode->integer = myatoi(yytext);
        }
        else if(!strcmp(newNode->name,"FLOAT")){
            newNode->type = 2;
            newNode->fnum = atof(yytext);
        }
        else if(!strcmp(newNode->name,"RELOP")){
            if(!strcmp(yytext,">"))
                newNode->relop = 1;
            else if(!strcmp(yytext,"<"))
                newNode->relop = 2;
            else if(!strcmp(yytext,">="))
                newNode->relop = 3;
            else if(!strcmp(yytext,"<="))
                newNode->relop = 4;
            else if(!strcmp(yytext,"=="))
                newNode->relop = 5;
            else if(!strcmp(yytext,"!="))
                newNode->relop= 6;
            else
                newNode->relop = 0;
        }
    }
    return newNode;
}

/*
 * 遍历抽象语法树, level为树的层数
 * */
void eval(GrammaNode *currentNode,int level)//先序遍历抽象语法树
{
    int i = 0;
    if(currentNode)
    {
        if(currentNode->currentLine != -1){
            for(i=0; i<level; ++i)
                fprintf(fgramma,"  ");
            fprintf(fgramma,"%s ",currentNode->name);
            if((!strcmp(currentNode->name,"ID"))||(!strcmp(currentNode->name,"TYPE")))
                fprintf(fgramma,": %s ",currentNode->idType);
            else if(!strcmp(currentNode->name,"INT"))
                fprintf(fgramma,": %d",currentNode->integer);
            else if(!strcmp(currentNode->name,"FLOAT"))
                fprintf(fgramma,": %f",currentNode->fnum);
            else
                fprintf(fgramma,"(%d)",currentNode->currentLine);
            fprintf(fgramma,"\n");
        }
        eval(currentNode->lchild,level+1);//遍历左子树
        eval(currentNode->rchild,level);//遍历右子树
    }
}

void yyerror(const char*s,...) //变长参数错误处理函数
{
    va_list ap;
    va_start(ap,s);
    fprintf(stderr,"Error Type B at Line %d:",yylineno);//错误行号
    vfprintf(stderr,s,ap);
    va_end(ap);
    fprintf(stderr,"\n");
}
