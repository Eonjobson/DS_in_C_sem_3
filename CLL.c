#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
Node *head=NULL,*tail = NULL,*ptr,*preptr,*new_node;
int size=0;
Node* create(int val){
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data =val;
	new_node->next;
	return new_node;
}
void InsertBegin(int val){
	new_node = create(val);
	if(head==NULL){
		head = new_node;
		tail = head;
		tail->next = head;
		size++;
		return;
	}
	tail->next = new_node;
	new_node->next = head;
	head = new_node;
	size++;
}
void InsertEnd(int val){
	new_node = create(val);
	if(tail==NULL){
		head = new_node;
		tail = head;
		size++;
		return;
	}
	tail->next = new_node;
	new_node->next = head;
	tail= new_node;
	size++;
}
void insertAny(int val,int index){
	//take index%length of the linkedlist and insert accordingly
	int idx = index%size;
	if(idx==0){
		InsertBegin(val);
		return;
	}
	if(idx==size){
		InsertEnd(val);
		return;
	}
	ptr = head;
	for(int i=0;i<idx-1;i++){
		ptr = ptr->next;
	}
	//Reached desired index now insert
	new_node = create(val);
	new_node->next = ptr->next;
	ptr->next = new_node;
	size++;
}
void deleteBegin(){
	if(head==NULL){
		printf("Empty\n");
		return;
	}
	ptr = head;
	head = head->next;
	tail->next = head;
	free(ptr);
	size--;

}
void DeleteEnd(){
	if(tail==NULL){
		printf("Empty list\n");
		return;
	}
	ptr=head;
	preptr = head;
	while(ptr!=tail){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = head;
	tail = preptr;
	free(ptr);
	size--;

}
void Delete(int idx){
	int index = idx%size;
	if(head==NULL){
		printf("Empty\n");
		return;
	}
	if(index ==0){
		deleteBegin();
		return;
	}
	if(index==size){
		DeleteEnd();
		return;
	}
	ptr = head;
	for(int i=0;i<index;i++){
		preptr=ptr;
		ptr = ptr->next;
	}
	preptr->next = ptr->next;
	free(ptr);
	size--;



}
void display(){
	if(head==NULL){
		printf("Empty list\n");
		return;
	}
	ptr = head;
	do{
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}while(ptr!=head);
	printf("\n");
	
}
void main()
{
	/* code */
	InsertBegin(1);
	InsertEnd(2);
	InsertEnd(4);
	insertAny(3,5);
	display();
	deleteBegin();
	display();
	DeleteEnd();
	display();
	InsertEnd(4);
	InsertEnd(5);
	display();
	Delete(2);
	display();
}
