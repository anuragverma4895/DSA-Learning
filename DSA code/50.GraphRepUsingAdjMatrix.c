#include <stdio.h>

#define MAX_VERTICES 10  // Maximum number of vertices

// Function to initialize the adjacency matrix
void initializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    // Initialize all entries of the matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;  // Since it's an undirected graph, also set the reverse edge
    graph[v][u] = 1;  // Set the reverse edge as well
}

// Function to print the adjacency matrix
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, u, v;
    
    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Initialize the graph with 0s (no edges)
    initializeGraph(graph, vertices);

    // Input the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input the edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        // Add the edge to the graph
        addEdge(graph, u, v);
    }

    // Print the adjacency matrix
    printGraph(graph, vertices);

    return 0;
}
