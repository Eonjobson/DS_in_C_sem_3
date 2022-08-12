#include<stdio.h>
#include<stdbool.h>
#define INF 999999
#define V 9
bool visited[V];
int distance[V];
int getMinCost(){
    int min = INF;
    int min_idx;
    for(int v=0;v<V;v++){
        if(!visited[v] && distance[v]<min){
            min = distance[v];
            min_idx = v;
        }
    }
    return min_idx;
}
printSolution(){
    printf("Vertex \t\t Distance\n");
    for(int i=0;i<V;i++){
        printf("%d \t\t %d\n",i,distance[i]);
    }
}
void Djikstras(int graph[V][V],int source){
    //Initialize dist and visited 
    for(int i=0;i<V;i++){
        visited[i] = false;
        distance[i] = INF;
    }
    distance[source] = 0;
    for(int count =0;count<V-1;count++){
        int u = getMinCost();
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && (distance[v]>distance[u]+graph[u][v])){
                distance[v] = distance[u]+graph[u][v];
            }
        }
    }
    printSolution();
}
int main(int argc, char const *argv[])
{
int graph[V][V]= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    Djikstras(graph,0);
    return 0;
}
