#include <stdio.h>
#include<stdbool.h>
#define INF 99999
#define MIN(a,b) (((a)<(b))?(a):(b))
int n =4;
void Floyd(int graph[n][n]){
    //Finding transitive closure 
    //Which basically says if a path exists before keep it,if it 
    //didn't exist before but exists now, add it, use Logical OR
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;i<n;j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
        }
        }
    }
}
void Warshall(int graph[n][n]){
    printf("Warshall\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
   
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;i<n;j++){
                graph[i][j] = MIN(graph[i][j],graph[i][k]+graph[k][j]);
        }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    
}
int main()
{
    //int graph[4][4] = { {0,1,0,1},{0,1,0,0},{0,0,0,1},{1,0,1,0}};
     int graph[4][4] = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} };
   
    
    Warshall(graph);
    
}
