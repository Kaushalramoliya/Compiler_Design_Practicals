%{
#include <stdlib.h>
void yyerror(char *);
#include "yacc.tab.h"
%}
%%
[0-9]+ {yylval.num = atoi(yytext); return INTEGER;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = yytext; return ID;}
[-+*\n] {return *yytext;}
[ \t] { }
. yyerror("invalid character");
%%
int yywrap() {
 return 0;
}