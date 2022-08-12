#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define V 5
#define INF 99999
bool visited[V];
bool isValid(int u,int v){
    if(u==v)return false;
    if((visited[u] && visited[v]) || (!visited[u] && !visited[v]))return false;
    return true;
}
void PrimsMST(int graph[V][V]){
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    int nodes[V]={INT_MAX};
    //nodes[0]=0;
    visited[0]=true;
    int curr =0;
    int cost =0;
    int edges =0;
    while(edges<V-1){
      int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {            
                if (graph[i][j] < min)
                {
                    if (isValid(i, j))
                    {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        visited[a]=visited[b]=true;
        edges++;
        cost+=min;

}
printf("\nToTal cost = %d",cost);
}
void main(){
    int graph[5][5] = {
        { INF, 2, INF, 6, INF },
        { 2, INF, 3, 8, 5 },
        { INF, 3, INF, INF, 7 },
        { 6, 8, INF, INF, 9 },
        { INF, 5, 7, 9, INF },
    };
    PrimsMST(graph);

}

