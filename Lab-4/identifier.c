#include <stdio.h>


int main(){
	char input[100];
	int state = 0, i = 0;
	
	FILE *file = fopen("identifier.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(file, "%s", input);
    fclose(file);
    
    while(input[i] != '\0'){
    	switch(state){
    		case 0:
    			if(input[i] == 'i'){
    				state = 1;
				}
				else if(input[i] == '_' || isalpha(input[i])){
					state = 5;
				}
				break;
				
			case 1:
				if(input[i] == 'n'){
					state = 2;
				}
				else if(input[i] == '_' || isalpha(input[i]) || isdigit(input[i])){
					state = 5	;
				}
				break;
				
			case 2:
				if(input[i] == 't'){
					state = 3;
					printf("int is a key world");
				}
				else if(input[i] == '_' || isalpha(input[i]) || isdigit(input[i])){
					state = 5	;
				}
				else{
					printf("in is a id");
					state = 0;
				}
				break;
				
			case 3:
				if(input[i] == '_' || isalpha(input[i]) || isdigit(input[i])){
					state = 5	;
				}
				else{
					printf("int is a key world");
					state = 0;
				}
				
				break;
				
			case 5:
				if(input[i] == '_' || isalpha(input[i]) || isdigit(input[i])){
					state = 5	;
				}
				else{
					printf("_ is akey world");
					state = 0;
				}
				break;				
				
			default:
				break;
		}
    	
    	i++;
	}
	
	printf("State is %d\n",state);
	if(state == 3){
		printf("it is a velid keyword\n");
	}
	
	return 0;
}
