#include"semantic_analyse.h"
#define I_MAXLENTH 32
#define TABLE_MAX  0xff //符号表的容量
#define REALPARA_MAX 10 //允许的实参最大个数

_pHashTable HashHead = NULL;//指向当前hash表
_pVarTable currentVar = NULL;
_pStructTable currentStruct = NULL;
_pFuncTable currentFunc = NULL,currentFunc2 = NULL;
_pVarTable parameter = NULL;//行参指针
_pExpType currentExpType = NULL;

int returnFlag = 1; //设置标记,用于递归函数的返回
int tag = 0; //1--int,2--float 3--struct
int arrayLat = 0,arrayLat2 = 0; //记录数组维数
int UnNameStructNum = 0;
int RealNum = 0;//实参的实际个数
int defineFlag = 1;
char currentId[I_MAXLENTH];
char UnNameStructStr[4];
GrammaNode* expFlags = NULL;//设置Exp标记,便于Exp检测时的遍历
_ExpType RealPara[REALPARA_MAX];

/*语义分析*/
void semantic()
{
    CreatSimbolTable(grammaTreeHead);
    CheckFuncDef(grammaTreeHead);
    if(SemanToggle){
        PrintFunSimbol();
        PrintStructSimbol();
        PrintVarSimbol();
    }
}

/*
 * 遍历语法树, level为树的层数
 * 构建符号表,同时进行语义分析
 * */
void CreatSimbolTable(GrammaNode *currentNode)//先序遍历抽象语法树
{
    if(currentNode)
    {
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Program")){//创建全局符号栈
                int i = 0;
                HashHead = (_pHashTable)malloc(sizeof(_HashTable)*TABLE_MAX);
                for(i = 0;i < TABLE_MAX; i++){
                    InitHashTable(HashHead[i]);
                }
            }
            else if(!strcmp(currentNode->name,"ExtDef")){
                switch(currentNode->rulenum){
                    case 1://全局变量的定义
                        if(currentNode->lchild->rulenum == 1){//非结构体
                            tag = currentNode->lchild->type;
                            //从ExtDecList处开始搜索子树
                            FindVar(currentNode->lchild,1);
                        }
                        else{
                            tag = 3;
                            strcpy(currentId,currentNode->lchild->idType);
                            if(exitStruct(currentId) == 1){//未定义该结构体
                                PrintError(17,currentNode->currentLine,currentId);
                            }
                            else{ //从ExtDecList处开始搜索子树
                                FindVar(currentNode->lchild,1);
                            }
                        }
                        currentNode = currentNode->rchild;
                        returnFlag = 1;
                        CheckExpType(expFlags);
                        expFlags = NULL;
                        break;
                    case 2://全局结构的定义
                    case 3://全局结构的定义(带变量)
                        if(currentNode->lchild->lchild->rchild->currentLine == -1){//处理匿名结构
                            sprintf(UnNameStructStr,"%d",UnNameStructNum);
                            strcpy(currentId,UnNameStructStr);
                            ++UnNameStructNum;
                        }
                        else{//有名结构
                            strcpy(currentId,currentNode->lchild->idType);
                        }
                        currentStruct = (_pStructTable)malloc(sizeof(_StructTable));//新建一个结构
                        currentStruct->head = NULL;
                        currentStruct->next = NULL;
                        currentStruct->memnum = 0;
                        strcpy(currentStruct->structName,currentId);//复制结构名字
                        if(!exitStruct(currentId)){//结构重定义
                            PrintError(16,currentNode->currentLine,currentId);
                        }
                        else{
                            FindStructVar(currentNode->lchild);
                            addStruct(currentStruct);
                        }
                        if(currentNode->rulenum == 3){//增加结构变量
                            tag = 3;
                            strcpy(currentId,currentStruct->structName);
                            FindVar(currentNode->lchild->rchild,1);
                        }
                        currentNode = currentNode->rchild;
                        returnFlag = 1;
                        currentStruct = NULL;//初始化当前结构体指针
                        break;
                    case 4://函数声明
                        strcpy(currentId,currentNode->lchild->rchild->idType);
                        if(!exitFunc(currentId)){//不存在该函数
                            //申请一个函数空间
                            currentFunc = (_pFuncTable)malloc(sizeof(_FuncTable));
                            //初始化函数
                            currentFunc->paraHead = NULL;
                            currentFunc->localHead = NULL;
                            currentFunc->next = NULL;
                            //复制函数名字
                            strcpy(currentFunc->funName,currentId);
                        }
                        //判断函数的返回类型
                        if(currentNode->lchild->rulenum == 1){//非结构体
                            currentFunc->kind = currentNode->lchild->type;
                            //从ExtDef->lchild处开始搜索子树
                            FindFunc(currentNode->lchild,0);
                        }
                        else{
                            currentFunc->kind = 3;
                            strcpy(currentFunc->backName,currentNode->lchild->idType);
                            if(exitStruct(currentFunc->backName) == 1){//未定义该结构体
                                PrintError(17,currentNode->currentLine,currentFunc->backName);
                            }
                            //从ExtDef->lchild处开始搜索子树
                            FindFunc(currentNode->lchild,0);
                        }
                        currentFunc->defineTag = 0;
                        addFunc(currentFunc);
                        currentFunc = NULL;
                        break;
                    case 5://函数的定义
                        defineFlag = 1;//初始化为未声明,直接定义
                        strcpy(currentId,currentNode->lchild->rchild->idType);
                        if(exitFunc(currentId)){
                            defineFlag = 0;
                            if(currentFunc && currentFunc->defineTag == 1){
                                PrintError(4,currentNode->currentLine,currentFunc->funName);
                                break;
                            }
                        }
                        else{
                            //申请一个函数空间
                            currentFunc = (_pFuncTable)malloc(sizeof(_FuncTable));
                            //初始化函数
                            currentFunc->paraHead = NULL;
                            currentFunc->localHead = NULL;
                            currentFunc->next = NULL;
                            //复制函数名字
                            strcpy(currentFunc->funName,currentNode->lchild->rchild->idType);
                        }
                        //判断函数的返回类型
                        if(currentNode->lchild->rulenum == 1){//非结构体
                            currentFunc->kind = currentNode->lchild->type;
                            //从ExtDef->lchild处开始搜索子树
                            if(defineFlag)
                                FindFunc(currentNode->lchild,2);
                            else
                                FindFunc(currentNode->lchild,1);
                        }
                        else{
                            currentFunc->kind = 3;
                            strcpy(currentFunc->backName,currentNode->lchild->idType);
                            if(exitStruct(currentFunc->backName) == 1){//未定义该结构体
                                PrintError(17,currentNode->currentLine,currentFunc->backName);
                            }
                            //从ExtDef->lchild处开始搜索子树
                            if(defineFlag)
                                FindFunc(currentNode->lchild,2);
                            else
                                FindFunc(currentNode->lchild,1);
                        }
                        currentFunc->defineTag = 1;
                        if(defineFlag)
                            addFunc(currentFunc);
                        CheckExpType(expFlags);
                        expFlags = NULL;
                        currentFunc = NULL;
                        currentNode = currentNode->rchild;
                        break;
                    default:
                        break;
                }
            }
        }
        CreatSimbolTable(currentNode->lchild);//遍历左子树
        CreatSimbolTable(currentNode->rchild);//遍历右子树
    }
}

