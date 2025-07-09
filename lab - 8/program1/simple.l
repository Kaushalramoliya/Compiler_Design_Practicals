%{
    #include<stdio.h>
    int letters=0;
%}
%%
[a-zA-Z]    {letters++;}
\n    ;
.     ;
%%
void main(){
    yyin=fopen("lab8_1.txt","r");
    yylex();
    
    printf("This file is Containing %d letters" , letters);
}
int yywrap(){return(1);}