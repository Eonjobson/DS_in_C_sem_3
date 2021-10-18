//push,pop peek using array stacks
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int st[MAX],top = -1;
void push(int);
int peek();
int pop();
void display();
int main()
{
    int val,choice;
    do{
        printf("\n*****MAIN MENU*****");
        printf("\n 1.PUSH \n 2.POP\n 3.PEEK\n 4.DISPLAY\n 5.EXIT\n Enter your option\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter no. to be pushed into the stack\n");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            val=pop();
            if(val!=-1){
                printf("value popped is %d",val);
            }
            break;
        case 3:
            //peek
            val = peek();
            if(val!=-1){
                printf("The top value of the stack is %d",val);

            }
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("enter one of the given options or 5 to exit\n");
            break;
        }}while(choice!=5);
    
    return 0;}



void push(int val){
    if(top==MAX-1){
        printf("Stack overflow");
        return;
    }
    else{
        top++;
        st[top]=val;
    }
}
int peek(){
    if(top==-1){
        printf("Stack is empty");
        return -1;
    }
    return (st[top]);
}
int pop(){
    if(top==-1){
        printf("stack underflow");
        return -1;
    }
    else{
        int val = st[top];
        top--;
        return val;
    }
    
}
void display(){
    int i;
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        for(i=top;i>=0;i--){
            printf("\n%d\t",st[i]);
        }
    }
}
