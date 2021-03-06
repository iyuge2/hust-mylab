#include"trans.h"

int gVarNum = 1;//全局变量编号
int VarNum = 1;//局部变量编号
int tNum = 1;//临时变量编号
int tIdNum = 0;//存放变量的临时编号
int labelNum = 1;//存放标签号
int arrayAddr = 0,structAddr = 0;
_pFuncTable currFunc = NULL;
_pLabelList currentLabel = NULL;
_ArrayLat tempLat;
_pMiddleCode CodeHead = NULL;//四元组链表头指针
_pMiddleCode currentCode = NULL;//指向当前四元组
_MiddleCode tCode;

void translate()
{
    printf("未检测到语义错误!\n");
    printf("开始生成中间代码...\n");
    translate_gVar();//翻译全局变量
    GetMiddleCode(grammaTreeHead);
    PrintCode();//打印中间代码
    printf("...中间代码生成完毕\n");
}

void GetMiddleCode(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"ExtDef") && currentNode->rulenum == 5){
                GrammaNode* tempFunc = currentNode->lchild->rchild;
                //fprintf(ftrans,"FUNCTION %s :\n",tempFunc->idType);
                tCode.kind = 6;
                sprintf(tCode.id1,"%s",tempFunc->idType);
                AddACode();
                unsigned int hash = hashcalc(tempFunc->idType);
                currFunc = HashHead[hash].funHead;
                while(currFunc){//找到当前函数
                    if(!strcmp(currFunc->funName,tempFunc->idType)){
                        break;
                    }
                    currFunc = currFunc->next;
                }
                if(currFunc){
                    if(currFunc->paraHead)
                        translate_param(currFunc);//打印函数参数
                    if(currFunc->localHead)
                        translate_localVar(currFunc);//翻译函数的局部变量
                    translate_stmt(currentNode->lchild->rchild->rchild->lchild->rchild->rchild->lchild);//翻译语句
                }
                //fprintf(ftrans,"\n");
                tCode.kind = 7;
                AddACode();
                if(currentNode->rchild)
                    currentNode = currentNode->rchild;
            }
        }
        GetMiddleCode(currentNode->lchild);
        GetMiddleCode(currentNode->rchild);
    }
}

/*翻译所有的全局变量*/
void translate_gVar()
{
    int i = 0;
    int flag = 0;
    _pVarTable tVar = NULL;
    for(i = 0;i < TABLE_MAX;++i){
        if(HashHead[i].varHead){
            tVar = HashHead[i].varHead;
            while(tVar){
                tVar->num = -gVarNum;
                //fprintf(ftrans,"DEC gv%d %d\n",gVarNum++,GetVarSize(tVar));
                tCode.kind = 3;
                sprintf(tCode.id1,"gv%d",gVarNum++);
                sprintf(tCode.id2,"%d",GetVarSize(tVar));
                AddACode();
                if(!flag)
                    flag = 1;
                tVar = tVar->next;
            }
        }
    }
    if(flag){
        tCode.kind = 7;
        AddACode();
    }
}

/*翻译函数参数*/
void translate_param(_pFuncTable tFunc)
{
    _pVarTable tVar = tFunc->paraHead;
    while(tVar){
        tVar->num = VarNum;
        //fprintf(ftrans,"PARAM v%d %d\n",VarNum++,GetVarSize(tVar));
        tCode.kind = 4;
        sprintf(tCode.id1,"v%d",VarNum++);
        sprintf(tCode.id2,"v%d",GetVarSize(tVar));
        AddACode();
        tVar = tVar->next;
    }
}

/*翻译函数的局部变量*/
void translate_localVar(_pFuncTable tFunc)
{
    _pVarTable tVar = tFunc->localHead;
    while(tVar){
        tVar->num = VarNum;
        //fprintf(ftrans,"DEC v%d %d\n",VarNum++,GetVarSize(tVar));
        tCode.kind = 3;
        sprintf(tCode.id1,"v%d",gVarNum++);
        sprintf(tCode.id2,"%d",GetVarSize(tVar));
        AddACode();
        tVar = tVar->next;
    }
}

