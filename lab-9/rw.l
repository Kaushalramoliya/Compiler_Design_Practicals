%{
#include<stdio.h>
int line_number=1; 
%}
%%
.+ {fprintf(yyout,"%d: %s", line_number,yytext);line_number++;}
%%
int main(){
yyin=fopen("num.txt","r");
yyout=fopen("op.txt", "w");
yylex();
printf("done");
return 0;
}
int yywrap(){return(1);}