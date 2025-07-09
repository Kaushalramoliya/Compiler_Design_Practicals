#include <stdio.h>
#include <ctype.h>
#include <string.h>

void parseLine(const char *line);

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        parseLine(buffer);
    }

    fclose(fp);
    return 0;
}

void parseLine(const char *line) {
    int state = 0;        
    char lexeme[256];     
    int f = 0;            
    int i = 0;          
    char c;

    while ((c = line[f]) != '\0') {
        switch (state) {
            case 0:
                if (isdigit(c)) {
                    state = 13;           
                    lexeme[i++] = c;
                }
                else if (isalpha(c)) {
                    state = 1;           
                    lexeme[i++] = c;
                }
                else {
                    // For whitespace or symbols, do nothing special here
                }
                break;

            case 1:
                if (isalnum(c)) {
                    lexeme[i++] = c;
                } else {
                    lexeme[i] = '\0';
                    printf("%s is an identifier\n", lexeme);
                    i = 0;
                    state = 0;
                    f--; 
                }
                break;
                
            case 13:
                if (isdigit(c)) {
                    lexeme[i++] = c;
                }
                else if (c == '.') {
                    state = 14;
                    lexeme[i++] = c;
                }
                else if (c == 'E' || c == 'e') {
                    state = 16;
                    lexeme[i++] = c;
                }
                else {
                    lexeme[i] = '\0';
                    printf("%s is a number\n", lexeme);

                    i = 0;
                    state = 0;
                    f--; 
                }
                break;

            case 14:
                if (isdigit(c)) {
                    state = 15;
                    lexeme[i++] = c;
                }
                else {
                    // We have something like "123." with no digit after '.'
                    // We'll finalize "123." as a number (or handle error).
                    lexeme[i] = '\0';
                    printf("%s is a number\n", lexeme);

                    i = 0;
                    state = 0;
                    f--;
                }
                break;

            case 15:
                if (isdigit(c)) {
                    lexeme[i++] = c;
                }
                else if (c == 'E' || c == 'e') {
                    state = 16;
                    lexeme[i++] = c;
                }
                else {
                    lexeme[i] = '\0';
                    printf("%s is a number\n", lexeme);

                    i = 0;
                    state = 0;
                    f--;
                }
                break;

            case 16:
                if (c == '+' || c == '-') {
                    state = 17; 
                    lexeme[i++] = c;
                }
                else if (isdigit(c)) {
                    state = 18; 
                    lexeme[i++] = c;
                }
                else {
                    lexeme[i] = '\0';
                    printf("%s is a number\n", lexeme);

                    i = 0;
                    state = 0;
                    f--;
                }
                break;

            case 17:
                if (isdigit(c)) {
                    state = 18;
                    lexeme[i++] = c;
                }
                else {
                    lexeme[i] = '\0';
                    printf("%s is a number\n", lexeme);

                    i = 0;
                    state = 0;
                    f--;
                }
                break;

            case 18:
                if (isdigit(c)) {
                    lexeme[i++] = c;
                }
                else {
                    lexeme[i] = '\0';
                    printf("%s is a number\n", lexeme);

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
    
    if (state == 1) {
        lexeme[i] = '\0';
        printf("%s is an identifier\n", lexeme);
    }
    else if (state == 13 || state == 14 || state == 15 ||
             state == 16 || state == 17 || state == 18) {
        lexeme[i] = '\0';
        printf("%s is a number\n", lexeme);
    }
}