/*翻译函数内的语句*/
void translate_stmt(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Stmt")){
                GrammaNode* tempNode = currentNode->lchild;
                switch(currentNode->rulenum){
                    case 1://Exp SEMI
                        translate_exp(currentNode);
                        break;
                    case 2://Compst
                        translate_stmt(tempNode->lchild->rchild->rchild->lchild);
                        return;
                    case 3://RETURN Exp SEMI
                        translate_exp(tempNode->rchild);
                        //fprintf(ftrans,"RETURN %s\n",tempNode->rchild->trans);
                        tCode.kind = 5;
                        sprintf(tCode.id1,"%s",tempNode->rchild->trans);
                        AddACode();
                        break;
                    case 4://IF LP Exp RP Stmt
                    case 5://IF LP Exp RP Stmt ELSE Stmt
                        AddLabel();//新建一个标签域
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"IF %s GOTO label%d\n",tempNode->rchild->rchild->trans,labelNum++);
                        tCode.kind = 2;
                        sprintf(tCode.id1,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.id2,"label%d",labelNum++);
                        AddACode();
                        addALabel(labelNum-1);
                        //fprintf(ftrans,"GOTO label%d\n",labelNum++);
                        tCode.kind = 8;
                        sprintf(tCode.id1,"label%d",labelNum++);
                        AddACode();
                        addALabel(labelNum-1);
                        //fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        tCode.kind = 9;
                        sprintf(tCode.id1,"label%d",deleteALabel());
                        AddACode();
                        translate_stmt(tempNode->rchild->rchild->rchild->rchild);
                        if(currentNode->rulenum == 5){
                            //fprintf(ftrans,"GOTO label%d\n",labelNum++);
                            tCode.kind = 8;
                            sprintf(tCode.id1,"label%d",labelNum++);
                            AddACode();
                            addALabel(labelNum-1);
                            //fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                            tCode.kind = 9;
                            sprintf(tCode.id1,"label%d",deleteALabel());
                            AddACode();
                            translate_stmt(tempNode->rchild->rchild->rchild->rchild->rchild->rchild);
                            //fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                            tCode.kind = 9;
                            sprintf(tCode.id1,"label%d",deleteALabel());
                            AddACode();
                        }
                        else{
                            //fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                            tCode.kind = 9;
                            sprintf(tCode.id1,"label%d",deleteALabel());
                            AddACode();
                        }
                        DestoryLabel();//删除当前标签域
                        currentNode = currentNode->rchild;
                        break;
                    case 6://WHILE LP Exp RP Stmt
                        AddLabel();//新建一个标签域
                        //fprintf(ftrans,"LABEL label%d :\n",labelNum++);
                        tCode.kind = 9;
                        sprintf(tCode.id1,"label%d",labelNum++);
                        AddACode();
                        currentLabel->whileNum = labelNum - 1;
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"IF %s GOTO label%d\n",tempNode->rchild->rchild->trans,labelNum++);
                        tCode.kind = 2;
                        sprintf(tCode.id1,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.id2,"label%d",labelNum++);
                        AddACode();
                        addALabel(labelNum-1);
                        //fprintf(ftrans,"GOTO label%d\n",labelNum++);
                        tCode.kind = 9;
                        sprintf(tCode.id1,"label%d",labelNum++);
                        AddACode();
                        addALabel(labelNum-1);
                        //fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        tCode.kind = 9;
                        sprintf(tCode.id1,"label%d",deleteALabel());
                        AddACode();
                        translate_stmt(tempNode->rchild->rchild->rchild->rchild);
                        //fprintf(ftrans,"GOTO label%d\n",currentLabel->whileNum);
                        tCode.kind = 8;
                        sprintf(tCode.id1,"label%d",currentLabel->whileNum);
                        AddACode();
                        //fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        tCode.kind = 9;
                        sprintf(tCode.id1,"label%d",deleteALabel());
                        AddACode();
                        DestoryLabel();//删除当前标签域
                        currentNode = currentNode->rchild;
                        break;
                    default:
                        break;
                }
            }
        }
        translate_stmt(currentNode->lchild);
        translate_stmt(currentNode->rchild);
    }
}

