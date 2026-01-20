#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in an existing BST
void insert(struct Node* root, int value) {
    struct Node* parent = NULL;
    struct Node* current = root;

    // Traverse the tree to find the correct position
    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else
            return; // Duplicates not allowed in BST
    }

    // Create new node
    struct Node* newNode = createNode(value);

    // Attach new node to the parent
    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Function to do inorder traversal (prints BST in sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Driver Code
int main() {
    // Manually creating a BST
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("BST before insertion (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    // Insert new nodes
    insert(root, 25);
    insert(root, 65);

    printf("BST after insertion (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
