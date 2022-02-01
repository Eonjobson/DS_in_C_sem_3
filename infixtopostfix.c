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
char* evaluate(char infix[],char postfix[]){
	int j=0;
	for(int i=0;infix[i]!='\0';i++){
		if(infix[i] == '('){
			push(infix[i]);
		}
		else if(isalnum(infix[i])){
			postfix[j++] = infix[i];
		}
		else if(infix[i]==')'){
			while(peek()!='('){
				postfix[j++]=pop();
			}
			pop();
		}
		else{
			while(precedence(peek())>precedence(infix[i])){
				postfix[j++]=pop();
			}
			push(infix[i]);
		}
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
        printf("\n*********************************************");
        printf("\nProgram to convert infix to postfix");
        printf("\nEnter the infix expression:\t");
        gets(infix);
        evaluate(infix,postfix);
        printf("\n");
        puts(postfix);
	return 0;
}