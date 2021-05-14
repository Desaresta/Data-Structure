#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QueueNode{
	int item;
	struct QueueNode *next;
};

struct QueueNode *backPtr = NULL;
struct QueueNode *temp = NULL;


void enqueue(int newItem){
	struct QueueNode *newPtr = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	newPtr->item = newItem;
	if(backPtr == NULL){
		backPtr = newPtr;
		backPtr->next = backPtr;
	}else{
		temp = backPtr->next;
        backPtr->next = newPtr;
        backPtr = newPtr;
        newPtr->next = temp;
	}	
}

void dequeue(){
	if(backPtr != NULL){
		temp = backPtr->next;
		printf("%d",temp->item);
		if(backPtr == temp){
			backPtr = NULL;
			free(temp);
		}else{
			backPtr->next = temp->next;
			temp = NULL;
			free(temp);
		}
	}else{
		printf("no");
	}
}


void getFront(){
    if (backPtr!=NULL){
    	printf("%d", backPtr->next->item);
	}else{
		printf("no");
	}
}


void clearQueue(){
	if(backPtr != NULL){
		temp = backPtr->next;
		if(backPtr == backPtr->next){
			printf("%d", temp->item);
			backPtr = NULL;
			free(temp);
		}else{
			while(temp != backPtr){
			printf("%d ", temp->item);
        	temp = temp->next;
			}
			printf("%d", backPtr->item);
			backPtr = NULL;
			free(temp);		
		}	
	}else{
		printf("no");
	}
}

int size(){
	int count = 0;
	if(backPtr == NULL){
		printf("%d",count);
	}else{
		temp = backPtr->next;
		while(temp != backPtr){
			count++;
			temp = temp->next;
		}
		printf("%d",count+1);
	}
}


char isEmpty(){		
	if (backPtr == NULL){
		printf("yes");
	}else{
		printf("no");
	}
}


int main(){
	int newItem;
	int n;
	scanf("%d", &n);
	while(n<7 && n>0){
		if(n == 1){
			scanf("%d", &newItem);
			enqueue(newItem);
		}else if(n == 2){
			dequeue();
			printf("\n");
		}else if(n == 3){
			getFront();
			printf("\n");
		}else if(n == 4){
			clearQueue();
			printf("\n");
		}else if(n == 5){
			size();
			printf("\n");
		}else if(n == 6){
			isEmpty();
			printf("\n");
		}
		scanf("%d", &n);
	}
	if(n == 7){
		return 0; 
	}				   
}
