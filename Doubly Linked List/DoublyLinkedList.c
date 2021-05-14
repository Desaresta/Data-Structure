#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NodeD { 
    int item; 
	struct NodeD* prev; 
	struct NodeD* next;
};


struct NodeD* head = NULL;
struct NodeD* cur = NULL;

char isEmpty(){		
	if (head == NULL){
		printf("yes");
	}else{
		printf("no");
	}
}

int getSize() { 			
    int count = 0;  
    cur = head; 
    while (cur != NULL) 
    { 
        count++; 
        cur = cur->next; 
    } 
	printf("%d",count);
}

void insertFirst(int newItem){
	struct NodeD *newNode = (struct NodeD*)malloc(sizeof(struct NodeD));
	newNode->item = newItem;
	if(head == NULL) {
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}else{
		head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
	}
}

void insertLast(int newItem){
	struct NodeD *newNode = (struct NodeD*)malloc(sizeof(struct NodeD));
	newNode->item = newItem;
	if(head == NULL) {
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}else{
		cur = head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->prev = cur;
		newNode->next = NULL;
	}
}

void removeFirst(){
	if(head != NULL){
		if(head->next==NULL){
			cur = head;
			head = NULL;
			free(cur);
		}else{
			cur = head;
    		head = head->next;
    		head->prev = NULL;
    		free(cur);	
		}
	}		
}

void removeLast(){
	if(head != NULL){
		if(head->next==NULL){
			cur = head;
			head = NULL;
			free(cur);
		}else{
			cur = head;
			while(cur->next != NULL){
				cur = cur->next;
			}
			cur->prev->next = NULL;
			free(cur);
		}	
	}
}

void displayList(){
	if(head != NULL){
		cur = head;
    	while(cur != NULL){
        	printf("%d ", cur->item);
        	cur = cur->next;
    	} 	
	}		   
}


void traverseList(int n, char pattern[]){
    cur = head; 
    int i = 0;
    if(head != NULL){
    	while(i<n){
        	if(pattern[i] == 'L'){
        	    if(cur->prev != NULL){
            	    cur = cur->prev;
            	}    
        	}else if(pattern[i] == 'R'){
            	if(cur->next != NULL){
                	cur = cur->next;
            	}
			}
        	i++;
    	}
		printf("%d",cur->item);	
	}else if(head == NULL){
		printf("no");
	}    
}


int main(){
	int num;
	int newItem;
	int n;
	char pattern[100];
	scanf("%d", &num);
	while(num<=8 && num>0){
		if(num == 1){
			isEmpty();
			printf("\n");	
		}
		else if(num == 2){
			getSize();
			printf("\n");	
		}
		else if(num == 3){
			scanf("%d",&newItem );
			insertFirst(newItem);
		}
		else if(num == 4){
			scanf("%d",&newItem );
			insertLast(newItem);
		}
		else if(num == 5){
			removeFirst();
		}
		else if(num == 6){
			removeLast();
		}
		else if(num == 7){
			displayList();
			printf("\n");
		}
		else if(num == 8){
			scanf("%d", &n); 
			scanf("%s", &pattern);
			traverseList(n,pattern);
			printf("\n");
		}
		scanf("%d", &num);
	}
	if(num == 9){
		return 0; 	
	}	   
}
