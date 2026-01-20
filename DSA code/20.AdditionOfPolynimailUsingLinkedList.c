#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct Node* next;
};
// Function to create a new node with given coefficient and exponent
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a new term at the end of the polynomial linked list
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        if (poly->coeff > 0 && poly != poly) {
            printf(" + ");
        }
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
    }
    printf("\n");
}
// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL; // Resultant polynomial
    struct Node *p1 = poly1, *p2 = poly2;
    // Traverse both polynomials
    while (p1 != NULL && p2 != NULL) {
        // If exponent of p1 > p2, add p1's term to result
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        // If exponent of p1 < p2, add p2's term to result
        else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        // If exponents are equal, add the coefficients and insert into result
        else {
            int coeffSum = p1->coeff + p2->coeff;
            if (coeffSum != 0) { // Only add non-zero terms
                insertTerm(&result, coeffSum, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    // Add remaining terms of poly1
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    // Add remaining terms of poly2
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;
    int n1, n2, coeff, exp;
    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }
    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }
    // Display both polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    // Add the two polynomials
    struct Node* result = addPolynomials(poly1, poly2);
    // Display the result
    printf("\nResult of polynomial addition: ");
    displayPolynomial(result);
    return 0;
}
