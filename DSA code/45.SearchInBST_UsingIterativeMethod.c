#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

// Function to create a new node
struct treeNode* createNode(int val) {
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative function to search for a key in BST
struct treeNode* searchIterative(struct treeNode* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;  // Found the key
        else if (key < root->data)
            root = root->left;  // Move left
        else
            root = root->right;  // Move right
    }
    return NULL;  // Key not found
}

int main() {
    // Manually creating a sample BST
    struct treeNode* root = createNode(50);
    root->left = createNode(25);
    root->right = createNode(75);
    root->left->left = createNode(10);
    root->left->right = createNode(40);
    root->right->left = createNode(70);
    root->right->right = createNode(80);

    // Searching for a value iteratively
    int key = 40;
    struct treeNode* result = searchIterative(root, key);

    if (result != NULL)
        printf("Found: %d\n", result->data);
    else
        printf("Not Found\n");

    return 0;
}
