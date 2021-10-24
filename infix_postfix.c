#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
int st[MAX],top = -1;
void push(char);
char peek();
char pop();
void display();
bool isoperator(char);
int prec(char);
bool isoperator(char symbol){
    if(symbol == '+' ||symbol == '-' ||symbol == '*' ||symbol == '/'){
        return true;
    }
    return false;
}
int prec(char operator){
    if(operator == '^'){
        return (3);
    }
    else if (operator == '*' || operator == '/')
    {
        return (2);
    }
    else if (operator == '+' || operator == '-'){
        return (1);
    }
    else{

        return (0);
    }
}
char* infixtopostfix(char prefix[]){
    //enclose the string in ()
    int i,j;
    char x;
    char postfix[strlen(prefix)];
    i=0;
    j=0;
    char element = prefix[i];
    push('(');
    strcat(prefix,')');
    //start reading
    while(element != '\0'){
        if(element == '('){
            push(element);
        }
        else if(element == ')'){
           x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
        }
        else if(isoperator(element)){
           x= peek();
           while(isoperator(x) && prec(x)>=prec(element)){
               postfix[j] = x;
               j++;
               x=pop();
           }
           push(element);
        }
        else if(isdigit(element)||isalpha(element)){
            postfix[j]=element;
            j++;
        }
        else{
            printf("\nInvalid\n");
            exit(1);
        }
        i++;
    }
    if(top>0){
        printf("Invalid infix");
        exit(1);
    }
    postfix[j]='\n';
    return postfix;
    }







void push(char val){
    if(top==MAX-1){
        printf("Stack overflow");
        return;
    }
    else{
        top++;
        st[top]=val;
    }
}
char peek(){
    if(top==-1){
        printf("Stack is empty");
        return -1;
    }
    return (st[top]);
}
char pop(){
    if(top==-1){
        printf("stack underflow");
        return -1;
    }
    else{
        char val = st[top];
        top--;
        return val;
    }
    
}
