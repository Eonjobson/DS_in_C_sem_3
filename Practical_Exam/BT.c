#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
}Node;

Node *root=NULL;

Node* create(){
	Node* new_node;
	int val;
	printf("\nEnter value of node or -1 for null\n");
	scanf("%d",&val);
	if(val==-1){
		return NULL;
	}
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	printf("\nenter left child");
	new_node->left = create();
	printf("\nenter right child");
	new_node->right = create();
	return new_node;
}

void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d\t",root->data);  //Print data
	Inorder(root->right); }
void main(){
	root = create();
	printf("Inorder traversal of tree is\n");
	Inorder(root);
	
}