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
        grammaTreeHead = $$;
        if(GrammaToggle){
            printf("开始打印syntax tree...\n");
            eval(grammaTreeHead,0);
            printf("syntax tree 打印完毕!\n");
        }
    }
    ;
ExtDefList : ExtDef ExtDefList {$$=InsertNode("ExtDefList",2,$1,$2);}
    |/*empty*/{$$=InsertNode("ExtDefList",0,-1);}
    ;
ExtDef : Specifier ExtDecList SEMI
    {//检查变量定义
        $$=InsertNode("ExtDef",3,$1,$2,$3);
        if(exitvar($2))//Error 3
            printf("Error type 3 at Line %d:Redefined Variable '%s'\n",yylineno,$2->content);
        else
            newvar(2,$1,$2);
    }
    | Specifier SEMI {$$=InsertNode("ExtDef",2,$1,$2);}
    | Specifier error SEMI /*获取错误，从中搜取分号，继续执行*/
    | Specifier FunDec CompSt
    {
        $$=InsertNode("ExtDef",3,$1,$2,$3);
        newfunc(4,$1);
    }
    ;
ExtDecList : VarDec {$$=InsertNode("ExtDecList",1,$1);}
    | VarDec COMMA ExtDecList {$$=InsertNode("ExtDecList",3,$1,$2,$3);}
    ;
Specifier : TYPE {$$=InsertNode("Specifier",1,$1);}
    | StructSpecifier {$$=InsertNode("Specifier",1,$1);}
    ;
StructSpecifier : STRUCT OptTag LC DefList RC
    {
        $$=InsertNode("StructSpecifier",5,$1,$2,$3,$4,$5);
        if(exitstruc($2))//Error 16
            printf("Error type 16 at Line %d: Duplicated name '%s'\n",yylineno,$2->content);
        else
            newstruc(1,$2);
    }
    | STRUCT OptTag LC DefList error RC
    | STRUCT Tag
    {
        $$=InsertNode("StructSpecifier",2,$1,$2);
        if(!exitstruc($2))//Error 17
            printf("Error type 17 at Line %d:undefined structure '%s'\n",yylineno,$2->content);
    }
    ;
OptTag : ID {$$=InsertNode("OptTag",1,$1);}
    | /*empty*/{$$=InsertNode("OptTag",0,-1);}
    ;
Tag : ID {$$=InsertNode("Tag",1,$1);}
    ;
VarDec : ID {$$=InsertNode("VarDec",1,$1);$$->tag = 1;}
    | VarDec LB INT RB
    {
        $$=InsertNode("VarDec",4,$1,$2,$3,$4);
        strcpy($$->content,$1->content);
        $$->tag=4;
    }
    ;
FunDec : ID LP VarList RP
    {
        $$=InsertNode("FunDec",4,$1,$2,$3,$4);
        if(exitfunc($1))//Error 4
            printf("Error type 4 at Line %d:Redefined Function '%s'\n",yylineno,$1->content);
        else
            newfunc(2,$1);
    }
    | ID LP RP
    {
        $$=InsertNode("FunDec",3,$1,$2,$3);
        strcpy($$->content,$1->content);
        if(exitfunc($1))//Error 4
            printf("Error type 4 at Line %d:Redefined Function '%s'\n",yylineno,$1->content);
        else
            newfunc(2,$1);
    }
    ;
VarList : ParamDec COMMA VarList {$$=InsertNode("VarList",3,$1,$2,$3);}
    | ParamDec {$$=InsertNode("VarList",1,$1);}
    ;
ParamDec : Specifier VarDec {$$=InsertNode("ParamDec",2,$1,$2);newvar(2,$1,$2);newfunc(1);}
    ;
CompSt : LC DefList StmtList RC {$$=InsertNode("CompSt",4,$1,$2,$3,$4);}
    | LC DefList StmtList error RC
    ;
StmtList : Stmt StmtList {$$=InsertNode("StmtList",2,$1,$2);}
    | /*empty*/{$$=InsertNode("StmtList",0,-1);}
Stmt : Exp SEMI {$$=InsertNode("Stmt",2,$1,$2);}
    | Exp error SEMI /*获取错误，从中搜取分号，继续执行*/
    | CompSt {$$=InsertNode("Stmt",1,$1);}
    | RETURN Exp SEMI {$$=InsertNode("Stmt",3,$1,$2,$3);}
    | RETURN Exp error SEMI /*获取错误，从中搜取分号，继续执行*/
    | IF LP Exp RP Stmt {$$=InsertNode("Stmt",5,$1,$2,$3,$4,$5);}
    | IF LP Exp RP Stmt ELSE Stmt {$$=InsertNode("Stmt",7,$1,$2,$3,$4,$5,$6,$7);}
    | WHILE LP Exp RP Stmt {$$=InsertNode("Stmt",5,$1,$2,$3,$4,$5);}
    ;
