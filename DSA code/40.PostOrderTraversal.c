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

// Recursive Postorder Traversal Function
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    postorderTraversal(root->left);

    // Traverse the right subtree
    postorderTraversal(root->right);

    // Print the current node data
    printf("%d ", root->data);
}

int main() {
    // Creating the binary tree using linked list representation
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Perform Postorder Traversal
    printf("Postorder Traversal: ");
    postorderTraversal(root);

    return 0;
}
