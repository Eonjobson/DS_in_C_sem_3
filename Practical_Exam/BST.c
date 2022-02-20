#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* root =NULL,*new_node,*ptr;
Node* create(int data){
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right =NULL;
	return new_node;
}
Node* insert(Node* root,int val){
	if(root==NULL){
		root = create(val);
	}
	else if (root->data>=val)
	{
		root->left = insert(root->left,val);
	}
	else{
		root->right = insert(root->right,val);
	}
	return root;
}
Node* GetMin(Node* root){
	while(root->left!=NULL){
		root = root->left;
	}
	return root;
}
Node* Delete(Node* root,int val){
	if(root==NULL)
		return root;
	else if(val<root->data){
		root->left = Delete(root->left,val);
	}
	else if(val>root->data){
		root->right = Delete(root->right,val);
	}
	else{
		//No children
		if(root->left==NULL && root->right ==NULL){
			free(root);
			root =NULL;

		}
		//1 child
		else if(root->left==NULL){
			Node* temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right==NULL){
			Node* temp = root;
			root = root->left;
			free(temp);
		}
		else{
			//2 children
			Node* temp =GetMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
void inorder(Node* root){
	if(root==NULL)return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void main(){
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,3);
	root=insert(root,2);
	root=insert(root,20);
	root=insert(root,15);
	inorder(root);
	root = Delete(root,10);
	inorder(root);	
}