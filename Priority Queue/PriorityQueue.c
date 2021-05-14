#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
int heap[max];
int lastIndex = -1;
int save_h[max];

char isEmpty(){
	if(lastIndex == -1){
		printf("yes");
	}else{
		printf("no");
	}
}

int size(){
	int s = lastIndex + 1;
	printf("%d", s);
}

void min(){
	if(lastIndex == -1){
		printf("no");
	}else{
		printf("%d", heap[0]);
	}
}

void insert(int data){
    lastIndex = lastIndex + 1;
    heap[lastIndex] = data;
    upheap();
}		

int upheap(){
	int i = lastIndex;
    while(1){ 
        int parent = (i-1)/2;
        if (parent > -1 && heap[parent] > heap[i]){
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

void removeMin(){
	if(lastIndex == -1){
		printf("no");
	}else{
    	int temp = heap[0];
    	heap[0] = heap[lastIndex];
    	lastIndex--;
    	downheap(0);
    	printf("yes");
	}
}

int downheap(int i){
  	int left  = 2*i+1;
    int right = 2*i+2;
  	int smallest;
  	if(left <= lastIndex && heap[left] < heap[i]){
  		smallest = left;
	}else{
		smallest = i;
	}if(right <= lastIndex && heap[right] < heap[smallest]){
		smallest = right;
	}if(smallest != i){
    	int temp = heap[i];
    	heap[i] =  heap[smallest];
    	heap[smallest] = temp;
    	downheap (smallest);
	} 
}


void showPriorityQueue(){
	if(lastIndex==-1){
		printf("no");	
	}else{
    	int i;
    	for(i=0;i<=lastIndex;i++){
        	printf("%d ",heap[i]);
    	}
	}
}

int parent(int index){
	if (lastIndex==-1){
		printf("no");
	}else{
		if(index==0 || index>lastIndex){
			printf("no");	
		}else{
			int pos = (index-1)/2;
			printf("%d",heap[pos]);
		}
	}	
}

int leftChild(int index){
	int pos = (index*2)+1;
	if(pos>lastIndex){
		printf("no");
	}else{
		printf("%d",heap[pos]);
	}
}
  
int rightChild(int index){
	int pos = (index*2)+2;
	if(pos>lastIndex){
		printf("no");
	}else{
		printf("%d",heap[pos]);
	}
} 
   
int main(){
	int input,index,data;
	scanf ("%d", &input);
	while(input <= 9 && input > 0){
		if(input == 1){
			isEmpty();
			printf("\n");
		}else if(input == 2){
			size();
			printf("\n");
		}else if(input == 3){	
			min();
			printf("\n");
		}else if(input == 4){
			scanf ("%d", &data);
			insert(data);
		}else if(input == 5){	
			removeMin();
			printf("\n");
		}else if(input == 6){
			showPriorityQueue();
			printf("\n");
		}else if(input == 7){
			scanf("%d", &index);
			parent(index);
			printf("\n");
		}else if(input == 8){
			scanf ("%d", &index);
			leftChild (index);
			printf("\n");
		}else if(input == 9){
			scanf ("%d", &index);
			rightChild(index);
			printf("\n");
		}scanf ("%d", &input);	
	}if(input == 10){
		return 0; 	
	}
	return 0;	
  
}
