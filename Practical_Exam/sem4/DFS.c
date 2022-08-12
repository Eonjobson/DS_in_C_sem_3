#include<stdio.h>
#include<stdbool.h>
int V =5;
int adj[5][5];
bool visited[5];
void addEdge(int from,int to){
    adj[from][to] = 1;
    adj[to][from] = 1;
}
void DFS(int start){
    printf("%d ", start);
    visited[start]=true;
    for(int i=0;i<V;i++){
        if(adj[start][i]==1 && !visited[i]){
            DFS(i);
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
        addEdge(0, 3);
        addEdge(0, 4);
        for(int i=0;i<V;i++){
            visited[i] =false;
        }
        DFS(0);

    
}