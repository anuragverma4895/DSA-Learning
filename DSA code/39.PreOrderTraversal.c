#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
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
// Preorder Traversal Function
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    // Print current node
    printf("%d ", root->data);
    
    // Recur on left subtree
    preorderTraversal(root->left);
    
    // Recur on right subtree
    preorderTraversal(root->right);
}
int main() {
    // Creating the binary tree from the example
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    // Perform Preorder Traversal
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    return 0;
}
