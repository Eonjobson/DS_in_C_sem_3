#include <stdio.h>
#include <stdlib.h>
//Insert, delete, display,search
//Contains reverse and stacks and queues are an extension of it

typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node *head=NULL,*ptr,*preptr,*searchptr,*new_node,*tail=NULL;
int size=0;
Node* create(int data){
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
void insertFirst(int val){
	new_node = create(val);
	new_node->next = head;
	head = new_node;
	if(tail==NULL){
		tail=head;
	}
	size++;
}
void insertLast(int val){
	new_node = create(val);
	if(tail==NULL){
		insertFirst(val);
		return;
	}
	tail->next = new_node;
	tail = new_node;
	size++;
}
void insert(int val,int index){
	new_node = create(val);
	if(index==0){
		insertFirst(val);
		return;
	}
	if(index==size){
		insertLast(val);
		return;
	}
	ptr =head;
	for(int i=1;i<index;i++){
		ptr=ptr->next;
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
	size++; 
}
Node* get(int index){
	searchptr = head;
	for(int i=0;i<index;i++){
		searchptr = searchptr->next;
	}
	return searchptr;
}
void deleteFirst(){
	if(head==NULL){
		return;
	}
	ptr = head;
	head = head->next;
	free(ptr);
	size--;
}
void deleteLast(){
	if(size<=1){
		deleteFirst();
	}
	Node* secondLast = get(size-2);
	ptr = tail;
	secondLast->next = NULL;
	tail = secondLast;
	free(ptr);
	size--;
}
void delete(int index){
	if(index==0){
		deleteFirst();
		return;
	}
	if(index==size){
		deleteLast();
		return;
	}
	preptr = get(index-1);
	ptr=preptr->next;
	preptr->next = ptr->next;
	free(ptr);
	size--;
}
void display(){
	if(head==NULL){
		printf("Empty\n");
		return;
	}
	ptr=head;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void reverse(){
	Node* prev=NULL;
	Node* curr = head;
	Node* next = curr->next;
	while(curr!=NULL){
		curr->next = prev;
		prev = curr;
		curr = next;
		if(next!=NULL){
			next = next->next;
		}
		

	}
	head = prev;
}
int main()
{
	insertFirst(5);
	insertLast(6);
	insertLast(8);
	insertLast(9);
	insert(7,1);
	display();
	deleteFirst();
	display();
	deleteLast();
	display();
	delete(1);
	insertFirst(11);
	insertLast(12);

	display();
	reverse();
	display();
	return 0;
}
