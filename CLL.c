#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
	
}node;
node *head=NULL,*tail=NULL,*new_node,*ptr,*pre_ptr;
//insert anywhere, delete anywhere
node* create(){
	int val;
	printf("Enter value of node\n");
	scanf("%d",&val);
	new_node = (node*)malloc(sizeof(node));
	new_node->next =NULL;
	new_node->data = val;
	return val;
}
void insert_start(){
	new_node = create();
	if(head==NULL && tail ==NULL){
		head = new_node;
		tail = head;
		tail->next = head;
		return;
	}
	new_node->next = head;
	tail->next = new_node;
	head = new_node;

}
void insert_end(){
	new_node = create();
	if(tail==NULL){
		insert_start();
	}
	new_node->next = head;
	tail->next = new_node;
	tail = new_node;

}
void insert_any(int element){
	new_node = create();
	if(head=NULL){
		insert_start();
	}
	ptr = head;
	if(element==head->data){
		insert_start();
	}
	ptr = ptr->next;
	else{
		while(element!=ptr->data && ptr!=head){
			ptr = ptr->next;
		}
		if(element == ptr->data){
			if(ptr == tail){
				insert_end();
			}
			else{
				new_node->next = ptr->next;
				ptr->next = new_node;
			}
		}
	}



}
void delete_start(){
	ptr = head;
	tail->next = ptr->next;
	head = ptr->next;
	free(ptr);
}
void delete_end(){
	ptr = head;
	while(ptr->next!=tail){
		ptr = ptr->next;
	}
	ptr->next = head;
	free(tail);
	tail = ptr;
}
void delete_any(int element){
	ptr = head;
	pre_ptr = head;
	if(element == head->data){
		delete_start();
	}
	else if(element == tail->data){
		delete_end();
	}
	else{
		ptr = head->next;
		while(ptr->data!=element && ptr!=head){
			pre_ptr = ptr;
			ptr = ptr->next;
		}
		if(ptr!=head){
			pre_ptr->next = ptr->next;
			free(ptr);

		}
	}
}