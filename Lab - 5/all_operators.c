#include <stdio.h>

int main(){
	char input[100];
	int state = 0, i = 0;
	
	FILE *file = fopen("operator.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(file, "%s", input);
    fclose(file);
    
    while(input[i] != '\0'){
    	switch(state){
    		case 0:
    			if(input[i] == '+'){
    				state = 1;
				}
				else if(input[i] == '-'){
					state = 5;
				}
				else if(input[i] == '*'){
					state = 9;
				}
				else if(input[i] == '/'){
					state = 12;
				}
				else if(input[i] == '%'){
					state = 15;
				}
				else if(input[i] == '&'){
					state = 18;
				}
				else if(input[i] == '|'){
					state = 21;
				}
				else if(input[i] == '<'){
					state = 24;
				}
				else if(input[i] == '>'){
					state = 28;
				}
				else if(input[i] == '!'){
					state = 32;
				}
				else if(input[i] == '~'){
					state = 34;
				}
				else if(input[i] == '^'){
					state = 35;
				}
				else if(input[i] == '='){
					state = 36;
				}
				break;
				
			case 1:
				if(input[i] == '+'){
					state = 2;
					printf("++,unari operator");
				}
				else if(input[i] == '='){
					state = 3;
					printf("+=,,assignment operator");
				}
				else{
					state = 4;
					printf("+,arithmetic operator");
				}
				break;
				
			case 5:
				if(input[i] == '-'){
					state = 6;
					printf("--,unari operator");
				}
				else if(input[i] == '='){
					state = 7;
					printf("-=,assignment operator");
				}
				else{
					state = 8;
					printf("+,arithmetic operator");
				}
				break;
			
			case 9:
				if(input[i] == '='){
					state = 10;
					printf("*=,assignment operator");
				}
				else{
					state = 11;
					printf("*,arithmetic operator");
				}
				break;

			case 12:
				if(input[i] == '='){
					state = 13;
					printf("/=,assignment operator");
				}
				else{
					state = 14;
					printf("/,arithmetic operator");
				}
				break;

			case 15:
				if(input[i] == '='){
					state = 16;
					printf("%=,assignment operator");
				}
				else{
					state = 17;
					printf("%,arithmetic operator");
				}
				break;
				
			case 18:
				if(input[i] == '&'){
					state = 19;
					printf("&&,Logical operator");
				}
				else{
					state = 20;
					printf("%,Bitwise operator");
				}
				break;
				
			case 21:
				if(input[i] == '|'){
					state =22;
					printf("||,Logical operator");
				}
				else{
					state = 23;
					printf("|,Bitwise operator");
				}
				break;
			
			case 24:
				if(input[i] == '<'){
					state =25;
					printf("<<,Bitwise operator");
				}
				else if(input[i] == '='){
					state =27;
					printf("<=,Relational operator");
				}
				else{
					state = 26;
					printf("< ,Relational operator");
				}
				break;
				
			case 28:
				if(input[i] == '>'){
					state =29;
					printf(">>,Bitwise operator");
				}
				else if(input[i] == '='){
					state =30;
					printf(">=,Relational operator");
				}
				else{
					state = 31;
					printf("> ,Relational operator");
				}
				break;
				
			case 32:
				if(input[i] == '='){
					state =33;
					printf("!=,Assignment operator");
				}
				break;
				
			case 36:
				if(input[i] == '='){
					state =37;
					printf("==,Relational operator");
				}
				break;
				
			default:
				break;
		}
    	
    	i++;
	}
	
	printf("\nState is %d\n",state);
	if(state == 1){printf("+,arithmetic operator\n");}
	else if(state == 5){printf("-,arithmetic operator\n");}
	else if(state == 9){printf("*,arithmetic operator\n");}
	else if(state == 12){printf("/,arithmetic operator\n");}
	else if(state == 15){printf("%,arithmetic operator\n");}
	else if(state == 18){printf("&,Bitwise operator\n");}
	else if(state == 21){printf("|,Bitwise operator\n");}
	else if(state == 24){printf("<,Relational operator\n");}
	else if(state == 28){printf(">,Relational operator\n");}
	else if(state == 32){printf("!,Logical operator\n");}
	else if(state == 34){printf("~,Bitwise operator\n");}
	else if(state == 35){printf("^,Bitwise operator\n");}
	else if(state == 36){printf("=,Assignment operator\n");}	
	return 0;
}
