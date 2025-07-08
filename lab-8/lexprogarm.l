%{
#include<stdio.h>
int characters=0;
int words=0;
int lines=1;    
%}
%%
[\t ]+ {words++;}
\n  {lines++;words++;}
.   {characters++;}
%%
void main(){
yyin=fopen("input.txt","r");
yylex();
printf("This file is containing %d characters\n",characters);
printf("This file is containing %d words\n",words);
printf("This file is containing %d lines\n",lines);
}
int yywrap(){return(1);}