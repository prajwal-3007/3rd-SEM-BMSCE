#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int n;               // number of vertices

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dfs(start);

    // check connectivity
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is connected\n");
    else
        printf("Graph is NOT connected\n");

    return 0;
}
