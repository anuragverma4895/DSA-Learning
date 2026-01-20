#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void DFS_iterative(int adj[MAX][MAX], int start, int n) {
    int visited[MAX] = {0};
    int stack[MAX], top = -1;
    
    stack[++top] = start; // Push start node to stack
    
    while (top != -1) {
        int vertex = stack[top--]; // Pop from stack

        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;
        }

        for (int i = n - 1; i >= 0; i--) { // Push unvisited adjacent nodes
            if (adj[vertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
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

    printf("DFS Traversal (Iterative): ");
    DFS_iterative(adj, 0, MAX); // Start DFS from node 0

    return 0;
}
