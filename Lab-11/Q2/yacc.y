%{ 
#include <stdio.h> 
int yylex(void); 
void yyerror(char *); 
%}
%token NUM 
%token id 
%%
S: E '\n' { printf("valid synatx"); return(0); } 
E: E '+' T {  } 
 | E '-' T {  } 
 | T       {  } 
T: T '*' F {  } 
 | F       {  }
F:NUM   {  } 
  | id   {  }
%%
void yyerror(char *s) { 
    fprintf(stderr, "%s\n", s); 
} 
int main() { 
    yyparse();  
    return 0; 
}