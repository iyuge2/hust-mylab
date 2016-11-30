/*
 * Author: iyuge2
 * Creat-time: 2016/11/04 13:35
 * Update-time: 2016/11/08 20:39
 * Function: 词法规则的声明
 * */
%{
    #include<stdio.h>
    #include"syntaxTree.h"
    extern int GrammaToggle;
%}

%union{
    struct GrammaNode* node;
    double dnum;
}

%error-verbose
%locations
/*define tokens*/
%token <node> ID
%token <node> TYPE/*float int void*/
%token <node> INT FLOAT/*常量*/
%token <node> STRUCT RETURN IF ELSE WHILE
%token <node> PLUS MINUS STAR DIV MOD/*+ - * / %*/
%token <node> RELOP ASSIGNOP/*< <= > >= == !=, =*/
%token <node> AND OR NOT/*&& || !*/
%token <node> SEMI COMMA DOT LP RP LB RB LC RC/*; , . ( ) [ ] { }*/

%type <node>Program ExtDefList ExtDecList ExtDef
%type <node>Specifier StructSpecifier OptTag Tag
%type <node>VarDec FunDec VarList ParamDec
%type <node>CompSt StmtList Stmt
%type <node>DefList Def DecList Dec
%type <node>Exp Args

/*priority*/
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LP RP LB RB DOT

%nonassoc ELSE

%start Program

%%
Program : ExtDefList
    {
        $$=InsertNode("Program",1,$1);
        $$->rulenum = 1;
        grammaTreeHead = $$;
        if(GrammaToggle){
            printf("开始打印syntax tree...\n");
            eval(grammaTreeHead,0);
            printf("syntax tree 打印完毕!\n");
        }
    }
    ;
ExtDefList : ExtDef ExtDefList {$$=InsertNode("ExtDefList",2,$1,$2);$$->rulenum = 1;}
    |/*empty*/{$$=InsertNode("ExtDefList",0,-1);$$->rulenum = 2;}
    ;
ExtDef : Specifier ExtDecList SEMI {$$=InsertNode("ExtDef",3,$1,$2,$3);$$->rulenum = 1;}
    | StructSpecifier SEMI {$$=InsertNode("ExtDef",2,$1,$2);$$->rulenum = 2;}
    | StructSpecifier ExtDecList SEMI {$$=InsertNode("ExtDef",3,$1,$2,$3);$$->rulenum = 3;}
    | Specifier error SEMI /*获取错误，从中搜取分号，继续执行*/
    | Specifier FunDec SEMI {$$=InsertNode("ExtDef",3,$1,$2,$3);$$->rulenum = 4;}/*允许函数声明*/
    | Specifier FunDec error SEMI
    | Specifier FunDec CompSt {$$=InsertNode("ExtDef",3,$1,$2,$3);$$->rulenum = 5;}
    ;
ExtDecList : VarDec {$$=InsertNode("ExtDecList",1,$1);$$->rulenum = 1;}
    | VarDec COMMA ExtDecList {$$=InsertNode("ExtDecList",3,$1,$2,$3);$$->rulenum = 2;}
    ;
Specifier : TYPE
    {
        $$=InsertNode("Specifier",1,$1);
        $$->rulenum = 1;
        $$->type = $1->type;
    }
    | STRUCT Tag
    {
        $$=InsertNode("Specifier",2,$1,$2);
        strcpy($$->idType,$2->idType);
        $2->lchild->type = 3;
        $$->rulenum = 2;
    }
    ;
StructSpecifier : STRUCT OptTag LC DefList RC
    {
        $$=InsertNode("StructSpecifier",5,$1,$2,$3,$4,$5);
        strcpy($$->idType,$2->idType);
        $$->rulenum = 1;
    }
    | STRUCT OptTag LC DefList error RC
    ;
OptTag : ID
    {
        $$=InsertNode("OptTag",1,$1);
        strcpy($$->idType,$1->idType);
        $$->rulenum = 1;
    }
    | /*empty*/{$$=InsertNode("OptTag",0,-1);}
    ;
Tag : ID
    {
        $$=InsertNode("Tag",1,$1);
        strcpy($$->idType,$1->idType);
        $$->rulenum = 1;
    }
    ;
VarDec : ID {$$=InsertNode("VarDec",1,$1);$$->rulenum = 1;}
    | VarDec LB INT RB {$$=InsertNode("VarDec",4,$1,$2,$3,$4);$$->rulenum = 2;}
    ;
FunDec : ID LP VarList RP
    {
        $$=InsertNode("FunDec",4,$1,$2,$3,$4);$$->rulenum = 1;
        strcpy($$->idType,$1->idType);
        $4->type = -1;//做一个特殊标记
    }
    | ID LP RP
    {
        $$=InsertNode("FunDec",3,$1,$2,$3);
        strcpy($$->idType,$1->idType);
        $$->rulenum = 2;
    }
    ;
