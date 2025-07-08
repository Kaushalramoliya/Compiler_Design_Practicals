#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 1000

void check(char *lexeme);
void processSymbol(char c);

void main() {
    FILE *f1;
    char buffer[BUFFER_SIZE], lexeme[50];
    char c;
    int f = 0, state = 0, i = 0;
    
    f1 = fopen("input.txt", "r");
    if (f1 == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fread(buffer, sizeof(char), BUFFER_SIZE - 1, f1);
    buffer[BUFFER_SIZE - 1] = '\0';
    fclose(f1);

    while (buffer[f] != '\0') {
        switch (state) {
            case 0:
                c = buffer[f];
                if (isalpha(c) || c == '_') {
                    state = 1;
                    lexeme[i++] = c;
                } else if (isdigit(c)) {
                    state = 2;
                    lexeme[i++] = c;
                } else if (c == '/') {
                    state = 3;
                } else if (c == ' ' || c == '\t' || c == '\n') {
                    state = 0;
                } else {
                    processSymbol(c);
                    state = 0;
                }
                break;
            
            case 1:
                c = buffer[f];
                if (isalnum(c) || c == '_') {
                    lexeme[i++] = c;
                } else {
                    lexeme[i] = '\0';
                    check(lexeme);
                    i = 0;
                    state = 0;
                    f--;
                }
                break;
                
            case 2:
                c = buffer[f];
                if (isdigit(c)) {
                    lexeme[i++] = c;
                } else if (c == '.') {
                    state = 4;
                    lexeme[i++] = c;
                } else {
                    lexeme[i] = '\0';
                    printf("%s is a valid number\n", lexeme);
                    i = 0;
                    state = 0;
                    f--;
                }
                break;
                
            case 3:
                c = buffer[f];
                if (c == '/') {
                    while (buffer[f] != '\n' && buffer[f] != '\0') {
                        f++;
                    }
                } else if (c == '*') {
                    f++;
                    while (buffer[f] != '\0' && !(buffer[f] == '*' && buffer[f + 1] == '/')) {
                        f++;
                    }
                    f += 2;
                } else {
                    printf("/ is a symbol\n");
                    f--;
                }
                state = 0;
                break;
                
            case 4:
                c = buffer[f];
                if (isdigit(c)) {
                    lexeme[i++] = c;
                } else {
                    lexeme[i] = '\0';
                    printf("%s is a valid float number\n", lexeme);
                    i = 0;
                    state = 0;
                    f--;
                }
                break;
            
            default:
                state = 0;
                break;
        }
        f++;
    }
}

void check(char *lexeme) {
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "inline", "int", "long", "register", "restrict", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    
    for (int i = 0; i < 32; i++) {
        if (strcmp(lexeme, keywords[i]) == 0) {
            printf("%s is a keyword\n", lexeme);
            return;
        }
    }
    printf("%s is an identifier\n", lexeme);
}

void processSymbol(char c) {
    char symbols[] = {';', ',', '{', '}', '(', ')', '[', ']', '+', '-', '*', '=', '<', '>', '!'};
    int symbolCount = sizeof(symbols) / sizeof(symbols[0]);
    
    for (int i = 0; i < symbolCount; i++) {
        if (c == symbols[i]) {
            printf("%c is a symbol\n", c);
            return;
        }
    }
}
