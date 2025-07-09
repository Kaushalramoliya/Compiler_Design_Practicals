%{
#include<stdio.h>
%}
%%
[0-9]+(\.[0-9]+)?([Ee][+-]?[0-9]+)? printf("%s is valid number \n", yytext);
\n   ;
.   ;
%%
void main() {
    yyin = fopen("num.txt", "r");
    yylex();
    fclose(yyin);
}
int yywrap() { return 1; }