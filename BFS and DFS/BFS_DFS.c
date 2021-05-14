#include <stdio.h>
#include <stdlib.h>

struct AdjListNode{
    int vertex_no;
    struct AdjListNode *next;
};

struct AdjList{
    struct AdjListNode *head;
};

struct Graph{
    int noofvertex;
    int *visited;
    struct AdjList*array;
};

struct AdjListNode *newAdjListNode(int v){
    struct AdjListNode *newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->vertex_no = v;
    newNode->next = NULL;
    return newNode;
};

struct Graph* createGraph(int n) { 
    int new_n = n+1;
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->noofvertex = new_n; 
    
    graph->visited =  malloc(new_n * sizeof(int));
    graph->array = (struct AdjList*) malloc(new_n * sizeof(struct AdjList)); 
  
    int i; 
    for (i = 0; i < new_n; ++i){
        
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph; 
}

void addEdge(struct Graph *graph,int src,int dest){
    struct AdjListNode* newNode = newAdjListNode(dest); 
    if(graph->array[src].head==NULL){
        graph->array[src].head = newNode;
    }else{
        struct AdjListNode *temp = graph->array[src].head;    
        if(temp->next==NULL && temp->vertex_no<=newNode->vertex_no){
            temp->next = newNode;
        }else if(temp->next==NULL && temp->vertex_no>newNode->vertex_no){
            newNode->next = temp;
            graph->array[src].head = newNode;
        }
        else{
            while(temp->next!=NULL && temp->next->vertex_no<=newNode->vertex_no){
                temp = temp->next;
            }
            struct AdjListNode *cur = temp->next;
            newNode->next = cur;
            temp->next = newNode;
        }
    }
    newNode = newAdjListNode(src); 
    if(graph->array[dest].head==NULL){
        graph->array[dest].head = newNode;    
    }else{
        struct AdjListNode *temp = graph->array[dest].head;
        if(temp->next==NULL && temp->vertex_no<=newNode->vertex_no){
            temp->next = newNode;
        }else if(temp->next==NULL && temp->vertex_no>newNode->vertex_no){
            newNode->next = temp;
        }else{
            while(temp->next!=NULL && temp->next->vertex_no<=newNode->vertex_no){
                temp = temp->next;
            }
            struct AdjListNode *cur = temp->next;
            newNode->next = cur;
            temp->next = newNode;
        }
    }   
}

int isAdjecent(struct Graph *graph,int src,int dest){
    struct AdjListNode *p = graph->array[src].head;
    while(p != NULL){
        if(p->vertex_no == dest){
            return 1;
        }p = p->next;
    }return 0;
}

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

int isEmpty(){		
	if (backPtr == NULL){
		return 1;
	}else{
		return 0;
	}
}

int dequeue(){
	int result;
	if(backPtr != NULL){
		temp = backPtr->next;
		result = temp->item;
		if(backPtr == temp){
			backPtr = NULL;
			free(temp);
		}else{
			backPtr->next = temp->next;
			temp = NULL;
			free(temp);
		}
	}else{
		result = -1;
	}
	return (result);
}

int bfs(struct Graph *graph,int vertex){
	
    graph->visited[vertex] = 1;
    enqueue(vertex);
    while(!isEmpty()){
    	int currentVertex = dequeue();
        printf("%d ", currentVertex);
    	struct AdjListNode *temp = graph->array[currentVertex].head;
    	while(temp){
    		int adjVertex = temp->vertex_no;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            temp = temp->next;
		}
	}
}

int dfs(struct Graph *graph,int vertex){
    struct AdjListNode *temp = graph->array[vertex].head;
    graph->visited[vertex] = 2;
    printf("%d ",vertex);
    while(temp!=NULL) {
      int connectedVertex = temp->vertex_no;
      if(graph->visited[connectedVertex] == 1) {
          dfs(graph, connectedVertex);
      }
      temp = temp->next;
    } 
}


int main(){
	int vertices;
	scanf("%d",&vertices);
	struct Graph *graph = createGraph(vertices);
	
	int edges,u,v;
	scanf("%d", &edges);
	int i;
	for(i=0;i<edges;i++){
		scanf("%d%d",&u,&v);
		addEdge(graph,u,v);
	}
	
	int s;
	scanf("%d", &s);
	bfs(graph,s);
	printf("\n");
	dfs(graph,s);		
	return 0;
}