VarList : ParamDec COMMA VarList {$$=InsertNode("VarList",3,$1,$2,$3);$$->rulenum = 1;}
    | ParamDec
    {
        $$ = InsertNode("COMMA",0,0);
        $$=InsertNode("VarList",2,$1,$$);
        $$->rulenum = 2;
    }
    ;
ParamDec : Specifier VarDec {$$=InsertNode("ParamDec",2,$1,$2);$$->rulenum = 1;}
    ;
CompSt : LC DefList StmtList RC {$$=InsertNode("CompSt",4,$1,$2,$3,$4);$$->rulenum = 1;$4->type = -1;}
    | LC DefList StmtList error RC
    ;
StmtList : Stmt StmtList {$$=InsertNode("StmtList",2,$1,$2);$$->rulenum = 1;}
    | /*empty*/{$$=InsertNode("StmtList",0,-1);}
Stmt : Exp SEMI {$$=InsertNode("Stmt",2,$1,$2);$$->rulenum = 1;}
    | Exp error SEMI /*获取错误，从中搜取分号，继续执行*/
    | CompSt {$$=InsertNode("Stmt",1,$1);$$->rulenum = 2;}
    | RETURN Exp SEMI {$$=InsertNode("Stmt",3,$1,$2,$3);$$->rulenum = 3;}
    | RETURN Exp error SEMI /*获取错误，从中搜取分号，继续执行*/
    | IF LP Exp RP Stmt {$$=InsertNode("Stmt",5,$1,$2,$3,$4,$5);$$->rulenum = 4;}
    | IF LP Exp RP Stmt ELSE Stmt {$$=InsertNode("Stmt",7,$1,$2,$3,$4,$5,$6,$7);$$->rulenum = 5;}
    | WHILE LP Exp RP Stmt {$$=InsertNode("Stmt",5,$1,$2,$3,$4,$5);$$->rulenum = 6;}
    ;
DefList : Def DefList {$$=InsertNode("DefList",2,$1,$2);$$->rulenum = 1;}
    | /*empty*/{$$=InsertNode("DefList",0,-1);}
    ;
Def : Specifier DecList SEMI{$$=InsertNode("Def",3,$1,$2,$3);$$->rulenum = 1;}
    | Specifier DecList error SEMI /*获取错误，从中搜取分号，继续执行*/
    ;
DecList : Dec {$$=InsertNode("DecList",1,$1);$$->rulenum = 1;}
    | Dec COMMA DecList {$$=InsertNode("DecList",3,$1,$2,$3);$$->rulenum = 2;}
    ;
Dec : VarDec {$$=InsertNode("Dec",1,$1);$$->rulenum = 1;}
    | VarDec ASSIGNOP Exp {$$=InsertNode("Dec",3,$1,$2,$3);$$->rulenum = 2;}
    ;
Exp : Exp ASSIGNOP Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 1;
    }
    | Exp AND Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 2;
    }
    | Exp OR Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 3;
    }
    | Exp RELOP Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 4;
    }
    | Exp PLUS Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 5;
    }
    | Exp MINUS Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 6;
    }
    | Exp STAR Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 7;
    }
    | Exp DIV Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 8;
    }
    | Exp MOD Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 9;
    }
    | LP Exp RP
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        $$->rulenum = 10;
    }
    | MINUS Exp
    {
        $$=InsertNode("Exp",2,$1,$2);
        $$->rulenum = 11;
    }
    | NOT Exp
    {
        $$=InsertNode("Exp",2,$1,$2);
        $$->rulenum = 12;
    }
    | ID LP Args RP
    {
        $$=InsertNode("Exp",4,$1,$2,$3,$4);
        strcpy($$->idType,$1->idType);
        $$->rulenum = 13;
    }
    | ID LP RP
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        strcpy($$->idType,$1->idType);
        $$->rulenum = 14;
    }
    | Exp LB Exp RB {$$=InsertNode("Exp",4,$1,$2,$3,$4);$$->rulenum = 15;}
    | Exp DOT ID {$$=InsertNode("Exp",3,$1,$2,$3);$$->rulenum = 16;strcpy($$->idType,$3->idType);}
    | ID
    {
        $$=InsertNode("Exp",1,$1);
        strcpy($$->idType,$1->idType);
        $$->rulenum = 17;
    }
    | INT
    {
        $$=InsertNode("Exp",1,$1);
        $$->type = 1;
        $$->integer = $1->integer;
        $$->rulenum = 18;
    }
    | FLOAT
    {
        $$=InsertNode("Exp",1,$1);
        $$->type = 2;
        $$->fnum = $1->fnum;
        $$->rulenum = 19;
    }
    ;
Args : Exp COMMA Args {$$=InsertNode("Args",3,$1,$2,$3);$$->rulenum = 1;}
    | Exp {$$=InsertNode("Args",1,$1);$$->rulenum = 2;}
%%
