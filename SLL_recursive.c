//Insert, Delete, Search in SLL using recursion
/**
 * [X]Insert
 * [X]Delete
 * [X]Search
 * [X]Print
 * **/
#include <stdio.h>
#include <stdlib.h>

//Node definition
typedef struct  Node
{
	int data;
	struct Node* next;
}Node;

//Global declarations
Node *head=NULL,*new_node,*ptr,*search_ptr;
int search_ptr_index=0;
int size=0;
//Create_Node helper function
Node* create(int val){
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}


//Insert
//Insert anywhere based on index
Node* insert(Node* head,int val,int index){
	if(index==0){
		 new_node = create(val);
		 new_node->next = head;
		 size++;
		 return new_node;
	}
	head->next = insert(head->next,val,index-1);
return head;
}
Node* insert_begin(Node* head,int val){
	head = insert(head,val,0);
	return head;
}
Node* insert_end(Node* head,int val){
	
	head = insert(head,val,size);
	return head;
}


Node* search(Node* head,int element){
	if(head==NULL){
		return NULL;
	}
	if(head->data==element){
		return head;
	}
	search_ptr_index++;
	head = search(head->next,element);


}
int FindIndexOf(int element){
	search_ptr_index=0;
	search_ptr = search(head,element);
	if(search_ptr!=NULL){
		return search_ptr_index;
	return -1;

	}
}
//Deletion using recursion
/**Note:Rather than creating multiple functions for delete such as delete start, end and anywhere
 * We create a single delete function which deletes solely based on the value the user wishes to delete
 * In case of deleting the first element, the function is designed to assign head pointer to the next node
 * Deleting last can be done by putting the value of the last Node in the function,and the same follows for 
 * the values of the other nodes in the list **/
Node* Delete(Node* head,int val){
	if(head->data==val){
		Node* temp = head;
		head = head->next;
		free(temp);
		size--;
		return head;}

	head->next = Delete(head->next,val);
	return head;
}

void display(Node* head){
	if(head==NULL){
		return;
	}
	printf("%d\t",head->data);
	display(head->next);	
}
int main(int argc, char const *argv[])
 {

 head = insert_end(head,5);
 head = insert_end(head,7);
 printf("%d",FindIndexOf(7));
 printf("\nhead value is %d\n",head->data);
 display(head);
 return 0;	
//head=insert_begin(8);
// 	head=insert_end(head,5);
// 	head=insert_end(head,7);
// 	head = insert(head,6,1);
// 	//search
// 	display(head);
// 	head = Delete(head,5);
// 	search_ptr = search(head,6);
// 	if(search_ptr!=NULL){
// 		printf("\nFound!!\n");
// 	}
// 	else{
// 		printf("Not found");
// 	}
// 	printf("\n");
// 	display(head);
// 	printf("\n");
// 	head = Delete(head,8);
// 	printf("\n");
// 	printf("%d",head->data);
// 	return 0;
}
