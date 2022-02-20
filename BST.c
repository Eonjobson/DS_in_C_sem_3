#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define SIZE 100
int front=-1;
int rear = -1;
int queue[SIZE];
//defining a queue for level order traversal
void insert(int item)  
{  
    
    if(rear == SIZE-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted ");  
      
}  
void delete()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        
        printf("\nvalue deleted %d ",queue[front++]);
    }  
      
      
}  
bool isEmpty(){
	return (rear==SIZE-1);
}
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
}Node;

Node *root=NULL,*new_node;

Node* create(int val){
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;	
	new_node->left = NULL;
	new_node ->right = NULL;
	return new_node;
}
Node* insert(Node* root,int data){
	if(root ==NULL){
		root = create(data);
		
	}
	else if(data <= root->data)
		root->left = insert(root->left,data);
	else 
		root->right = insert(root->right,data);
	return root;
}
bool search(Node* root,int val){
	if(root ==NULL){
		return false;
		
	}
	if(root->data == val)
		return true;
	else if(val>root->data){
		return search((root->right),val);
	}
	else
		return search((root->left),val);
}
Node* GetMin(Node* root){
	while(root->left!=NULL){
		root = root->left;
	}
	return root;
}
Node* delete(Node* root,int val){
	//NULL case
	if(root==NULL)
		return root;
	//quickly search for the node to be deleted
	else if(val<root->data)
		root->left = delete(root->left,val);
	else if (val>root->data)
		root->right = delete(root->right,val);
	
	else{
		//no children
		if(root->left==NULL && root->right==NULL){
			free(root);
			root=NULL;
		}	
		//1 child
		else if(root->left == NULL){
			Node* temp = root;
			root = root->right;
			free(temp);
		}

		else if(root->right == NULL){
			Node* temp = root;
			root = root->left;
			free(temp);
		}
		else{
			Node* new = GetMin(root->right);
			root->data = new->data;
			root->right = delete(root->right,new->data);
		}


	}
	return root;
	

}
void LevelOrder(Node* root){
	if(root==NULL){
		return;
	}
	insert(root->data);
	while(!isEmpty()){
		
	}
}
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d\t",root->data);  //Print data
	Inorder(root->right); }
void Preorder(Node* root){
	if(root==NULL)return;
	printf("%d\t",root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(Node* root){
	if(root==NULL)return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d\t",root->data);
}
//MINIMUM is recursive uptil left and max is rightmost element
int FindHeight(Node* root){
	if(root == NULL){
		return -1;
	}
	return MAX(FindHeight(root->left),FindHeight(root->right))+1;
}
int main()
{
	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4); 
	root = insert(root,1); root = insert(root,11);

	// Deleting node with value 5, change this value to test other cases
	root = delete(root,5);
	Inorder(root);

	return 0;
}
