%{
#include<stdio.h>
int consonants=0, vowels = 0;   
%}
%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z]  {consonants++;}
\n         ;
.          ;
%%
void main(){
yyin=fopen("data.txt","r");
yylex();
printf("This file is containing ...\n");
printf("This file is containing %d vowels\n",vowels);
printf("This file is containing %d consonants\n",consonants);
}
int yywrap(){return(1);}