/*
 * 检测Exp类型
 * */
void CheckExpType(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Exp")){//检查表达式类型
                GrammaNode* temp = currentNode->lchild;
                switch(currentNode->rulenum){
                    case 1://Exp ASSIGNOP Exp//暂为对结构进行类型检查
                        CheckExpType(temp);//这个会遍历整个规则式
                        if(temp->integer == -1){
                            PrintError(6,currentNode->currentLine,NULL);
                        }
                        else if(temp->type != temp->rchild->rchild->type){
                            PrintError(5,currentNode->currentLine,NULL);
                        }
                        else{
                            if(temp->type == 3){//结构的内容等价
                                if(!isEqualStruct(temp->idType,temp->rchild->rchild->idType,0)){
                                    PrintError(5,currentNode->currentLine,NULL);
                                }
                            }
                            else{
                                currentNode->type = temp->type;
                                if(currentNode->type == 3){
                                    strcpy(currentNode->idType,temp->rchild->idType);
                                }
                            }
                        }
                        break;
                    case 2://Exp AND EXP
                    case 3://Exp OR Exp
                    case 4://Exp RELOP Exp
                        CheckExpType(temp);
                        if(temp->type == 1 && temp->rchild->rchild->type == 1){
                            currentNode->type = temp->type;
                        }
                        else{
                            PrintError(5,currentNode->currentLine,NULL);
                        }
                        currentNode->integer = -1;
                        break;
                    case 5://Exp PLUS Exp
                    case 6://Exp MINUS Exp
                    case 7://Exp STAR Exp
                    case 8://Exp DIV Exp
                    case 9://Exp MOD Exp
                        CheckExpType(temp);
                        if(temp->type == temp->rchild->rchild->type && (temp->type == 2 || temp->type == 1)){
                            currentNode->type = temp->type;
                        }
                        else{
                            PrintError(5,currentNode->currentLine,NULL);
                        }
                        currentNode->integer = -1;
                        break;
                    case 10://LP Exp RP
                        CheckExpType(temp->rchild);
                        currentNode->type = temp->rchild->type;
                        if(currentNode->type == 3){
                            strcpy(currentNode->idType,temp->rchild->idType);
                        }
                        break;
                    case 11://MINUS Exp
                        CheckExpType(temp->rchild);
                        if(temp->rchild->type != 1 || temp->rchild->type != 2){
                            PrintError(7,currentNode->currentLine,NULL);
                        }
                        else{
                            currentNode->type = temp->rchild->type;
                        }
                        currentNode->integer = -1;
                        break;
                    case 12://NOT Exp
                        CheckExpType(temp->rchild);
                        if(temp->rchild->type != 1){
                            PrintError(7,currentNode->currentLine,NULL);
                        }
                        else{
                            currentNode->type = temp->rchild->type;
                        }
                        currentNode->integer = -1;
                        break;
                    case 14://ID LP RP
                    case 13://ID LP Args RP
                        currentExpType = FuncBackType(currentNode->idType);
                        if(!currentExpType){
                            PrintError(2,currentNode->currentLine,currentNode->idType);
                        }
                        else{
                            currentNode->type = currentExpType->kind;
                            if(currentExpType->kind == 3)
                                strcpy(currentNode->idType,currentExpType->id);
                            if(currentNode->rulenum == 13){//比较参数
                                RealNum = 0;
                                GetRealPara(temp->rchild->rchild);
                                if(!ComparePara(currentNode->idType)){//比较实参与形参
                                    PrintError(9,currentNode->rulenum,NULL);
                                }
                            }
                        }
                        break;
                    case 15://Exp LB Exp RB
                        if(!arrayLat2){
                            GetLat(temp);//获取数组的维度
                            CheckExpType(temp->rchild->rchild->lchild);
                        }
                        if(temp->rchild->rchild->type != 1){
                                //if(!strcmp(temp->rchild->rchild->name,"FLOAT")){字符串转换成整数
                                //    PrintError(12,currentNode->currentLine,)
                                //}
                                PrintError(12,currentNode->currentLine,temp->rchild->rchild->idType);
                        }
                        CheckExpType(temp);
                        currentNode->type = temp->type;//在多维数组时有用
                        if(arrayLat2){
                            if(temp->type < 4){
                                PrintError(10,currentNode->currentLine,temp->idType);
                            }
                            else{
                                if((temp->type/16) != arrayLat2){
                                    PrintError(7,currentNode->currentLine,NULL);
                                    currentNode->type = 4;//数组
                                }
                                else{
                                    if((temp->type%16)==4){
                                        currentNode->type = 1;
                                    }
                                    else{
                                        currentNode->type = 2;
                                    }
                                }
                            }
                            arrayLat2 = 0;
                        }
                        break;
                    case 16://Exp DOT ID
                        CheckExpType(temp);
                        if(temp->type != 3 || !exitVar(temp->idType)){//不存在该结构变量
                            PrintError(13,currentNode->currentLine,NULL);
                        }
                        else{
                            currentExpType = StructBackType(currentVar->type->typeSys.structId,temp->rchild->rchild->idType);
                            if(!currentExpType){
                                PrintError(13,currentNode->currentLine,NULL);
                            }
                            else{
                                currentNode->type = currentExpType->kind;
                                strcpy(currentNode->idType,currentExpType->id);
                            }
                            currentVar = NULL;
                        }
                        break;
                    case 17://ID
                        currentExpType = VarBackType(currentNode->idType);
                        if(currentExpType){
                            currentNode->type = currentExpType->kind;
                        }
                        else{
                            PrintError(1,currentNode->currentLine,currentNode->idType);
                        }
                        break;
                    case 18://INT
                        currentNode->type = 1;
                        currentNode->integer = -1;
                        break;
                    case 19://FLOAT
                        currentNode->type = 2;
                        currentNode->integer = -1;
                        break;
                    default:
                        currentNode->type = -1;
                        break;
                }
                if(currentNode->rchild){
                    currentNode = currentNode->rchild;
                }
                if(currentExpType){
                    free(currentExpType);
                    currentExpType = NULL;
                }
            }
        }
        CheckExpType(currentNode->lchild);
        CheckExpType(currentNode->rchild);
    }
}

