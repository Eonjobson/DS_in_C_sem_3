public boolean isBipartite(int[][] graph) {
    int vertexCount = graph.length;
    int color[] = new int[vertexCount];
    Arrays.fill(color, -1);
    
    for (int i=0; i<vertexCount; i++) {
        if (color[i] != -1) continue;
        boolean isPossible = dfs(graph, i, color);    //implementation of dfs approach  
        //boolean isPossible = bfs(graph, i, color);  //implementation of bfs approach
        if (!isPossible) return false;
    }
    return true;
}

public boolean dfs(int[][] graph, int curr, int[] color) {
    if (color[curr] == -1) {
        color[curr] = 1;
    }
    for (int neighbour: graph[curr]) {
            if(color[neighbour] == -1) {
                color[neighbour] = color[curr] == 1 ? 2 : 1;
                if (!dfs(graph, neighbour, color)) {
                    return false;
                }
            }
            else if (color[neighbour] == color[curr]) {
                return false;
            }
    }
    return true;
}