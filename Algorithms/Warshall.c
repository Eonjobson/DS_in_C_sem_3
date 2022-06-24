#include <stdio.h>
#include <stdbool.h>
#define INF 999
int min(int a, int b) // function to return minimum of two numbers
{

    if (a < b)
        return a;

    else

        return b;
}
void print_matrix(int n, int graph[][n]) // function to print matrix
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)

            printf("%d ", graph[i][j]);

        printf("\n");
    }
}
void floyds_algo(int n, int graph[][n]) // function of the algorithm
{

    for (int k = 0; k < n; k++)

        for (int i = 0; i < n; i++)

            for (int j = 0; j < n; j++)

                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    print_matrix(n, graph);
}
void warshall_algo(int n, int graph[][n])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] || graph[i][k] && graph[k][j])
                    graph[i][j] = true;
            }
        }
    }
}
int main() // main method
{
    int v = 4;

    int graph[][4] = {{0, 9, -4, INF},

                      {6, 0, INF, 2},
                      {INF, 5, 0, INF},
                      {INF, INF, 1, 0}};
    floyds_algo(4, graph); // passing the adjacency matrix of the graph
}