/*处理函数使用未定义的情况*/
void CheckFuncDef(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if((currentNode->rulenum == 13 || currentNode->rulenum == 14) &&
                    !strcmp(currentNode->name,"Exp")){
                currentExpType = FuncBackType(currentNode->idType);
                if(currentFunc2 && !currentFunc2->defineTag){
                    PrintError(2,currentNode->currentLine,currentNode->idType);
                }
            }
        }
        CheckFuncDef(currentNode->lchild);
        CheckFuncDef(currentNode->rchild);
    }
}

/*获取函数实参类型表*/
void GetRealPara(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Args")){
                CheckExpType(currentNode->lchild);
                RealPara[RealNum].kind = currentNode->lchild->type;
                if(currentNode->lchild->type == 3){
                    strcpy(RealPara[RealNum].id,currentNode->lchild->idType);
                }
                ++RealNum;
            }
        }
        GetRealPara(currentNode->lchild);
        GetRealPara(currentNode->rchild);
    }
}

/*
 * 比较实参与形参
 * 1--相同
 * 0--不同
 * */
int ComparePara(char *id)
{
    int i = 0;
    unsigned int hash = hashcalc(id);
    _pVarTable vtemp = HashHead[hash].funHead->paraHead;
    for(i = 0;i < RealNum;++i){
        if(vtemp){
            if(RealPara[i].kind == 3 && vtemp->type->kind == 3){//实参是结构
                if(!isEqualStruct(RealPara[i].id,vtemp->type->typeSys.structId,1)){
                    return 0;
                }
            }
            else if(RealPara[i].kind != vtemp->type->kind){
                return 0;
            }
            vtemp = vtemp->next;
        }
        else{
            return 0;
        }
    }
    if(i != RealNum)
        return 0;
    else
        return 1;
}

/*
 * 寻找当前子树下的变量定义
 * op--1 在符号表中增加变量
 * op--2 在结构中增加变量
 * op--3 增加函数形参
 * op--4 增加局部变量
 * */
