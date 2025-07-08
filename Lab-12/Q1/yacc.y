%{
 #include <stdio.h>
 int yylex(void);
 void yyerror(char *);
%}
%union {
    char *str;
    int num;
}
%token <num> INTEGER
%token <str> ID
%%
S: E '\n'       { printf("\n"); }
E: E '+' T      { printf("+"); }
 | E '-' T      { printf("-"); }
 | T            { }
T : T '*' F     { printf("*"); }
 | F            { }
F:  INTEGER     { printf("%d",$1); }
 | ID              { printf("%s",$1); }
%%
void yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
}
int main() {
 yyparse();
 return 0;
}