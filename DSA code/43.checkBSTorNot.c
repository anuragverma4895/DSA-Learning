#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if the tree is a BST using inorder traversal
bool isBST(struct Node* node, int* prev) {
    if (node == NULL) {
        return true;
    }

    // Check the left subtree
    if (!isBST(node->left, prev)) {
        return false;
    }

    // Check if the current node's value is greater than the previous value
    if (node->data <= *prev) {
        return false;
    }

    // Update the previous value
    *prev = node->data;

    // Check the right subtree
    return isBST(node->right, prev);
}

// Wrapper function to call the isBST function with initial parameters
bool isBSTWrapper(struct Node* root) {
    int prev = INT_MIN;  // Initialize previous value to minimum integer value
    return isBST(root, &prev);
}

// Driver code to test the function
int main() {
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    if (isBSTWrapper(root)) {
        printf("The tree is a Binary Search Tree.\n");
    } else {
        printf("The tree is not a Binary Search Tree.\n");
    }

    return 0;
}