void FindVar(GrammaNode* currentNode,int op)
{
    if(returnFlag && currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Dec") && (currentNode->rulenum == 2)){
                GrammaNode* temp = currentNode->lchild->rchild->rchild;
                CheckExpType(temp);
                if(tag != temp->type){
                    PrintError(5,currentNode->currentLine,NULL);
                }
                else if(temp->type == 3){//结构的内容等价
                    if(!isEqualStruct(temp->idType,currentVar->id,0)){
                        PrintError(5,currentNode->currentLine,NULL);
                    }
                }
            }
            else if(!strcmp(currentNode->name,"SEMI") || !strcmp(currentNode->name,"COMMA")){
                if(currentVar->type->kind == 2 || currentVar->type->kind == 4){//数组
                    currentVar->type->typeSys.array.lat = arrayLat;
                    arrayLat = 0;
                    //给数组的类型分配空间
                    currentVar->type->typeSys.array.elem = (union u*)malloc(sizeof(union u));
                    if(!currentVar->type->typeSys.array.elem){
                        printf("storage error!\n"); exit(1);
                    }
                    if(tag == 3)
                        strcpy(currentVar->type->typeSys.array.elem->structId,currentId);
                    else
                        currentVar->type->typeSys.array.elem->basic = tag;
                }
                else if(tag == 3)
                    strcpy(currentVar->type->typeSys.structId,currentId);
                else
                    currentVar->type->typeSys.basic = tag;

                if(op == 1)
                    addVar(currentVar);//在符号表中增加变量
                else if(op == 2){
                    addStructVar(currentVar);//在结构中增加变量
                    ++currentStruct->memnum;//结构体成员数目增1
                }
                else if(op == 3){
                    addFuncPara(currentVar);//增加函数形参
                    returnFlag = 0;
                }
                else if(op == 4)//在函数中增加局部变量
                    addLocalVar(currentVar);
                currentVar = NULL;//初始化变量currentVar
                if(!strcmp(currentNode->name,"SEMI")){
                    returnFlag = 0;
                    return;
                }
            }
            else if(!strcmp(currentNode->name,"ID")){
                if(currentNode->type != 3){
                    _pStructTable tStruct = currentStruct;//进行结构体变量的判断
                    if(op == 1){
                        currentStruct = NULL;
                    }
                    if(exitVar(currentNode->idType) == 1){
                        PrintError(3,currentNode->currentLine,currentNode->idType);
                    }
                    if(op == 1){
                        currentStruct = tStruct;
                    }
                    currentVar = (_pVarTable)malloc(sizeof(_VarTable));
                    if(!currentVar){
                        printf("storage error!\n"); exit(1);
                    }
                    strcpy(currentVar->id,currentNode->idType);
                    currentVar->type = (_pType)malloc(sizeof(_Type));
                    if(!currentVar->type){
                        printf("storage error!\n"); exit(1);
                    }
                    if(tag == 3)
                        currentVar->type->kind = 3;
                    else
                        currentVar->type->kind = 1;
                }
            }
            else if(!strcmp(currentNode->name,"LB")){
                if(!arrayLat){
                    if(tag == 3)
                        currentVar->type->kind = 4;
                    else
                        currentVar->type->kind = 2;
                }
                ++arrayLat;
            }
            else if(!strcmp(currentNode->name,"INT")){
                if(arrayLat)
                    currentVar->type->typeSys.array.size[arrayLat-1] = currentNode->integer;
            }
        }
        FindVar(currentNode->lchild,op);//遍历左子树
        FindVar(currentNode->rchild,op);//遍历右子树
    }
}

/*找到结构内变量定义*/
void FindStructVar(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Def")){
                if(currentNode->lchild->rulenum == 1){//非结构体
                    tag = currentNode->lchild->type;
                    //从ExtDecList处开始搜索子树
                    FindVar(currentNode,2);
                    returnFlag = 1;
                }
                else{
                    tag = 3;
                    strcpy(currentId,currentNode->lchild->idType);
                    if(exitStruct(currentId)){//未定义该结构体或者为正在定义的结构体
                        PrintError(17,currentNode->currentLine,currentId);
                    }
                    else{ //从ExtDecList处开始搜索子树
                        FindVar(currentNode,2);
                        returnFlag = 1;
                    }
                }
                currentNode = currentNode->rchild;
            }
        }
        FindStructVar(currentNode->lchild);//遍历左子树
        FindStructVar(currentNode->rchild);//遍历右子树
    }
}

/*
 * 寻找函数中的变量
 * op--0 函数声明
 * op--1 函数定义
 * */
void FindFunc(GrammaNode* currentNode,int op)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(op && !expFlags && currentNode->lchild && !strcmp(currentNode->lchild->name,"Exp")){
                expFlags = currentNode;
            }
            else if(op && !strcmp(currentNode->name,"Def")){
                if(currentNode->lchild->rulenum == 1){//非结构体
                    tag = currentNode->lchild->type;
                    //从Def处开始搜索子树
                    FindVar(currentNode,4);
                    returnFlag = 1;
                }
                else{
                    tag = 3;
                    strcpy(currentId,currentNode->lchild->idType);
                    if(exitStruct(currentId) == 1){//未定义该结构体
                        PrintError(17,currentNode->currentLine,currentId);
                    }
                    else{ //从Def处开始搜索子树
                        FindVar(currentNode,4);
                        returnFlag = 1;
                    }
                }
                currentNode = currentNode->rchild;
            }
            else if((!op || op==2) && !strcmp(currentNode->name,"ParamDec")){//寻找行参
                if(currentNode->lchild->rulenum == 1){//非结构体
                    tag = currentNode->lchild->type;
                    //从Def处开始搜索子树
                    FindVar(currentNode,3);
                    returnFlag = 1;
                }
                else{
                    tag = 3;
                    strcpy(currentId,currentNode->lchild->idType);
                    if(exitStruct(currentId) == 1){//未定义该结构体
                        PrintError(17,currentNode->currentLine,currentId);
                    }
                    //从Def处开始搜索子树
                    FindVar(currentNode,3);
                    returnFlag = 1;
                }
                currentNode = currentNode->rchild;
            }
            else if(op && !strcmp(currentNode->name,"Stmt") && currentNode->rulenum == 3){//处理return
                GrammaNode* temp = currentNode->lchild->rchild;
                CheckExpType(temp);
                if(temp->type != currentFunc->kind){
                    PrintError(8,currentNode->currentLine,NULL);
                }
                else if(temp->type == 3){//结构的内容等价
                    if(!isEqualStruct(currentFunc->backName,currentVar->id,0)){
                        PrintError(5,currentNode->currentLine,NULL);
                    }
                }
                currentNode = currentNode->rchild;
            }
        }
        FindFunc(currentNode->lchild,op);//遍历左子树
        FindFunc(currentNode->rchild,op);//遍历右子树
    }
}

