%{ 
#include <stdlib.h> 
void yyerror(char *); 
#include "yacc.tab.h" 
%} 
%% 
[0-9]+ {yylval = atoi(yytext); return NUM;} 
[a-zA-Z_][a-zA-Z_0-9]* {return id;} 
[-+*\n] {return *yytext;} 
[ \t] { } 
. yyerror("invalid character"); 
%% 
int yywrap() { 
return 0; 
}