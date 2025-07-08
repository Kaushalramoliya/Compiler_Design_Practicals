#include <stdio.h>


int main(){
	char input[100];
	int state = 0, i = 0;
	
	FILE *file = fopen("d_conain_ab.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(file, "%s", input);
    fclose(file);
    
    while(input[i] != '\0'){
    	switch(state){
    		case 0:
    			if(input[i] == 'a'){
    				state = 1;
				}
				else if(input[i] == 'b'){
					state = 0;
				}
				else{
					state = 3;
				}
				break;
				
			case 1:
				if(input[i] == 'a'){
					state = 1;
				}
				else if(input[i] == 'b'){
					state = 2;
				}
				else{
					state = 3;
				}
				break;
				
			case 2:
				if(input[i] == 'a' || input[i] == 'b'){
					state = 2;
				}
				else{
					state = 3;
				}
				break;
				
			case 3:
				state = 3;
				break;
				
			default:
				break;
		}
    	
    	i++;
	}
	
	printf("State is %d\n",state);
	
	if(state == 2 ){
		printf("Stering is velid\n");
	}
	else{
		printf("Stering is Invelid\n");
	}

	
	return 0;
}
