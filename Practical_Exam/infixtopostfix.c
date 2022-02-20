#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 50
char stack[MAX];
int top = -1;

void push(char x){
	if(top==MAX-1){
		printf("Overflow\n");
		return;
	}
	stack[++top]=x;
}
char peek(){
	if(top==-1){
		return '0';
	}
	return stack[top];
}
char pop(){
	if(top==-1)
		return '0';
	return stack[top--];
}
int precedence(char x){
	switch(x){
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
		case '$':
			return 3;

		default:
			return -1;
	}
}
int IsOperator(char x){
	switch(x){
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '$':
		case '^':
			return 1;
		default:
			return 0;
	}
}
char* Convert(char infix[],char postfix[]){
	int i=0;
	int j=0;
	while(infix[i]!='\0'){
		if(infix[i]=='('){
			push(infix[i]);

		}
		else if(isalnum(infix[i])){
			postfix[j++]=infix[i];
		}
		else if(infix[i]==')'){
			while(peek()!='('){
				postfix[j++] = pop();
			}
			pop();
		}
		else{
			while(precedence(peek())>=precedence(infix[i])){
				postfix[j++]=pop();
			}
			push(infix[i]);
		}
		i++;
	}
		while(peek()!='0'){
			postfix[j++]=pop();
		}
		postfix[j]='\0';
		return postfix;

	}

int main(int argc, char const *argv[])
{
	char infix[MAX];
	char postfix[MAX];
	printf("Enter infix\n");
	gets(infix);
	
	printf("\npostfix is %s\t",Convert(infix,postfix));
	
	return 0;
}