/*hash值计算*/
unsigned int hashcalc(char *name)
{
    unsigned int val = 0,i;
    for(; *name; ++name){
        val = (val << 2) + *name;
        i = val & ~0xff;
        if(i)
            val = (val ^ (i >> 12)) & 0xff;
    }
    return val;
}

/*初始化hush表*/
void InitHashTable(_HashTable pH)
{
    int i = 0;
    for(i = 0;i < TABLE_MAX;++i){
        pH.Hash = 0;
        pH.funHead  = NULL;
        pH.varHead = NULL;
        pH.structHead = NULL;
    }
}

/*新增一个全局变量*/
void addVar(_pVarTable pv)
{
    unsigned int hash = hashcalc(pv->id);
    _pVarTable temp = HashHead[hash].varHead;
    if(pv->next)
        pv->next = NULL;
    if(!temp){
        HashHead[hash].varHead = pv;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = pv;
}

/*新增一个局部变量*/
void addLocalVar(_pVarTable pv)
{
    _pVarTable temp = currentFunc->localHead;
    if(pv->next)
        pv->next = NULL;
    if(!temp){
        currentFunc->localHead = pv;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = pv;
}

/*增加函数形参*/
void addFuncPara(_pVarTable pv)
{
    _pVarTable temp = currentFunc->paraHead;
    if(pv->next)
        pv->next = NULL;
    if(!temp){
        currentFunc->paraHead = pv;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = pv;
}

/*复制变量信息*/
void CopyVar(_pVarTable pt,_pVarTable ps)
{
    if(!pt || !ps){
        printf("error for var copy!\n");
        exit(1);
    }
    strcpy(pt->id,ps->id);
    pt->type = ps->type;
    pt->next = ps->next;
    return;
}

/*
 * 比较两个变量是否完全一致
 * 1--一致
 * 0--不一致
 * */
int isEqualVar(_pVarTable pt,_pVarTable ps)
{
    int i = 0;
    if(pt && ps && !strcmp(pt->id,ps->id)){//比较变量名
        if(pt->type->kind == ps->type->kind){//比较类型号
            switch(pt->type->kind){
                case 1://BASIC
                    if(pt->type->typeSys.basic == ps->type->typeSys.basic)
                        return 1;
                    break;
                case 2://BASIC ARRAY
                    if(pt->type->typeSys.array.elem->basic == ps->type->typeSys.array.elem->basic
                        && pt->type->typeSys.array.lat == ps->type->typeSys.array.lat){//比较数组类型和维数
                        for(i = 0;i < pt->type->typeSys.array.lat;++i){
                            if(pt->type->typeSys.array.size[i] != ps->type->typeSys.array.size[i])
                                return 0;
                        }
                        return 1;
                    }
                    break;
                case 3://STRUCT
                    if(!strcmp(pt->type->typeSys.structId,ps->type->typeSys.structId))
                        return 1;
                    break;
                case 4://STRUCT ARRAY
                    if(!strcmp(pt->type->typeSys.array.elem->structId,ps->type->typeSys.array.elem->structId)
                        && pt->type->typeSys.array.lat == ps->type->typeSys.array.lat){//比较数组类型和维数
                        for(i = 0;i < pt->type->typeSys.array.lat;++i){
                            if(pt->type->typeSys.array.size[i] != ps->type->typeSys.array.size[i])
                                return 0;
                        }
                        return 1;
                    }
                    break;
                default:
                    printf("error\n");
            }
        }
    }
    return 0;
}

/*新增一个结构成员*/
void addStructVar(_pVarTable pv)
{
    _pVarTable temp = currentStruct->head;
    if(pv->next)
        pv->next = NULL;
    if(!(currentStruct->head)){
        currentStruct->head = pv;
        return;
    }
    while(temp->next){
        temp  = temp->next;
    }
    temp->next = pv;
}

/*判断变量是否存在
 * id--标志符名称
 * 0--不存在
 * 1--在当前作用域存在
 * 2--在外层作用域存在
 * */
int exitVar(char *id)
{
    unsigned int hash = hashcalc(id);
    _pVarTable temp;
    if(currentFunc){//表示函数内变量
        temp = currentFunc->paraHead;//先搜索形参列表
        while(temp){
            if(!strcmp(temp->id,id)){
                currentVar = temp;
                return 1;
            }
            temp = temp->next;
        }
        temp = currentFunc->localHead;//搜索函数内部
        while(temp){
            if(!strcmp(temp->id,id)){
                currentVar = temp;
                return 1;
            }
            temp = temp->next;
        }
        temp = HashHead[hash].varHead;//搜索全局变量
        while(temp){
            if(!strcmp(temp->id,id)){
                currentVar = temp;
                return 2;
            }
            temp = temp->next;
        }
    }
    else if(currentStruct){//表示结构体变量
        temp = currentStruct->head;
        while(temp){
            if(!strcmp(temp->id,id)){
                currentVar = temp;
                return 1;
            }
            temp = temp->next;
        }
    }
    else{//表示全局变量
        temp = HashHead[hash].varHead;
        while(temp){
            if(!strcmp(temp->id,id)){
                currentVar = temp;
                return 1;
            }
            temp = temp->next;
        }
    }
    currentVar = NULL;
    return 0;
}


/*新增加一个结构体定义*/
void addStruct(_pStructTable ps)
{
    unsigned int hash = hashcalc(ps->structName);
    _pStructTable temp = HashHead[hash].structHead;
    if(ps->next)
        ps->next = NULL;
    if(!temp){
        HashHead[hash].structHead = ps;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = ps;
}

/*判断结构是否存在
 * id--标识符名称
 * 0--存在
 * 1--不存在
 * 2--正定义
 * */
int exitStruct(char *id)
{
    unsigned int hash = hashcalc(id);
    _pStructTable temp = HashHead[hash].structHead;
    if(currentStruct){
        if(!strcmp(currentStruct->structName,id)){//先判断是不是正在定义的结构
            return 2;
        }
    }
    while(temp){
        if(!strcmp(temp->structName,id)){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

/*
 * 判断两个结构是否内容等价
 * 1--是
 * 0--否
 * op--0 id1 id2为结构变量
 * op--1 id1为结构变量,id2为结构名
 * */
int isEqualStruct(char* id1,char* id2,int op)
{
    int flag = 0;
    unsigned int hash1 = 0;
    unsigned int hash2 = 0;
    _pStructTable temp1 = NULL,temp2 = NULL;
    _pVarTable vtemp1 = NULL,vtemp2 = NULL;
    if(exitVar(id1)){
        if(currentVar->type->kind == 3){
            hash1 = hashcalc(currentVar->type->typeSys.structId);
        }
        else if(currentVar->type->kind == 4){
            hash1 = hashcalc(currentVar->type->typeSys.array.elem->structId);
        }
        currentVar = NULL;
    }
    if(op == 1){
        hash2 = hashcalc(id2);
    }
    else if(exitVar(id2)){
        if(currentVar->type->kind == 3){
            hash2 = hashcalc(currentVar->type->typeSys.structId);
        }
        else if(currentVar->type->kind == 4){
            hash2 = hashcalc(currentVar->type->typeSys.array.elem->structId);
        }
        currentVar = NULL;
    }
    if(hash1 == hash2){//同名结构
        return 1;
    }
    temp1 = HashHead[hash1].structHead;
    temp2 = HashHead[hash2].structHead;
    if(temp1)
        vtemp1 = temp1->head;
    if(temp2)
        vtemp2 = temp2->head;
    if(vtemp1 && vtemp2 && (temp1->memnum == temp2->memnum)){
        while(vtemp1){
            vtemp2 = temp2->head;
            while(vtemp2){
                if(isEqualVar(vtemp1,vtemp2)){
                    flag = 1;
                    break;
                }
                vtemp2 = vtemp2->next;
            }
            if(flag){
                flag = 0;
            }
            else return 0;
            vtemp1 = vtemp1->next;
        }
        return 1;
    }
    return 0;
}

/*新增加一个函数定义*/
void addFunc(_pFuncTable pf)
{
    unsigned int hash = hashcalc(pf->funName);
    _pFuncTable temp = HashHead[hash].funHead;
    if(pf->next)
        pf->next = NULL;
    if(!temp){
        HashHead[hash].funHead = pf;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = pf;
}



/*判断函数是否存在
 * id--标志符名称
 * 0--不存在
 * 1--存在
 * */
int exitFunc(char *id)
{
    unsigned int hash = hashcalc(id);
    _pFuncTable temp =HashHead[hash].funHead;
    while(temp){
        if(!strcmp(temp->funName,id)){
            currentFunc = temp;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

/*
 * 返回函数的返回类型
 * */
_pExpType FuncBackType(char *id)
{
    unsigned int hash = hashcalc(id);
    _pExpType pt = NULL;
    _pFuncTable temp = HashHead[hash].funHead;
    while(temp){
        if(!strcmp(temp->funName,id)){//找到该函数
            pt = (_pExpType)malloc(sizeof(_ExpType));
            pt->kind = temp->kind;
            if(temp->kind == 3){
                strcpy(pt->id,temp->backName);
            }
            currentFunc2 = temp;
            return pt;
        }
        temp = temp->next;
    }
    return NULL;
}

/*返回结构体内部成员的类型*/
_pExpType StructBackType(char *sname,char *memName)
{
    unsigned int hash = hashcalc(sname);
    _pExpType pt = NULL;
    _pStructTable temp = HashHead[hash].structHead;
    _pVarTable tempVar = NULL;
    while(temp){
        if(!strcmp(temp->structName,sname)){//找到该结构
            tempVar = temp->head;
            while(tempVar){
                if(!strcmp(tempVar->id,memName)){//找到该数据成员
                    pt = (_pExpType)malloc(sizeof(_ExpType));
                    switch(tempVar->type->kind){
                        case 1:
                            pt->kind = tempVar->type->typeSys.basic;
                            break;
                        case 2:
                            if(tempVar->type->typeSys.array.lat == arrayLat)
                                pt->kind = tempVar->type->typeSys.array.elem->basic;
                            else
                                pt->kind = 3 + tempVar->type->typeSys.array.elem->basic + (tempVar->type->typeSys.array.lat << 4);
                            break;
                        case 3:
                            pt->kind = 3;
                            strcpy(pt->id,tempVar->type->typeSys.structId);
                            break;
                        case 4:
                            if(tempVar->type->typeSys.array.lat == arrayLat)
                                pt->kind = 3;
                            else
                                pt->kind = 3 + tempVar->type->typeSys.array.elem->basic + (tempVar->type->typeSys.array.lat << 4);
                            strcpy(pt->id,tempVar->type->typeSys.array.elem->structId);
                            break;
                        default:
                            printf("error!\n");
                    }
                    return pt;
                }
                tempVar = tempVar->next;
            }
        }
        temp = temp->next;
    }
    return NULL;
}

/*
 * 返回变量的类型
 * */
_pExpType VarBackType(char *vname)
{
    _pExpType pt = NULL;
    _pVarTable temp;
    if(currentVar && !strcmp(currentVar->id,vname))
        temp = currentVar;
    else if(exitVar(vname)){
        temp = currentVar;
    }
    else{
        return pt;
    }
    pt = (_pExpType)malloc(sizeof(_ExpType));
    if(temp && !strcmp(temp->id,vname)){
        switch(temp->type->kind){
            case 1:
                pt->kind = temp->type->typeSys.basic;
                break;
            case 2:
                if(temp->type->typeSys.array.lat == arrayLat)
                    pt->kind = temp->type->typeSys.array.elem->basic;
                else
                    pt->kind = 3 + temp->type->typeSys.array.elem->basic + (temp->type->typeSys.array.lat << 4);
                break;
            case 3:
                pt->kind = 3;
                strcpy(pt->id,temp->type->typeSys.structId);
                break;
            case 4:
                if(temp->type->typeSys.array.lat == arrayLat)
                    pt->kind = 3;
                else
                    pt->kind = 3 + temp->type->typeSys.array.elem->basic + (temp->type->typeSys.array.lat << 4);
                strcpy(pt->id,temp->type->typeSys.array.elem->structId);
                break;
            default:
                printf("error!\n");
        }
        return pt;
    }
    return NULL;
}

/*获取数组的维度*/
void GetLat(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"LB")){
                ++arrayLat2;
            }
        }
        GetLat(currentNode->lchild);
        GetLat(currentNode->rchild);
    }
}

/*打印函数符号表*/
void PrintFunSimbol()
{
    int i = 0;
    int fnum = 0; //记录函数的编号
    int vnum = 0; //记录局部变量数目
    _pFuncTable tempfunc = NULL;
    _pVarTable tempVar = NULL;
    for(i = 0; i < TABLE_MAX; ++i){
        if(HashHead[i].funHead){
            tempfunc = HashHead[i].funHead;
            while(tempfunc){
                if(fnum==0){
                    fprintf(fseman,"\n>>函数符号表<<\n");
                }
                fprintf(fseman,"\n[[%d]]\n",++fnum);
                fprintf(fseman,"返回类型");
                switch(tempfunc->kind){//打印返回类型
                    case 1://返回类型为int
                        fprintf(fseman,"int\n");
                        break;
                    case 2:
                        fprintf(fseman,"float\n");
                        break;
                    case 3:
                        fprintf(fseman,"struct %s\n",tempfunc->backName);
                        break;
                    default:
                        fprintf(fseman,"error!\n");
                }
                fprintf(fseman,"函数名>>%s\n",tempfunc->funName);//打印函数名
                //打印参数列表
                fprintf(fseman,"形参>>");
                tempVar = tempfunc->paraHead;
                if(!tempVar){
                    fprintf(fseman,"无!\n");
                }
                while(tempVar){
                    switch(tempVar->type->kind){
                        case 1://int or float
                            if(tempVar->type->typeSys.basic == 1)
                                fprintf(fseman," <int %s>",tempVar->id);
                            else
                                fprintf(fseman," <float %s>",tempVar->id);
                            break;
                        case 2://普通数组
                            if(tempVar->type->typeSys.array.elem->basic == 1)
                                fprintf(fseman," <int %d %s>",tempVar->type->typeSys.array.lat,tempVar->id);
                            else
                                fprintf(fseman," <float %d %s>",tempVar->type->typeSys.array.lat,tempVar->id);
                            break;
                        case 3://结构
                            fprintf(fseman," <struct %s %s>",tempVar->type->typeSys.structId,tempVar->id);
                            break;
                        case 4://结构数组
                            fprintf(fseman," <struct %s %d %s>",tempVar->type->typeSys.array.elem->structId,tempVar->type->typeSys.array.lat,tempVar->id);
                            break;
                        default:
                            fprintf(fseman," <error!>");
                    }
                    tempVar = tempVar->next;
                }
                printf("\n");
                //打印当前函数下的局部变量
                fprintf(fseman,">Local Var<\n");
                tempVar = tempfunc->localHead;
                if(!tempVar){
                    fprintf(fseman,"无!\n");
                }
                while(tempVar){
                    fprintf(fseman,"[%d]>>",++vnum);
                    switch(tempVar->type->kind){
                        case 1://int or float
                            if(tempVar->type->typeSys.basic == 1)
                                fprintf(fseman," <int %s>\n",tempVar->id);
                            else
                                fprintf(fseman," <float %s>\n",tempVar->id);
                            break;
                        case 2://普通数组
                            if(tempVar->type->typeSys.array.elem->basic == 1)
                                fprintf(fseman," <int %d %s>\n",tempVar->type->typeSys.array.lat,tempVar->id);
                            else
                                fprintf(fseman," <float %d %s>\n",tempVar->type->typeSys.array.lat,tempVar->id);
                            break;
                        case 3://结构
                            fprintf(fseman," <struct %s %s>\n",tempVar->type->typeSys.structId,tempVar->id);
                            break;
                        case 4://结构数组
                            fprintf(fseman," <struct %s %d %s>\n",tempVar->type->typeSys.array.elem->structId,tempVar->type->typeSys.array.lat,tempVar->id);
                            break;
                        default:
                            fprintf(fseman," <error!>\n");
                    }
                    tempVar = tempVar->next;
                }
                tempfunc = tempfunc->next;
            }
        }
    }
}

/*打印结构符号表*/
void PrintStructSimbol()
{
    int i = 0;
    int snum = 0; //记录结构的编号
    _pStructTable tempStruct = NULL;
    _pVarTable tempVar = NULL;
    for(i = 0; i < TABLE_MAX; ++i){
        if(HashHead[i].structHead){
            tempStruct = HashHead[i].structHead;
            while(tempStruct){
                if(!snum){
                    fprintf(fseman,"\n>>结构符号表<<\n");
                }
                fprintf(fseman,"\n[[%d]]\n",++snum);
                fprintf(fseman,"结构名>> %s\n",tempStruct->structName);
                //打印参数列表
                fprintf(fseman,"结构成员>>");
                tempVar = tempStruct->head;
                if(!tempVar){
                    fprintf(fseman,"无!\n");
                }
                while(tempVar){
                    switch(tempVar->type->kind){
                        case 1://int or float
                            if(tempVar->type->typeSys.basic == 1)
                                fprintf(fseman," <int %s>",tempVar->id);
                            else
                                fprintf(fseman," <float %s>",tempVar->id);
                            break;
                        case 2://普通数组
                            if(tempVar->type->typeSys.array.elem->basic == 1)
                                fprintf(fseman," <int %d %s>",tempVar->type->typeSys.array.lat,tempVar->id);
                            else
                                fprintf(fseman," <float %d %s>",tempVar->type->typeSys.array.lat,tempVar->id);
                            break;
                        case 3://结构
                            fprintf(fseman," <struct %s %s>",tempVar->type->typeSys.structId,tempVar->id);
                            break;
                        case 4://结构数组
                            fprintf(fseman," <struct %s %d %s>",tempVar->type->typeSys.array.elem->structId,tempVar->type->typeSys.array.lat,tempVar->id);
                            break;
                        default:
                            fprintf(fseman," <error!>");
                    }
                    tempVar = tempVar->next;
                }
                fprintf(fseman,"\n");
                tempStruct = tempStruct->next;
            }
        }
    }
}

/*打印变量符号表*/
void PrintVarSimbol()
{
    int i = 0;
    int vnum = 0; //记录结构的编号
    _pVarTable tempVar = NULL;
    for(i = 0; i < TABLE_MAX; ++i){
        if(HashHead[i].varHead){
            tempVar = HashHead[i].varHead;
            while(tempVar){
                if(!vnum)
                    fprintf(fseman,"\n>>全局变量符号表<<\n");
                fprintf(fseman,"[%d]",++vnum);
                switch(tempVar->type->kind){
                    case 1://int or float
                        if(tempVar->type->typeSys.basic == 1)
                            fprintf(fseman," <int %s>\n",tempVar->id);
                        else
                            fprintf(fseman," <float %s>\n",tempVar->id);
                        break;
                    case 2://普通数组
                        if(tempVar->type->typeSys.array.elem->basic == 1)
                            fprintf(fseman," <int %d %s>\n",tempVar->type->typeSys.array.lat,tempVar->id);
                        else
                            fprintf(fseman," <float %d %s>\n",tempVar->type->typeSys.array.lat,tempVar->id);
                        break;
                    case 3://结构
                        fprintf(fseman," <struct %s %s>\n",tempVar->type->typeSys.structId,tempVar->id);
                        break;
                    case 4://结构数组
                        fprintf(fseman," <struct %s %d %s>\n",tempVar->type->typeSys.array.elem->structId,tempVar->type->typeSys.array.lat,tempVar->id);
                        break;
                    default:
                        fprintf(fseman," <error!>\n");
                }
                tempVar = tempVar->next;
            }
        }
    }
}

/*打印错误
 * s--字符串
 * op-- 错误号
 * line-- 出错的行号
 * */
void PrintError(int op,int line,char *s)
{
    if(TransToggle){
        TransToggle = 0;
    }
    switch(op){
        case 1:
            printf("Error type %d at Line %d: Undefined variable '%s'.\n",op,line,s);
            break;
        case 2:
            printf("Error type %d at Line %d: Undefined function '%s'.\n",op,line,s);
            break;
        case 3:
            printf("Error type %d at Line %d: Redefined variable '%s'.\n",op,line,s);
            break;
        case 4:
            printf("Error type %d at Line %d: Redefined function '%s'.\n",op,line,s);
            break;
        case 5:
            printf("Error type %d at Line %d: Type mismatched for assignment.\n",op,line);
            break;
        case 6:
            printf("Error type %d at Line %d: The left-hand side of an assignment must be a variable.\n",op,line);
            break;
        case 7:
            printf("Error type %d at Line %d: Type mismatched for operands.\n",op,line);
            break;
        case 8:
            printf("Error type %d at Line %d: Type mismatched for return.\n",op,line);
            break;
        case 9:
            printf("Error type %d at Line %d: Function is not applicable for arguments.\n",op,line);
            break;
        case 10:
            printf("Error type %d at Line %d: '%s' is not an array.\n",op,line,s);
            break;
        case 11:
            printf("Error type %d at Line %d: '%s' is not a function.\n",op,line,s);
            break;
        case 12:
            printf("Error type %d at Line %d: '%s' is not an integer.\n",op,line,s);
            break;
        case 13:
            printf("Error type %d at Line %d: Illegal use of '.'.\n",op,line);
            break;
        case 14:
            printf("Error type %d at Line %d: Non-existent field '%s'.\n",op,line,s);
            break;
        case 15:
            printf("Error type %d at Line %d: Redefined field '%s'.\n",op,line,s);
            break;
        case 16:
            printf("Error type %d at Line %d: Duplicated name '%s'.\n",op,line,s);
            break;
        case 17:
            printf("Error type %d at Line %d: Undefined structure '%s'.\n",op,line,s);
            break;
        default:
            printf("op error!\n");
            break;
    }
}
