#include<stdio.h>
#include<stdbool.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
int n = 4;
bool isValid(bool board[n][n],int row,int col){
    //Vertical position
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }
    //Diagonal position
    int maxLeft = MIN(row,col);
    for(int i=1;i<=maxLeft;i++){
        if(board[row-i][col-i]){
            return false;
        }
        
    }
    int maxRight = MIN(row,n-col-1);
    for(int i=1;i<=maxRight;i++){
        if(board[row-i][col+i]){
            return false;
        }
    }
    return true;
}
void display(bool board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j])printf("Q ");
            else printf("X ");
        }
        printf("\n");
    }
}
int solve(bool board[n][n],int row){
    if(row==n){
        printf("\n");
        display(board);
        return 1;
    }
    int count =0;
    for(int col =0;col<n;col++){
        if(isValid(board,row,col)){
            board[row][col]=true;
            count += solve(board,row+1);
            board[row][col]=false;           
        }
    }
    return count;

}
void main(){
    bool board[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=false;
        }
    }
    display(board);
    printf("\n");
    printf("%d",solve(board,0));
}