#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void main(){
    int table[126];
    char text[100];
    char pattern[25];
    printf("Enter text: \t");
    gets(text);
    printf("\n Enter Pattern \t");
    gets(pattern);
    int textLength = strlen(text);
    int PatternLength = strlen(pattern);
    for(int i=0;i<126;i++){
        table[i] = textLength;
    }
    for(int i=0;i<PatternLength ;i++){
        table[pattern[i]] = PatternLength-i-1;
    }
    //Hello WORD
    //WORD : 3 2 1 0 : 4 
    int i=PatternLength-1;
    int k=0;
    bool flag = false;
    while(i<textLength){
        while(k<PatternLength && pattern[PatternLength-k-1]==text[i-k]){
            k++;
        }
        if(k==PatternLength){
            printf("Found @ position %d\n",i-PatternLength+1);
            flag = true;
            break;
        }
        else{
            i+=table[text[i]];
        }
    }
    if(!flag){
        printf("\nNot found");
    }


} 