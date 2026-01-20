#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the array

// Global array to store binary tree elements
int tree[MAX_SIZE];
// Function to initialize the array
void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;  // Using -1 to indicate empty positions
    }
}
// Function to insert a node at a given index
void insertNode(int value, int index) {
    if (index >= MAX_SIZE) {
        printf("Index out of bounds. Cannot insert.\n");
        return;
    }
    if (tree[index] != -1) {
        printf("Position already occupied. Cannot insert.\n");
        return;
    }
    tree[index] = value;
}
// In-order traversal (Recursive)
void inorderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return;
    }
    inorderTraversal(2 * index + 1);  // Left child
    printf("%d ", tree[index]);       // Root
    inorderTraversal(2 * index + 2);  // Right child
}
// Function to display the tree as an array
void displayTreeArray() {
    printf("Binary Tree as Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}
int main() {
    initializeTree();

    // Inserting nodes into the binary tree
    insertNode(10, 0);  // Root
    insertNode(20, 1);  // Left child of root
    insertNode(30, 2);  // Right child of root
    insertNode(40, 3);  // Left child of node at index 1
    insertNode(50, 4);  // Right child of node at index 1
    insertNode(60, 5);  // Left child of node at index 2
    insertNode(70, 6);  // Right child of node at index 2

    printf("Inorder Traversal: ");
    inorderTraversal(0);
    printf("\n");
    displayTreeArray();
    return 0;
}
