%{
#include <stdio.h>
#include <string.h>

int comment_lines = 0;
%}

%%
"//"(.|\n).*              { count_lines(yytext); comment_lines++; }
"/"([^]|\+[^/])""+"/"  {count_lines(yytext); comment_lines++;}
.|\n                { fputc(yytext[0], yyout); }  // Copy all other content
%%

void main() {
    yyin  = fopen("Lab_10a.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    printf("Number of comment lines removed: %d\n", comment_lines);
    fclose(yyin);
    fclose(yyout);
}
int yywrap() {
    return 1;
}