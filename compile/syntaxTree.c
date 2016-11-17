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
        if(num == 1){
            strcpy(newNode->content,temp->content);
            newNode->tag = temp->tag;
        }
        else
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
        if(!strcmp(newNode->name,"INT")){
            strcpy(newNode->type,"int");
            newNode->integer = myatoi(yytext);
        }
        else if(!strcmp(newNode->name,"FLOAT")){
            strcpy(newNode->type,"float");
            newNode->fnum = atof(yytext);
        }
        else{
           strcpy(newNode->content,yytext);
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
                fprintf(fgramma,": %s ",currentNode->content);
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

/*====(1)变量符号表的建立和查询================*/
void newvar(int num,...)//1)创建变量符号表
{
    va_list valist; //定义变长参数列表
    struct var *a=(struct var*)malloc(sizeof(struct var));//新生成的父节点
    struct GrammaNode *temp=(struct GrammaNode*)malloc(sizeof(struct GrammaNode));
    va_start(valist,num);//初始化变长参数为num后的参数
    temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第一个结点
    strcpy(a->type,temp->content);
    temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第二个结点
    strcpy(a->name,temp->content);
    vartail->next=a;
    vartail=a;
}

int  exitvar(struct GrammaNode* tp)//2)查找变量是否已经定义,是返回1，否返回0
{
    struct var* p=(struct var*)malloc(sizeof(struct var*));
    p=varhead->next;
    int flag=0;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
        {
            flag=1;    //存在返回1
            return 1;
        }
        p=p->next;
    }
    if(!flag)
    {
        return 0;//不存在返回0
    }
}

char* typevar(struct GrammaNode*tp)//3)查找变量类型
{
    struct var* p=(struct var*)malloc(sizeof(struct var*));
    p=varhead->next;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
            return p->type;//返回变量类型
        p=p->next;
    }
}
/*====(2)函数符号表的建立和查询================*/
void newfunc(int num,...)//1)创建函数符号表
{
    va_list valist; //定义变长参数列表
    struct GrammaNode *temp=(struct GrammaNode*)malloc(sizeof(struct GrammaNode));
    va_start(valist,num);//初始化变长参数为num后的参数
    switch(num)
    {
        case 1:
            functail->pnum+=1;//参数个数加1
            break;
        case 2://记录函数名
            temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第1个结点
            strcpy(functail->name,temp->content);
            break;
        case 3://记录实际返回值
            temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第1个结点
            strcpy(functail->rtype,temp->type);
            break;
        default://记录函数类型,返回类型不匹配则报出错误
            rpnum=0;//将实参个数清0
            temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第1个结点
            if(functail->rtype!=NULL)//实际返回类型和函数定义的返回类型比较
            {
                if(strcmp(temp->content,functail->rtype))
                    printf("Error type 8 at Line %d:Type mismatched for return.\n",yylineno);
            }
            strcpy(functail->type,temp->type);
            functail->tag=1;//标志为已定义
            struct func *a=(struct func*)malloc(sizeof(struct func));
            functail->next=a;//尾指针指向下一个空结点
            functail=a;
            break;
        }
}

int  exitfunc(struct GrammaNode* tp)//2)查找函数是否已经定义,是返回1，否返回0
{
    int flag=0;
    struct func* p=(struct func*)malloc(sizeof(struct func*));
    p=funchead->next;
    while(p!=NULL&&p->name!=NULL&&p->tag==1)
    {
        if(!strcmp(p->name,tp->content))
        {
            flag=1;    //存在返回1
            return 1;
        }
        p=p->next;
    }
    if(!flag)
        return 0;//不存在返回0
}
char* typefunc(struct GrammaNode*tp)//3)查找函数类型
{
    struct func* p=(struct func*)malloc(sizeof(struct func*));
    p=funchead->next;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
            return p->type;//返回函数类型
        p=p->next;
    }
}

int pnumfunc(struct GrammaNode*tp)//4)查找函数的形参个数
{
    struct func* p=(struct func*)malloc(sizeof(struct func*));
    p=funchead->next;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
            return p->pnum;//返回形参个数
        p=p->next;
    }
}

/*====(3)数组符号表的建立和查询================*/
void newarray(int num,...)//1)创建数组符号表
{
    va_list valist; //定义变长参数列表
    struct array *a=(struct array*)malloc(sizeof(struct array));//新生成的父节点
    struct GrammaNode *temp=(struct GrammaNode*)malloc(sizeof(struct GrammaNode));
    va_start(valist,num);//初始化变长参数为num后的参数
    temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第一个结点
    strcpy(a->type,temp->content);
    temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第二个结点
    strcpy(a->name,temp->content);
    arraytail->next=a;
    arraytail=a;
}

int  exitarray(struct GrammaNode* tp)//2)查找数组是否已经定义,是返回1，否返回0
{
    struct array* p=(struct array*)malloc(sizeof(struct array*));
    p=arrayhead->next;
    int flag=0;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
        {
            flag=1;    //存在返回1
            return 1;
        }
        p=p->next;
    }
    if(!flag)
    {
        return 0;//不存在返回0
    }
}

char* typearray(struct GrammaNode* tp)//3)查找数组类型
{
    struct array* p=(struct array*)malloc(sizeof(struct array*));
    p=arrayhead->next;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
            return p->type;//返回数组类型
        p=p->next;
    }
}
/*====(4)结构体符号表的建立和查询================*/
void newstruc(int num,...)//1)创建结构体符号表
{
    va_list valist; //定义变长参数列表
    struct struc *a=(struct struc*)malloc(sizeof(struct struc));//新生成的父节点
    struct GrammaNode *temp=(struct GrammaNode*)malloc(sizeof(struct GrammaNode));
    va_start(valist,num);//初始化变长参数为num后的参数
    temp=va_arg(valist, struct GrammaNode*);//取变长参数列表中的第二个结点
    strcpy(a->name,temp->content);
    structail->next=a;
    structail=a;
}

int  exitstruc(struct GrammaNode* tp)//2)查找结构体是否已经定义,是返回1，否返回0
{
    struct struc* p=(struct struc*)malloc(sizeof(struct struc*));
    p=struchead->next;
    int flag=0;
    while(p!=NULL)
    {
        if(!strcmp(p->name,tp->content))
        {
            flag=1;    //存在返回1
            return 1;
        }
        p=p->next;
    }
    if(!flag)
    {
        return 0;//不存在返回0
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