DefList : Def DefList {$$=InsertNode("DefList",2,$1,$2);}
    | /*empty*/{$$=InsertNode("DefList",0,-1);}
    ;
Def : Specifier DecList SEMI
    {
        $$=InsertNode("Def",3,$1,$2,$3);
        if(exitvar($2)||exitarray($2))//Error 3
            printf("Error type 3 at Line %d:Redefined Variable '%s'\n",yylineno,$2->content);
        else if($2->tag==4)
            newarray(2,$1,$2);
        else
            newvar(2,$1,$2);
    }
    | Specifier DecList error SEMI /*获取错误，从中搜取分号，继续执行*/
    ;
DecList : Dec {$$=InsertNode("DecList",1,$1);}
    | Dec COMMA DecList {$$=InsertNode("DecList",3,$1,$2,$3);$$->tag = $3->tag;}
    ;
Dec : VarDec {$$=InsertNode("Dec",1,$1);}
    | VarDec ASSIGNOP Exp {$$=InsertNode("Dec",3,$1,$2,$3);strcpy($$->content,$1->content);}
    ;
Exp : Exp ASSIGNOP Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))//Error 5
            printf("Error type 5 at Line %d:Type mismatched for assignment.\n ",yylineno);
    }
    | Exp AND Exp {$$=InsertNode("Exp",3,$1,$2,$3);}
    | Exp OR Exp {$$=InsertNode("Exp",3,$1,$2,$3);}
    | Exp RELOP Exp {$$=InsertNode("Exp",3,$1,$2,$3);}
    | Exp PLUS Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))//Error 7
            printf("Error type 7 at Line %d:Type mismatched for operand.\n ",yylineno);
    }
    | Exp MINUS Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
            printf("Error type 7 at Line %d:Type mismatched for operand.\n ",yylineno);
    }
    | Exp STAR Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
            printf("Error type 7 at Line %d:Type mismatched for operand.\n ",yylineno);
    }
    | Exp DIV Exp
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
            printf("Error type 7 at Line %d:Type mismatched for operand.\n ",yylineno);
    }
    | LP Exp RP {$$=InsertNode("Exp",3,$1,$2,$3);}
    | Exp MOD Exp {$$=InsertNode("Exp",3,$1,$2,$3);}
    | MINUS Exp {$$=InsertNode("Exp",2,$1,$2);}
    | NOT Exp {$$=InsertNode("Exp",2,$1,$2);}
    | ID LP Args RP
    {
        $$=InsertNode("Exp",4,$1,$2,$3,$4);
        if(!exitfunc($1))//Error 2
            printf("Error type 2 at Line %d:undefined Function %s\n ",yylineno,$1->content);
    }
    | ID LP RP {$$=InsertNode("Exp",3,$1,$2,$3);}
    | Exp LB Exp RB
    {
        $$=InsertNode("Exp",4,$1,$2,$3,$4);
        if(strcmp($3->type,"int"))//Error 12
            printf("Error type 12 at Line %d:%.1f is not a integer.\n",yylineno,$3->fnum);
        if((!exitarray($1))&&(exitvar($1)||exitfunc($1)))//Error 10
            printf("Error type 10 at Line %d:'%s'is not an array.\n ",yylineno,$1->content);
        else if(!exitarray($1))//Error 2
            printf("Error type 2 at Line %d:undefined Array %s\n ",yylineno,$1->content);

    }
    | Exp DOT ID
    {
        $$=InsertNode("Exp",3,$1,$2,$3);
        if(!exitstruc($1))//Error 13
            printf("Error type 13 at Line %d:Illegal use of '.'.\n",yylineno);
    }
    | ID
    {
        $$=InsertNode("Exp",1,$1);
        if(!exitvar($1)&&!exitarray($1))//Error 1
            printf("Error type 1 at Line %d:undefined variable %s\n ",yylineno,$1->content);
        else
            strcpy($$->type,typevar($1));
    }
    | INT {$$=InsertNode("Exp",1,$1);$$->tag=3;strcpy($$->type,"int");$$->integer = $1->integer;}
    | FLOAT {$$=InsertNode("Exp",1,$1);$$->tag=3;strcpy($$->type,"float");$$->fnum=$1->fnum;}
    ;
Args : Exp COMMA Args {$$=InsertNode("Args",3,$1,$2,$3);rpnum += 1;}
    | Exp {$$=InsertNode("Args",1,$1);rpnum += 1;}
%%
