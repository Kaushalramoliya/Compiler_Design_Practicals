%{
#include<stdio.h>
int num=0; 
%}
%%
"<"[A-Za-z0-9]+">" printf("%s is a valid markup tag\n", yytext);
"<!--"(.|\n)*"-->" num++;
\n ;
. ;
%%

int main(){
yyin=fopen("myfile.txt","r");
yylex();
printf("%d comment", num);
return 0;
}
int yywrap(){return(1);}