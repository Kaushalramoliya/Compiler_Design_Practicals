%{
    #include<stdio.h>
    int latters=0;
%}
%%
[a-zA-Z]    {latters++;}
\n    ;
.     ;
%%
void main(){
    yyin=fopen("input.txt","r");
    yylex();
    
    printf("This file is Containing %d letters" , latters);
}
int yywrap(){return(1);}