#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define SIZE 31
int PQ[SIZE];
int rear=0;
int size =0;
void swap(int *x,int *y){
	int temp = *x;
	*x=*y;
	*y=temp;
}
int parent(int i){
	return (i-1)/2;
}
int left(int i){
	int l =  2*i+1;
	if(l<=SIZE && i>=0)
		return l;
	return -1;
}
int right(int i){
	int r = 2*i +2;
	if(r<=SIZE && i>=0)
		return r;
	return -1;	
}

void swim(int index){
	int i=index;
	while(i>0 && (PQ[i]>PQ[parent(i)])){
		swap(&PQ[i],&PQ[parent(i)]);
		i=parent(i);
	}
}

void max_heapify(int index){
	int maxidx =index;
	int l = left(index);
	int r = right(index);
	if(l<=rear && l>=0){
		if(PQ[l]>PQ[maxidx])
			maxidx = l;
	}
	if(r<=rear && r>=0){
		if(PQ[r]>PQ[maxidx])
			maxidx = r;
	}
	if(maxidx!=index){
		swap(&PQ[maxidx],&PQ[index]);
		max_heapify(maxidx);
	}
}
void sink(int index){
	max_heapify(index);

}
void insert(int element){
	rear++;
	PQ[rear]=element;
	swim(rear);

}
int delete(){
	int max = PQ[0];
	PQ[0]=PQ[rear];
	rear--;
	sink(0);
	return max;
}
void display(){
	for(int i=0;i<rear;i++){
		printf("%d\t",PQ[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	
	
	
	insert(9);
	insert(8);
	insert(6);
	insert(5);
	insert(18);
	display();
	printf("\n%d",delete());
	printf("\n%d",delete());
	//display();
	//printf("%d\t",delete());
	//printf("%d\t",delete());

	
	
	return 0;
}