#include <stdio.h>
#include<stdlib.h>
#define SIZE 6
int q[SIZE];
int front =-1;
int rear = -1;
//rear for insert
// front for delete
//Circular queue
void enqueue(){
	printf("Enter value to insert\n");
	int val;
	scanf("%d",&val);
	if(front==-1 && rear == -1){
		front =0;
		rear = 0;
		q[rear]=val;

	}
	else if((rear+1)%SIZE == front){
		printf("Overflow");
		return;
	}
	else{
		rear = (rear+1)%SIZE;
		q[rear]=val;
	}
}
int dequeue(){
	int deq;
	if(front==-1 && rear == -1){
		printf("underflow");
		return -1;
	}
	else if(front==rear){
		deq = q[rear];
		front =-1;
		rear = -1;

	}
	else{
		deq = q[front];
		front = (front + 1)%SIZE;
	}
	return deq;
}
void display(){
	if(front==-1 && rear == -1){
		printf("Empty Queue\n");
	}
	else{
		for(int i=front;i<=rear;i++){
			printf("%d\t",q[i]);
		}
	}
}
void main(){
	int ch,n;
	do{
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: enqueue();
			break;
			case 2:
			n = dequeue();
			if(n!=-1)
				printf("dequeued element is %d",n);
			break;
			case 3: display();
			break;
			case 4:
			break;
			default:printf("Invalid");

		}

	}while(ch!=4);
}