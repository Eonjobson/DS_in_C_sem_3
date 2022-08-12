#include <stdio.h>
#define INF 99999
int V=5;
int parent[10];
int size[10];
int find(int x){
    if(x==parent[x]){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);
    }
}
void Union(int a,int b){
    if(size[a]>=size[b]){
        parent[b] = a;
        size[a]++;
    }
    else {
        parent[a]=b;
        size[b]++;
}
}
void MST_Kruskal(int graph[V][V]){
    //Initialize parents Array
    for(int i=0;i<V;i++){
        parent[i] = i;
        size[i]=1;
    }
    int cost = 0;
    int edges = 0;
    while(edges<V-1){
        int min = INF;
        int a = -1;
        int b = -1;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
            if(find(i)!=find(j) && graph[i][j]<min){
                    min = graph[i][j];
                    a =i;
                    b=j;
                }
             }
            
        }
        Union(a,b);
        cost+=min;
        printf("%d -> %d : %d",a,b,min);
        edges+=1;
    }
    printf("Minimum Cost = %d",cost);
}
void main(){
    int graph[5][5] = {
        { INF, 2, INF, 6, INF },
        { 2, INF, 3, 8, 5 },
        { INF, 3, INF, INF, 7 },
        { 6, 8, INF, INF, 9 },
        { INF, 5, 7, 9, INF },
    };
    MST_Kruskal(graph);
}
    
        
    

