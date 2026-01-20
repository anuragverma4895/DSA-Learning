#include <stdio.h>
#include <stdlib.h>

// Structure for each node in the linked list
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a new node at the end of the list
struct Node* insertNode(struct Node* head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
// Function to display the linked list (sparse matrix)
void displaySparse(struct Node* head) {
    printf("\nRow\tCol\tValue\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}
// Main function
int main() {
    // Example matrix (most of the elements are zero)
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    struct Node* head = NULL;
    // Convert the matrix to linked list representation
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                head = insertNode(head, i, j, matrix[i][j]);
            }
        }
    }
    // Display the sparse matrix
    printf("Sparse Matrix Representation:\n");
    displaySparse(head);
    return 0;
}
