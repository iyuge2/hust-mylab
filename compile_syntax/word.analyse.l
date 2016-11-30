/*
 * Author: iyuge2
 * Creat-time: 2016/11/03 15:05
 * Update-time: 2016/11/08 20:36
 * Function: 词法规则的声明
 * */
%{
#include<stdio.h>
#include<stdlib.h>
#include"syntaxTree.h"
#include"syntax.tab.h"
extern int WordToggle;
extern FILE* fword;
int tokennum = 0;
int yycolumn = 1;
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
%}


%x COMMENT
%option yylineno
TYPE float|int
ELSE else
IF if
STRUCT struct
RETURN return
WHILE while
PLUS \+
MINUS -
STAR \*
DIV \/
MOD %
INT ([1-9][0-9]*)|0|(0[xX][0-9a-fA-F]+)|(0[0-7]+)
FLOAT ([0-9]+\.[0-9]+)|([0-9]*[\.]?[0-9]+[eE][+-]?[0-9]+)
ID [a-z_A-Z][a-zA-Z_0-9]*
IDERROR [1-9]+[a-zA-Z0-9]+
SPACE [ \t\r]+
EN \n
SEMI ;
COMMA ,
ASSIGNOP =
RELOP >|<|<=|>=|==|!=
AND &&
OR \|\|
DOT \.
NOT !
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
AERROR .

%%
"//".* {if(WordToggle) fputs("COMMENTS",fword);}
"/*" {BEGIN COMMENT;if(WordToggle) fputs("COMMENTS",fword);}
<COMMENT>"*/" {BEGIN INITIAL;}
<COMMENT>. {}

{TYPE} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s TYPE>)\n",++tokennum,yytext);
    yylval.node = InsertNode("TYPE",0,yylineno);
    return TYPE;
    }
{ELSE} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s ELSE>)\n",++tokennum,yytext);
    yylval.node = InsertNode("ELSE",0,yylineno);
    return ELSE;
    }
{IF} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s IF>)\n",++tokennum,yytext);
    yylval.node = InsertNode("IF",0,yylineno);
    return IF;
    }
{RETURN} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s RETURN>)\n",++tokennum,yytext);
    yylval.node = InsertNode("RETURN",0,yylineno);
    return RETURN;
    }
{WHILE} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s WHILE>)\n",++tokennum,yytext);
    yylval.node = InsertNode("WHILE",0,yylineno);
    return WHILE;
    }
{STRUCT} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s STRUCT>)\n",++tokennum,yytext);
    yylval.node = InsertNode("STRUCT",0,yylineno);
    return STRUCT;
    }
{PLUS} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s PLUS>)\n",++tokennum,yytext);
    yylval.node = InsertNode("PLUS",0,yylineno);
    return PLUS;
    }
{MINUS} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s MINUS>)\n",++tokennum,yytext);
    yylval.node = InsertNode("MINUS",0,yylineno);
    return MINUS;
    }
{STAR} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s STAR>)\n",++tokennum,yytext);
    yylval.node = InsertNode("STAR",0,yylineno);
    return STAR;
    }
{DIV} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s DIV>)\n",++tokennum,yytext);
    yylval.node = InsertNode("DIV",0,yylineno);
    return DIV;
    }
{MOD} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s MOD>)\n",++tokennum,yytext);
    yylval.node = InsertNode("MOD",0,yylineno);
    return MOD;
    }
{INT} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s INT>)\n",++tokennum,yytext);
    yylval.node = InsertNode("INT",0,yylineno);
    return INT;
    }
{FLOAT} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s FLOAT>)\n",++tokennum,yytext);
    yylval.node = InsertNode("FLOAT",0,yylineno);
    return FLOAT;
    }
{ID} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s ID>)\n",++tokennum,yytext);
    yylval.node = InsertNode("ID",0,yylineno);
    return ID;
    }
{SPACE} {}
{EN} {yycolumn = 1;}
{SEMI} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s SEMI>)\n",++tokennum,yytext);
    yylval.node = InsertNode("SEMI",0,yylineno);
    return SEMI;
    }
{COMMA} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s COMMA>)\n",++tokennum,yytext);
    yylval.node = InsertNode("COMMA",0,yylineno);
    return COMMA;
    }
{ASSIGNOP} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s ASSIGNOP>)\n",++tokennum,yytext);
    yylval.node = InsertNode("ASSIGNOP",0,yylineno);
    return ASSIGNOP;
    }
{RELOP} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s RELOP>)\n",++tokennum,yytext);
    yylval.node = InsertNode("RELOP",0,yylineno);
    return RELOP;
    }
{AND} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s AND>)\n",++tokennum,yytext);
    yylval.node = InsertNode("AND",0,yylineno);
    return AND;
    }
{OR} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s OR>)\n",++tokennum,yytext);
    yylval.node = InsertNode("OR",0,yylineno);
    return OR;
    }
{DOT} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s DOT>)\n",++tokennum,yytext);
    yylval.node = InsertNode("DOT",0,yylineno);
    return DOT;
    }
{NOT} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s NOT>)\n",++tokennum,yytext);
    yylval.node = InsertNode("NOT",0,yylineno);
    return NOT;
    }
{LP} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s LP>)\n",++tokennum,yytext);
    yylval.node = InsertNode("LP",0,yylineno);
    return LP;
    }
{RP} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s RP>)\n",++tokennum,yytext);
    yylval.node = InsertNode("RP",0,yylineno);
    return RP;
    }
{LB} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s LB>)\n",++tokennum,yytext);
    yylval.node = InsertNode("LB",0,yylineno);
    return LB;
    }
{RB} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s RB>)\n",++tokennum,yytext);
    yylval.node = InsertNode("RB",0,yylineno);
    return RB;
    }
{LC} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s LC>)\n",++tokennum,yytext);
    yylval.node = InsertNode("LC",0,yylineno);
    return LC;
    }
{RC} {
    if(WordToggle)
        fprintf(fword,"(token[%d]:<%s RC>)\n",++tokennum,yytext);
    yylval.node = InsertNode("RC",0,yylineno);
    return RC;
    }
{AERROR} {
    printf("Error type A at line %d: Mystirious charachter '%s'\n",yylineno,yytext);
    }
{IDERROR} {
    printf("Error type A at line %d: illegal identifier '%s'\n",yylineno,yytext);
    }
%%
int yywrap()
{
    return 1;
}
