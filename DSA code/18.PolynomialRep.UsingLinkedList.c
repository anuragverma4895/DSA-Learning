#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int coeff;       // Coefficient of the term
    int exp;         // Exponent of the term
    struct Node* next; // Pointer to the next node
};
// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a term into the polynomial
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
// Main function
int main() {
    struct Node* poly = NULL;
    // Example: 4x^3 + 3x^2 + 2
    insertTerm(&poly, 4, 3);
    insertTerm(&poly, 3, 2);
    insertTerm(&poly, 2, 0);
    // Display the polynomial
    printf("The polynomial is: ");
    displayPolynomial(poly);
    return 0;
}
