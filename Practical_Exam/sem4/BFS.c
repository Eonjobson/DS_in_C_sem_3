#include<stdio.h>
#include<stdbool.h>
#define V 5
int front = -1;
int rear = -1;
int Q[3*V];
bool visited[V];
int adj[V][V];
void push(int node){
    if (front == -1 && rear == -1){
        front = rear = 0;
    }
    Q[rear++] = node;
}
int delete(){
    return Q[front++];
}
bool isEmpty(){
    if(front>rear || rear == -1){
        return true;
    }
    return false;
}
void addEdge(int from,int to){
    adj[to][from]=1;
    adj[from][to]=1;
}
void BFS(int start){
    visited[start] = true;
    push(start);
    int vis;
    while(!isEmpty()){
        vis = delete();
            // Print the current node
        printf("%d ",vis); 
        for(int i=0;i<V;i++){
            if(adj[start][i]==1 && !visited[i]){
                push(i);
                visited[i] = true;
            }
        }
    }
}
void main(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            adj[i][j] = 0;
        }
    }
    
        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(2, 3);
        addEdge(1, 4);
        for(int i=0;i<V;i++){
            visited[i] =false;
        }
        BFS(0);
}