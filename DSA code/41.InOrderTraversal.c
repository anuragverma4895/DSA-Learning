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

// Recursive Inorder Traversal Function
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    inorderTraversal(root->left);

    // Print the current node data
    printf("%d ", root->data);

    // Traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    // Creating the binary tree using linked list representation
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Perform Inorder Traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}
