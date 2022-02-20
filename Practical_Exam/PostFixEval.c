#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50
int top =-1;
char stack[MAX];
void push(char a){
	if(top == MAX -1){
		printf("Stack overflow\n");
		return;
	}
	else{
		stack[++top] = a;
	}
}
char pop(){
	if(top == -1){
		return '0';
	}
	else{
		return stack[top--];
	}
}
char peek(){
	if(top == -1){
		return '0';
	}
	else{
		return stack[top];
	}
}
int is_operator(char symbol){
	if(symbol == '+' || symbol == '-' ||symbol == '*' ||symbol == '/' ||symbol == '^'){
		return 1;
	}
	else{
		return 0;
	}
}
int precedence(char symbol){
	switch(symbol){
		 case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '%':
            return 3;
        case '/':
            return 3;
		case '^':
        case '$':
			return 4;
        default:
            return -1;
	}
}
void Evaluate(char* postfix){
 for(int i=0;postfix[i]!='\0';i++){
 	if(isdigit(postfix[i])){
 		push(postfix[i]-'0');
 	}
 	else if(isalpha(postfix[i])){
 		push(postfix[i]);
 	}
 	else if(is_operator(postfix[i])){
 		int op1 = pop();
 		int op2 = pop();
 		switch(postfix[i]){
 			case '+':
 				 push(op2+op1);
 				 break;
 			case '-':
 				 push(op2-op1);
 				 break;	
 			case '*':
 				 push(op2*op1);
 				 break;	
 			case '/' :
 				if(op1==0){
 					printf("\nNaN\n");
 					break;
 				}
 				else
 				 	push(op2/op1);
 				
 				break;

 			case '^':
 				push(op2^op1);
 				break;
 			}
 		}
 	}
 	printf("\nValue is = %d",pop());

}
int main(int argc, char const *argv[])
{
	char postfix[MAX];
	printf("Enter postfix\t");
	gets(postfix);
	Evaluate(postfix);
}