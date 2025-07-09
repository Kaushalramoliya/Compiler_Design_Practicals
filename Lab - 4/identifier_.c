#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of C keywords
char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidIdentifier(char *str) {
    int i = 0;

    if (!(isalpha(str[0]) || str[0] == '_'))
        return 0;

    for (i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0;
    }

    if (isKeyword(str))
        return 0;

    return 1;
}

int main() {
    char input[100];
    FILE *file = fopen("identifier.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%s", input);
    fclose(file);

    if (isValidIdentifier(input)) {
        printf("String is a valid identifier\n");
    } else {
        printf("String is not a valid identifier\n");
    }

    return 0;
}
