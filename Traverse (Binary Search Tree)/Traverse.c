#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_content{
	int item;
	struct node_content *left, *right;
}node_type;

node_type *createNewNode(int data){
	node_type *new_node;
	new_node = (node_type*) malloc(sizeof(node_type));
	new_node->item = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return(new_node);
}

node_type *insert(node_type *root, node_type *new_node){
	node_type *p, *prevous;
	if(root == NULL){
		root = new_node;
	}else{
		p = root;
		while(p != NULL){
			prevous = p;
			if(p->item > new_node->item){
				p = p->left;
			}else{
				p = p->right;
			}
		}if(prevous->item > new_node->item){
			prevous->left = new_node;
		}else{
			prevous->right = new_node;
		}
	}return(root);
}

void preOrder(node_type *root){
	if (root != NULL){
		printf("%d ", root->item);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(node_type *root){
	if (root != NULL){ 
        inOrder(root->left); 
        printf("%d ", root->item); 
        inOrder(root->right); 
    } 
}

void postOrder(node_type *root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->item);
	}
}



int main(){
	node_type *root = NULL;
	int num;
	int data;
	int count = 0;
	scanf("%d", &num);
	while (count < num){
		scanf("%d", &data);
		root = insert(root,createNewNode(data));
		count++;
	}
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	return 0;	
}
