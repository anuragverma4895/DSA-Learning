#include <stdio.h>

#define MAX 100  

int queue[MAX], front = 0, rear = 0;
int visited[MAX] = {0};

// Function to enqueue an element
void enqueue(int v) {
    queue[rear++] = v;
}

// Function to dequeue an element
int dequeue() {
    return queue[front++];
}

// Function to check if the queue is empty
int isEmpty() {
    return front == rear;
}

// BFS function
void BFS(int adj[MAX][MAX], int nodes, int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < nodes; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int nodes = 5;  // Number of nodes
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    }; // Predefined adjacency matrix

    int start = 0; // Starting node
    printf("BFS Traversal: ");
    BFS(adj, nodes, start);

    return 0;
}
