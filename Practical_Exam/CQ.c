#include <stdio.h>
#define SIZE 5
int Q[SIZE];
int front =-1;
int rear =-1;
void enqueue(int val){
	if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		Q[rear]=val;
	}
	else if((rear+1)%SIZE == front){
		printf("Overflow\n");
		return;
	}
	else{
		rear = (rear+1)%SIZE;
		Q[rear]=val;
		

	}
}
int dequeue(){
	int del;
	if(front==-1 && rear ==-1){
		printf("Underflow\n");
		return -1;
	}
	else if(front==rear){
		del = Q[front];
		front =-1;
		rear =-1;
	}
	else{
		del = Q[front];
		front = (front+1)%SIZE;
	}
	return del;
}
void display(){
	if(front == -1 && rear == -1){
		printf("Empty Queue");
		return;
	}
	int i=front;
	do{
		printf("%d",Q[i]);
		i=(i+1)%SIZE;
	}while(i!=(rear+1)%SIZE);
}
void main()
{
	int ch,n;
	do{
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		int val;
		switch(ch){
			case 1: 
			printf("\nEnter value to enqueue\t");
			scanf("%d",&val);
			enqueue(val);
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
	
