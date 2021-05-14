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



node_type *delete(node_type *root, int data){ 
	if (root == NULL){
		printf("no");
		return(root);
	}if (data < root->item){
		root->left = delete(root->left, data); 
	}else if (data > root->item){
    	root->right = delete(root->right, data); 
	}else{
		if(root->left == NULL){ 
            node_type *temp = root->right; 
            free(root); 
            printf("yes");
            return(temp); 
        }else if (root->right == NULL){ 
            node_type *temp = root->left; 
            free(root); 
            printf("yes");
            return(temp); 
        }else{
        	node_type *temp = root; 
            temp = temp->right;
            while (temp->left != NULL){
              temp = temp->left;
            }
            int deletenode = temp->item;
            delete(root,temp->item);
            root->item = deletenode;
		}
	}
	return(root); 	
}

node_type *LeafNode(node_type *root){ 
    if (root == NULL){
    	return(root);
	}if (root->left==NULL && root->right==NULL){ 
      printf("%d ",root->item);  
    }if (root->left){
    	LeafNode(root->left);
	}if(root->right){
		LeafNode(root->right); 
	}       
} 

void show(node_type *root){
	if(root != NULL){
		node_type *temp1 = root;
    	while(temp1 != NULL){
        	printf("%d ", temp1->item);
        	temp1 = temp1->left;
    	}printf("\n");
    	node_type *temp2 = root;
    	while(temp2 != NULL){
        	printf("%d ", temp2->item);
        	temp2 = temp2->right;
    	}
    	printf("\n");
    	LeafNode(root);
	}
}

int main(){
	node_type *root = NULL; 
	int num;
	int data;
	scanf("%d", &num);
	while(num<=3 && num>0){
		if(num == 1){
			scanf("%d",&data );
			root = insert(root,createNewNode(data));
		}else if(num == 2){
			scanf("%d",&data );
			root = delete(root,data);
			printf("\n");
		}else if(num == 3){
			show(root);
			printf("\n");
		}
	scanf("%d", &num);
	}if(num == 4){
		return 0;
	}
}
