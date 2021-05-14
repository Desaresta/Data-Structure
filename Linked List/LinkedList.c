#include <stdio.h>
#include <stdlib.h>

struct Node { 
    int item; 
    struct Node* next; 
};

struct Node *head = NULL;
struct Node *cur = NULL;
struct Node* prev = NULL;

char isEmpty(){ 			
	if (head == NULL){
		printf("yes");
	}else{
		printf("no");
	}
}

int getSize(){ 			
    int count = 0;  
    cur = head; 
    while (cur != NULL) { 
        count++; 
        cur = cur->next; 
    } 
	printf("%d",count);
}

void insertList(int pos, int data){
	int count = 0;  
    cur = head; 
    while (cur != NULL) { 
        count++; 
        cur = cur->next; 
    }
    if(pos>=1 && pos<=count+1){
    	struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)); 
		newNode->item = data;
		if(pos == 1){
			newNode->next = head;
			head = newNode;
		}else{
			prev = head;
			int i;
			for(i=1; i<pos-1; i++){
				if(prev->next != NULL){
					prev = prev->next;
				}else{
					break;
				}	
			}
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}

void removeList(int pos){
	int count = 0;  
    cur = head; 
    while (cur != NULL) { 
        count++; 
        cur = cur->next; 
    }
    
    if(pos==1 && count>1){
    	cur = head;
    	head = head->next;
    	free(cur);
	}else if(pos==1 && count==1){
		cur = head;
		head = NULL;
		free(cur);
	}else if(pos>1 && pos<count){
		prev = head;
		int i;
		for(i=1; i<pos-1; i++){
			prev = prev->next;		
		}			
		cur = prev->next;
		prev->next = cur->next;
		free(cur);
	}else if(pos==count){
		cur = head;
		int i;
		for(i=1; i<pos-1; i++){
			cur = cur->next;
		}
		cur->next = NULL;
	}
}

void retrieveList(int pos){
	if(head == NULL){
		printf("no");
	}else{
		int count = 0;  
    	cur = head; 
    	while (cur != NULL) { 
        	count++; 
        	cur = cur->next; 
    	}
    	if(pos<=count && pos>0){
    		cur = head; 
			int i = 1;
			while(i<pos){
				cur = cur->next;
				i++;
			}printf("%d", cur->item);
		}else{
			printf("no");
		}		
	}
}

void findList(int data){
	cur = head;
	int pos = 1;
	while(cur != NULL){	
        if(cur->item==data){
        	printf("%d",pos);
			break;
		}else{
			cur = cur->next;
			pos++;
		}
	}
	if(cur==NULL){
		printf("no");
	}
}

void displayList(){ 
	cur = head;
    while(cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }		   
}

int main(){
	int input,pos,data;
	scanf ("%d", &input);
	while(input <= 7 && input > 0){
		if(input == 1){
			isEmpty();
			printf("\n");
		}else if(input == 2){
			getSize();
			printf("\n");
		}else if(input == 3){	
			scanf ("%d%", &pos);
			scanf ("%d", &data);
			insertList(pos, data);
		}else if(input == 4){
			scanf ("%d", &pos);
			removeList(pos);
		}else if(input == 5){
			scanf ("%d", &pos);
			retrieveList(pos);
			printf("\n");
		}else if(input == 6){
			scanf ("%d", &data);
			findList(data);
			printf("\n");
		}else if(input == 7){
			displayList();
			printf("\n");
		}scanf ("%d", &input);	
	}if(input == 8){
		return 0; 	
	}   
}	
