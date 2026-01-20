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

// Function to find the minimum node in a subtree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Node %d not found in BST.\n", key);
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get inorder successor
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

    printf("BST before deletion (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    // Deleting nodes
    root = deleteNode(root, 30);
    printf("BST after deleting 30 (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("BST after deleting 50 (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 100); // Trying to delete a non-existing node
    printf("BST after trying to delete 100 (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
