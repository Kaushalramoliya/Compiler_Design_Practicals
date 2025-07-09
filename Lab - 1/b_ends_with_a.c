#include <stdio.h>

int main() {
    char input[100];
    int state = 0, i = 0;
    
    FILE *file = fopen("b_endswitha.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(file, "%s", input);
    fclose(file);
    
    while (input[i] != '\0') {
        switch (state) {
            case 0:
                if (input[i] == 'a') {
                    state = 1;  
                } else if (input[i] == 'b') {
                    state = 0;  
                } else {
                    state = 2;  
                }
                break;
                
            case 1:
                if (input[i] == 'a') {
                    state = 1;  
                } else if (input[i] == 'b') {
                    state = 0;  
                } else {
                    state = 2;  
                }
                break;
                
            case 2:
                state = 2;  
                break;

            default:
                break;
        }
        i++;
    }

    printf("State is %d\n", state);

    if (state == 1) {
        printf("String is valid\n");
    } else {
        printf("String is Invalid\n");
    }

    return 0;
}

