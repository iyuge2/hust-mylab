#include"trans.h"

int gVarNum = 1;//全局变量编号
int VarNum = 1;//局部变量编号
int tNum = 1;//临时变量编号
int tIdNum = 0;//存放变量的临时编号
int labelNum = 1;//存放标签号
_pFuncTable currFunc = NULL;
_pLabelList currentLabel = NULL;
_ArrayLat tempLat;

void translate()
{
    translate_gVar();//翻译全局变量
    GetMiddleCode(grammaTreeHead);
}

void GetMiddleCode(GrammaNode* currentNode)
{
    if(currentNode){
        if(currentNode->currentLine != -1){
            if(!strcmp(currentNode->name,"ExtDef") && currentNode->rulenum == 5){
                GrammaNode* tempFunc = currentNode->lchild->rchild;
                fprintf(ftrans,"FUNCTION %s :\n",tempFunc->idType);
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
                fprintf(ftrans,"\n");
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
    _pVarTable tVar = NULL;
    for(i = 0;i < TABLE_MAX;++i){
        if(HashHead[i].varHead){
            tVar = HashHead[i].varHead;
            while(tVar){
                tVar->num = -gVarNum;
                fprintf(ftrans,"DEC gv%d %d\n",gVarNum++,GetVarSize(tVar));
                tVar = tVar->next;
            }
        }
    }
}

/*翻译函数参数*/
void translate_param(_pFuncTable tFunc)
{
    _pVarTable tVar = tFunc->paraHead;
    while(tVar){
        tVar->num = VarNum;
        fprintf(ftrans,"PARAM v%d %d\n",VarNum++,GetVarSize(tVar));
        tVar = tVar->next;
    }
}

/*翻译函数的局部变量*/
void translate_localVar(_pFuncTable tFunc)
{
    _pVarTable tVar = tFunc->localHead;
    while(tVar){
        tVar->num = VarNum;
        fprintf(ftrans,"DEC v%d %d\n",VarNum++,GetVarSize(tVar));
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
                        fprintf(ftrans,"RETURN %s\n",tempNode->rchild->trans);
                        break;
                    case 4://IF LP Exp RP Stmt
                    case 5://IF LP Exp RP Stmt ELSE Stmt
                        AddLabel();//新建一个标签域
                        translate_exp(tempNode->rchild->rchild);
                        fprintf(ftrans,"IF %s GOTO label%d\n",tempNode->rchild->rchild->trans,labelNum++);
                        addALabel(labelNum-1);
                        fprintf(ftrans,"GOTO label%d\n",labelNum++);
                        addALabel(labelNum-1);
                        fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        translate_stmt(tempNode->rchild->rchild->rchild->rchild);
                        if(currentNode->rulenum == 5){
                            fprintf(ftrans,"GOTO label%d\n",labelNum++);
                            addALabel(labelNum-1);
                            fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                            translate_stmt(tempNode->rchild->rchild->rchild->rchild->rchild->rchild);
                            fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        }
                        else{
                            fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        }
                        DestoryLabel();//删除当前标签域
                        currentNode = currentNode->rchild;
                        break;
                    case 6://WHILE LP Exp RP Stmt
                        AddLabel();//新建一个标签域
                        fprintf(ftrans,"LABEL label%d :\n",labelNum++);
                        currentLabel->whileNum = labelNum - 1;
                        translate_exp(tempNode->rchild->rchild);
                        fprintf(ftrans,"IF %s GOTO label%d\n",tempNode->rchild->rchild->trans,labelNum++);
                        addALabel(labelNum-1);
                        fprintf(ftrans,"GOTO label%d\n",labelNum++);
                        addALabel(labelNum-1);
                        fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
                        translate_stmt(tempNode->rchild->rchild->rchild->rchild);
                        fprintf(ftrans,"GOTO label%d\n",currentLabel->whileNum);
                        fprintf(ftrans,"LABEL label%d :\n",deleteALabel());
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
                        fprintf(ftrans,"%s := %s\n",tempNode->trans,tempNode->rchild->rchild->trans);
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
                                sprintf(currentNode->trans,"%s > %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 2:
                                sprintf(currentNode->trans,"%s < %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 3:
                                sprintf(currentNode->trans,"%s >= %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 4:
                                sprintf(currentNode->trans,"%s <= %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 5:
                                sprintf(currentNode->trans,"%s == %s",tempNode->trans,tempNode->rchild->rchild->trans);
                                break;
                            case 6:
                                sprintf(currentNode->trans,"%s != %s",tempNode->trans,tempNode->rchild->rchild->trans);
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
                        fprintf(ftrans,"t%d := %s + %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 6://Exp MINUS Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        fprintf(ftrans,"t%d := %s - %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 7://Exp STAR Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        fprintf(ftrans,"t%d := %s * %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 8://Exp DIV Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        fprintf(ftrans,"t%d := %s / %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 9://Exp MOD Exp
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        fprintf(ftrans,"t%d := %s / %s\n",tNum,tempNode->trans,tempNode->rchild->rchild->trans);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 10://LP Exp RP
                        translate_exp(tempNode->rchild);
                        strcpy(currentNode->trans,tempNode->rchild->trans);
                        return;
                    case 11://MINUS Exp
                        translate_exp(tempNode->rchild);
                        fprintf(ftrans,"t%d := #0 - %s\n",tNum,tempNode->rchild->trans);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        return;
                    case 13://ID LP Args RP
                    case 14://ID LP RP
                        if(currentNode->rulenum == 13)
                            translate_args(currentNode->lchild->rchild->rchild);//翻译函数参数
                        fprintf(ftrans,"t%d := CALL %s\n",tNum,tempNode->idType);
                        sprintf(currentNode->trans,"t%d",tNum++);
                        break;
                    case 15://Exp LB Exp RB
                        translate_exp(tempNode);
                        translate_exp(tempNode->rchild->rchild);
                        if(tempNode->type == -1){
                            fprintf(ftrans,"t%d := *%s\n",tNum++,tempNode->trans);
                        }
                        return;
                    case 16://Exp DOT ID
                    case 17://ID
                        tIdNum = GetVarNum(tempNode->idType);
                        if(tIdNum > 0){
                            sprintf(currentNode->trans,"v%d",tIdNum);
                        }
                        else{
                            sprintf(currentNode->trans,"gv%d",tIdNum);
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
            fprintf(ftrans,"ARG %s\n",currentNode->lchild->trans);
            translate_args(currentNode->lchild->rchild->rchild);
            return;
        }
        else{//Exp
            translate_exp(currentNode->lchild);
            fprintf(ftrans,"ARG %s\n",currentNode->lchild->trans);
            return;
        }
    }
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
