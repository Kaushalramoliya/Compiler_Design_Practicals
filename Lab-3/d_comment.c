#include <stdio.h>


int main(){
	char input[100];
	int state = 0, i = 0;
	
	FILE *file = fopen("comment.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(file, "%s", input);
    fclose(file);
    
    while(input[i] != '\0'){
    	switch(state){
    		case 0:
    			if(input[i] == '/'){
    				state = 1;
				}
				else{
					state = 3;
				}
				break;
				
			case 1:
				if(input[i] == '/'){
					state = 2;
				}
				else if(input[i] == '*'){
					state = 4;
				}
				else{
					state = 3;
				}
				break;
				
			case 2:
				if(input[i] != '\0'){
					state = 2;
				}
				break;
				
			case 3:
				state = 3;
				break;
				
			case 4:
				if(input[i] == '*'){
					state = 5;
				}
				else{
					state = 4;
				}
				break;
				
			case 5:
				if(input[i] == '/'){
					state = 6;
				}
				else{
					state = 4;
				}
				break;	
				
			case 6:
				state = 3;
				break;	
				
				
			default:
				break;
		}
    	
    	i++;
	}
	
	printf("State is %d\n",state);
	
	if(state == 2 || state == 6){
		printf("Stering is Velid Comment\n");
	}
	else{
		printf("Stering is Invelid Comment\n");
	}

	
	return 0;
}
