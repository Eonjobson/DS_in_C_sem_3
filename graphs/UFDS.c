#include<stdio.h>
int graph[10000][10000];
int parent[10000];
int size[10000];
int find(int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u] = find(parent[u]);
}
void union(int v,int u){
    if(size[u]>size[v]){
        parent[v]=u;
        size[u]++;
    }
}
int main()
{ return 0;}