#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for Level Order Traversal using a queue
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Queue implemented using an array
    struct Node* queue[100]; // Assuming max 100 nodes
    int front = 0, rear = 0;

    // Enqueue root
    queue[rear++] = root;

    // Process nodes in FIFO order
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        // Enqueue left child if exists
        if (current->left)
            queue[rear++] = current->left;

        // Enqueue right child if exists
        if (current->right)
            queue[rear++] = current->right;
    }
}

int main() {
    // Creating the binary tree using linked list representation
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Perform Level Order Traversal
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