/*翻译表达式*/
void translate_exp(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"Exp")){
                GrammaNode* tempNode = currentNode->lchild;
                switch(currentNode->rulenum){
                    case 1://Exp ASSIGNOP Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"%s := %s\n",tempNode->trans,tempNode->rchild->rchild->trans);
                        tCode.kind = 0;
                        sprintf(tCode.id1,"%s",tempNode->trans);
                        sprintf(tCode.id2,"%s",tempNode->rchild->rchild->trans);
                        AddACode();
                        return;
                    case 2://Exp AND Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        sprintf(currentNode->trans,"%s && %s",tempNode->trans,tempNode->rchild->rchild->trans);
                        return;
                    case 3://Exp OR Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        sprintf(currentNode->trans,"%s || %s",tempNode->trans,tempNode->rchild->rchild->trans);
                        return;
                    case 4://Exp RELOP Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        switch(tempNode->rchild->relop){
                            case 1:
                                sprintf(currentNode->trans,"1%s > %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 2:
                                sprintf(currentNode->trans,"2%s < %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 3:
                                sprintf(currentNode->trans,"3%s >= %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 4:
                                sprintf(currentNode->trans,"4%s <= %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 5:
                                sprintf(currentNode->trans,"5%s == %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 6:
                                sprintf(currentNode->trans,"6%s != %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            default:
                                break;
                        }
                        return;
                    case 12://NOT Exp
                        translate_exp(tempNode->rchild);
                        sprintf(currentNode->trans,"!%s",tempNode->rchild->trans);
                        return;
                    case 5://Exp PLUS Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"t%d := %s + %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        tCode.kind = 1;
                        tCode.op = '+';
                        sprintf(tCode.id1,"%s",tempNode->trans);
                        sprintf(tCode.id2,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 6://Exp MINUS Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"t%d := %s - %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        tCode.kind = 1;
                        tCode.op = '-';
                        sprintf(tCode.id1,"%s",tempNode->trans);
                        sprintf(tCode.id2,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 7://Exp STAR Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"t%d := %s * %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        tCode.kind = 1;
                        tCode.op = '*';
                        sprintf(tCode.id1,"%s",tempNode->trans);
                        sprintf(tCode.id2,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 8://Exp DIV Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"t%d := %s / %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        tCode.kind = 1;
                        tCode.op = '/';
                        sprintf(tCode.id1,"%s",tempNode->trans);
                        sprintf(tCode.id2,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 9://Exp MOD Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        //fprintf(ftrans,"t%d := %s / %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        tCode.kind = 1;
                        tCode.op = '%';
                        sprintf(tCode.id1,"%s",tempNode->trans);
                        sprintf(tCode.id2,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 10://LP Exp RP
                        translate_exp(tempNode->rchild);
                        strcpy(currentNode->trans,tempNode->rchild->trans);
                        return;
                    case 11://MINUS Exp
                        translate_exp(tempNode->rchild);
                        //fprintf(ftrans,"t%d := #0 - %s\n",tNum,tempNode->rchild->trans);
                        tCode.kind = 10;
                        sprintf(tCode.id1,"t%d",tNum);
                        sprintf(tCode.id2,"%s",tempNode->rchild->trans);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 13://ID LP Args RP
                    case 14://ID LP RP
                        if(currentNode->rulenum == 13)
                            translate_args(currentNode->lchild->rchild->rchild);//翻译函数参数
                        //fprintf(ftrans,"t%d := CALL %s\n",tNum,tempNode->idType);
                        tCode.kind = 11;
                        sprintf(tCode.id1,"t%d",tNum);
                        sprintf(tCode.id2,"%s",tempNode->idType);
                        AddACode();
                        sprintf(currentNode->trans,"t%d",tNum++);
                        break;
                    case 15://Exp LB Exp RB
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        if(tempNode->type == -1){
                            //fprintf(ftrans,"t%d := &%s\n",tNum++,tempNode->trans);
                            tCode.kind = 0;
                            sprintf(tCode.id1,"t%d",tNum++);
                            sprintf(tCode.id2,"&%s",tempNode->trans);
                            AddACode();
                        }
                        arrayAddr = GetArrayAddr(tempNode);
                        //fprintf(ftrans,"t%d := %s * #%d\n",tNum++,tempNode->rchild->rchild->trans,arrayAddr);
                        tCode.kind = 1;
                        tCode.op = '*';
                        sprintf(tCode.id1,"%s",tempNode->rchild->rchild->trans);
                        sprintf(tCode.id1,"#%d",arrayAddr);
                        sprintf(tCode.res,"t%d",tNum++);
                        AddACode();
                        //fprintf(ftrans,"t%d := t%d + t%d\n",tNum,tNum-1,tNum-2);
                        tCode.kind = 1;
                        tCode.op = '+';
                        sprintf(tCode.id1,"t%d",tNum-1);
                        sprintf(tCode.id1,"t%d",tNum-2);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"*t%d",tNum++);
                        return;
                    case 16://Exp DOT ID
                        translate_exp(tempNode);
                        if(tempNode->type == -1){
                            //fprintf(ftrans,"t%d := &%s\n",tNum++,tempNode->trans);
                            tCode.kind = 0;
                            sprintf(tCode.id1,"t%d",tNum++);
                            sprintf(tCode.id2,"&%s",tempNode->trans);
                            AddACode();
                        }
                        structAddr = GetStructAddr(tempNode->idType,tempNode->rchild->rchild->idType);
                        //fprintf(ftrans,"t%d := t%d + #%d\n",tNum,tNum-1,structAddr);
                        tCode.kind = 1;
                        tCode.op = '+';
                        sprintf(tCode.id1,"t%d",tNum-1);
                        sprintf(tCode.id1,"#%d",structAddr);
                        sprintf(tCode.res,"t%d",tNum);
                        AddACode();
                        sprintf(currentNode->trans,"*t%d",tNum++);
                        return;
                    case 17://ID
                        tIdNum = GetVarNum(tempNode->idType);
                        if(tIdNum > 0){
                            sprintf(currentNode->trans,"v%d",tIdNum);
                        }
                        else{
                            sprintf(currentNode->trans,"gv%d",-tIdNum);
                        }
                        currentNode->type = -1;
                        break;
                    case 18://INT
                        //fprintf(ftrans,"t%d := #%d\n",tNum,tempNode->integer);
                        sprintf(currentNode->trans,"#%d",tempNode->integer);
                        currentNode->integer = tempNode->integer;
                        break;
                    case 19://FLOAT
                        //fprintf(ftrans,"t%d := #%.2f\n",tNum,tempNode->fnum);
                        sprintf(currentNode->trans,"#%.2f",tempNode->fnum);
                        break;
                }
            }
        }
        translate_exp(currentNode->lchild);
    }
}

/*翻译函数参数*/
void translate_args(GrammaNode* currentNode)
{
    if(!strcmp(currentNode->name,"Args")){
        if(currentNode->rulenum == 1){//Exp COMMA Args
            translate_exp(currentNode->lchild);
            //fprintf(ftrans,"ARG %s\n",currentNode->lchild->trans);
            tCode.kind = 12;
            sprintf(tCode.id1,"%s",currentNode->lchild->trans);
            AddACode();
            translate_args(currentNode->lchild->rchild->rchild);
            return;
        }
        else{//Exp
            translate_exp(currentNode->lchild);
            //fprintf(ftrans,"ARG %s\n",currentNode->lchild->trans);
            tCode.kind = 12;
            sprintf(tCode.id1,"%s",currentNode->lchild->trans);
            AddACode();
            return;
        }
    }
}

/*计算并返回数组的地址*/
int GetArrayAddr(GrammaNode* currentNode)
{
    int lat = 0;//记录数组的维度
    int addr = 1;
    int i = 0;
    while(currentNode){
        if(!strcmp(currentNode->name,"Exp")){
            ++lat;
        }
        currentNode = currentNode->lchild;
    }
    for(i = lat;i < tempLat.lat;++i){
        addr *= tempLat.size[i];
    }
    return addr*4;
}

/*计算并返回结构成员的地址*/
int GetStructAddr(char *sname,char *mname)
{
    char *structName = NULL;
    int msize = 0;
    unsigned int hash = 0;
    _pVarTable tVar = NULL;
    _pStructTable tStruct = NULL;
    /*找到该结构体*/
    if(currFunc){
        tVar = currFunc->paraHead;
        while(tVar){//在形参中找
            if(!strcmp(sname,tVar->id)){
                if(tVar->type->kind == 3)//为普通结构
                    structName = tVar->type->typeSys.structId;
                else//为结构数组
                    structName = tVar->type->typeSys.array.elem->structId;
                break;
            }
            tVar = tVar->next;
        }
        if(!structName){//在局部变量中找
            tVar = currFunc->localHead;
            while(tVar){
                if(!strcmp(sname,tVar->id)){
                    if(tVar->type->kind == 3)//为普通结构
                        structName = tVar->type->typeSys.structId;
                    else//为结构数组
                        structName = tVar->type->typeSys.array.elem->structId;
                    break;
                }
                tVar = tVar->next;
            }
        }
        if(!structName){//在全局变量中找
            hash = hashcalc(sname);
            if(HashHead[hash].varHead){
                tVar = HashHead[hash].varHead;
                while(tVar){
                    if(!strcmp(sname,tVar->id)){
                        if(tVar->type->kind == 3)//为普通结构
                            structName = tVar->type->typeSys.structId;
                        else//为结构数组
                            structName = tVar->type->typeSys.array.elem->structId;
                        break;
                    }
                    tVar = tVar->next;
                }
            }
        }
    }
    hash = hashcalc(structName);
    if(HashHead[hash].structHead)
        tStruct = HashHead[hash].structHead;
    while(tStruct){
        if(!strcmp(tStruct->structName,structName)){//找到该结构
            break;
        }
        tStruct = tStruct->next;
    }
    if(tStruct){
        tVar = tStruct->head;
        while(tVar){
            if(!strcmp(tVar->id,mname)){//找到该成员
                return msize;
            }
            msize += GetVarSize(tVar);
            tVar = tVar->next;
        }
    }
    return msize;
}

/*增加一个标签域*/
void AddLabel()
{
    _pLabelList temp = (_pLabelList)malloc(sizeof(_LabelList));
    temp->lenth = 0;
    temp->next = currentLabel;
    currentLabel = temp;
}

/*销毁一个标签域*/
void DestoryLabel()
{
    _pLabelList temp = currentLabel;
    currentLabel = currentLabel->next;
    free(temp);
}

/*在当前标签域中增加一个标签*/
void addALabel(int num)
{
    currentLabel->labelNum[currentLabel->lenth] = num;
    ++currentLabel->lenth;
}

/*
 * 删除第一个标签元素并返回
 * 当前域为空,返回-1
 * */
int deleteALabel()
{
    if(currentLabel->lenth <= 0){
        return -1;
    }
    int temp = currentLabel->labelNum[0];
    int i = 0;
    for(i = 1; i <= currentLabel->lenth;++i){
        currentLabel->labelNum[i-1] = currentLabel->labelNum[i];
    }
    --currentLabel->lenth;
    return temp;
}

/*在链表中增加一个四元组*/
void AddACode()
{
    _pMiddleCode tempCode = (_pMiddleCode)malloc(sizeof(_MiddleCode));
    if(tempCode){
        tempCode->kind = tCode.kind;
        tempCode->op = tCode.op;
        switch(tempCode->kind){
            case 0:
            case 2:
            case 3:
            case 4:
            case 10:
            case 11:
                tempCode->res[0] = '$';
                strcpy(tempCode->id1,tCode.id1);
                strcpy(tempCode->id2,tCode.id2);
                break;
            case 1:
                strcpy(tempCode->id1,tCode.id1);
                strcpy(tempCode->id2,tCode.id2);
                strcpy(tempCode->res,tCode.res);
                break;
            case 5:
            case 6:
            case 8:
            case 9:
            case 12:
                tempCode->id2[0] = '$';
                tempCode->res[0] = '$';
                strcpy(tempCode->id1,tCode.id1);
                break;
            case 7:
                tempCode->res[0] = '$';
                tempCode->id1[0] = '$';
                tempCode->id2[0] = '$';
                break;
            default:
                break;

        }
        tempCode->next = NULL;
        //初始化tCode
        tCode.kind = -1;
        tCode.op = '0';
        sprintf(tCode.id1,"0");
        sprintf(tCode.id2,"0");
        sprintf(tCode.res,"0");
    }
    if(CodeHead == NULL){//加入第一个四元组
        CodeHead = tempCode;
        currentCode = CodeHead;
        return;
    }
    else{
        currentCode->next = tempCode;
        currentCode = tempCode;
    }
}



/*
 * 查询符号表,返回变量的编号,如果是数组,还返回数组的维数以及下标
 * */
int GetVarNum(char* id)
{
    int i = 0;
    _pVarTable tVar = currFunc->paraHead;
    while(tVar){
        if(!strcmp(id,tVar->id)){//在形参中找到该编号
            if(tVar->type->kind == 2 || tVar->type->kind == 4){
                tempLat.lat = tVar->type->typeSys.array.lat;
                for(i = 0; i <tempLat.lat;++i){
                    tempLat.size[i] = tVar->type->typeSys.array.size[i];
                }
            }
            return tVar->num;
        }
        tVar = tVar->next;
    }
    tVar = currFunc->localHead;
    while(tVar){
        if(!strcmp(id,tVar->id)){//在局部变量中找到该编号
            if(tVar->type->kind == 2 || tVar->type->kind == 4){
                tempLat.lat = tVar->type->typeSys.array.lat;
                for(i = 0; i <tempLat.lat;++i){
                    tempLat.size[i] = tVar->type->typeSys.array.size[i];
                }
            }
            return tVar->num;
        }
        tVar = tVar->next;
    }
    unsigned int hash = hashcalc(id);
    tVar = HashHead[hash].varHead;
    while(tVar){
        if(!strcmp(id,tVar->id)){//在全局变量中找到该编号
            if(tVar->type->kind == 2 || tVar->type->kind == 4){
                tempLat.lat = tVar->type->typeSys.array.lat;
                for(i = 0; i <tempLat.lat;++i){
                    tempLat.size[i] = tVar->type->typeSys.array.size[i];
                }
            }
            return tVar->num;
        }
        tVar = tVar->next;
    }
    return 0;
}

/*
 * 计算变量的大小
 * */
int GetVarSize(_pVarTable var)
{
    int i = 0;
    int arraylat = 0;//数组的维度
    int arrayNum = 1;//数组大小
    if(var){
        switch(var->type->kind){
            case 2://普通数组
            case 4://结构数组
                arraylat = var->type->typeSys.array.lat;
                for(i = 0;i < arraylat;i++){
                    arrayNum *= var->type->typeSys.array.size[i];
                }
                if(var->type->kind == 2)
                    arrayNum *= 4;
                else
                    arrayNum *= GetStructSize(var->type->typeSys.array.elem->structId);
                break;
            case 3://结构体
                arrayNum = GetStructSize(var->type->typeSys.structId);
                break;
            default:
                arrayNum *= 4;
                break;
        }
    }
    return arrayNum;
}

/*获取结构体的大小*/
int GetStructSize(char *structId)
{
    int structSize = 0;
    unsigned int hash = hashcalc(structId);
    _pVarTable tVar = NULL;
    _pStructTable pst = HashHead[hash].structHead;
    while(pst){//找到当前结构体
        if(!strcmp(pst->structName,structId)){
            break;
        }
        pst = pst->next;
    }
    if(pst){
        tVar = pst->head;
        while(tVar){
            structSize += GetVarSize(tVar);
            tVar = tVar->next;
        }
    }
    return structSize;
}
/*输出四元组*/
void PrintCode()
{
    _pMiddleCode tempCode = CodeHead;
    while(tempCode){
        switch(tempCode->kind){
            case 0:
                fprintf(ftrans,"%s := %s\n",tempCode->id1,tempCode->id2);
                break;
            case 1:
                fprintf(ftrans,"%s := %s %c %s\n",tempCode->res,tempCode->id1,tempCode->op,tempCode->id2);
                break;
            case 2:
                fprintf(ftrans,"IF %s GOTO %s\n",tempCode->id1,tempCode->id2);
                break;
            case 3:
                fprintf(ftrans,"DEC %s %s\n",tempCode->id1,tempCode->id2);
                break;
            case 4:
                fprintf(ftrans,"PARAM %s %s\n",tempCode->id1,tempCode->id2);
                break;
            case 5:
                fprintf(ftrans,"RETURN %s\n",tempCode->id1);
                break;
            case 6:
                fprintf(ftrans,"FUNCTION %s\n",tempCode->id1);
                break;
            case 7:
                fprintf(ftrans,"\n");
                break;
            case 8:
                fprintf(ftrans,"GOTO %s\n",tempCode->id1);
                break;
            case 9:
                fprintf(ftrans,"LABEL %s :\n",tempCode->id1);
                break;
            case 10:
                fprintf(ftrans,"%s := #0 - %s\n",tempCode->id1,tempCode->id2);
                break;
            case 11:
                fprintf(ftrans,"%s := CALL %s\n",tempCode->id1,tempCode->id2);
                break;
            case 12:
                fprintf(ftrans,"ARG %s\n",tempCode->id1);
                break;
            default:
                fprintf(ftrans,"error!\n");
                break;
        }
        tempCode = tempCode->next;
    }
}
