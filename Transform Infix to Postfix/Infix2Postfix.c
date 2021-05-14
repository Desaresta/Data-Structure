#include<stdio.h>
#include<stdlib.h>      
#include<string.h>
#include<ctype.h> 

#define SIZE 100

char stack[SIZE];
int top = -1;      
 
void push(char item){
	if(top<SIZE){
		top = top+1;
		stack[top] = item;
	}	
} 

char pop(){
	char item;
	if(top>-1){
		item = stack[top];
		top = top-1;
		return(item);
	}		
}
 
int operation(char item){      
    if(item == '#'){
		return 0;
	}else if(item == '('){
		return 1;
	}else if (item == '-' || item == '+'){
		return 2;
	}else if (item == '*' || item == '/'){
		return 3;
	}
}

void InfixToPostfix(char in_fix[],char post_fix[]){
	char word,item;
	int i = 0;
	int j = 0;
	push('#');
    while((word = in_fix[i++]) != '\0'){
        if( word == '('){
        	push(word);
		}else{
        	if(islower(word)){
        		post_fix[j++] = word;
			}else{
				if(word == ')'){
                    while( stack[top] != '(')
                        post_fix[j++] = pop();
                    item = pop();
                }else{     
                    while(operation(stack[top]) >= operation(word)){
                    	post_fix[j++]=pop();
					}
                    push(word);
                }
			}
		}         
    }while(stack[top] != '#'){
    	post_fix[j++]=pop();
	} 
    post_fix[j]='\0';         
    printf("%s",post_fix);
}
 
main(){                        
    char in_fix[SIZE],post_fix[SIZE];
    scanf("%s",in_fix);
    InfixToPostfix(in_fix,post_fix);
    return 0;    
}
