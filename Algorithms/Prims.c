#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define INF 999999
#define V 5
int findMinkey(bool mst[], int key[], int n)
{
    int min = INF;
    int minIndex;
    for (int i = 0; i < n; i++)
    {
        if (mst[i] == false && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void Prims(int graph[V][V], int n)
{
    bool mst[n];
    int key[n];
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        mst[i] = false;
        key[i] = INF;
    }
    key[0] = 0;
    mst[0] = true;
    parent[0] = -1;
    for (int c = 0; c < n - 1; c++)
    {
        int u = findMinkey(mst, key, n);
        mst[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mst[v] == false && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST(parent, graph);
}
void main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    Prims(graph, V);
}