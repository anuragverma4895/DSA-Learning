#include <stdio.h>

#define MAX 5

int visited[MAX];

void DFS_recursive(int adj[MAX][MAX], int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS_recursive(adj, i, n);
        }
    }
}

int main() {
    // Predefined adjacency matrix for a 5-vertex graph
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    for (int i = 0; i < MAX; i++) 
        visited[i] = 0;

    printf("DFS Traversal (Recursive): ");
    DFS_recursive(adj, 0, MAX); // Start DFS from node 0

    return 0;
}
