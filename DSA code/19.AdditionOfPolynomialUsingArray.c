#include <stdio.h>

#define MAX_DEGREE 10  // Maximum degree of the polynomial

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int i = 0, j = 0, k = 0;
    // Add terms with matching degrees
    while (i <= degree1 && j <= degree2) {
        if (degree1 - i > degree2 - j) {
            result[k++] = poly1[i++];
        } else if (degree2 - j > degree1 - i) {
            result[k++] = poly2[j++];
        } else {
            result[k++] = poly1[i++] + poly2[j++];
        }
    }
    // If polynomial 1 has remaining terms
    while (i <= degree1) {
        result[k++] = poly1[i++];
    }
    // If polynomial 2 has remaining terms
    while (j <= degree2) {
        result[k++] = poly2[j++];
    }
}
// Function to display the polynomial
void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}
int main() {
    int degree1, degree2;
    // Input for the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    int poly1[degree1 + 1];  // Array to store coefficients of polynomial 1
    printf("Enter the coefficients of the first polynomial (from lowest to highest degree):\n");
    for (int i = 0; i <= degree1; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    // Display the first polynomial
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, degree1);
    // Input for the second polynomial
    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    int poly2[degree2 + 1];  // Array to store coefficients of polynomial 2
    printf("Enter the coefficients of the second polynomial (from lowest to highest degree):\n");
    for (int i = 0; i <= degree2; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    // Display the second polynomial
    printf("\nSecond Polynomial: ");
    displayPolynomial(poly2, degree2);
    // Array to store the result of the addition
    int result[MAX_DEGREE + 1] = {0};
    // Add the polynomials
    addPolynomials(poly1, poly2, result, degree1, degree2);
    // Display the result
    printf("\nResult of polynomial addition: ");
    displayPolynomial(result, degree1 > degree2 ? degree1 : degree2);
    return 0;
}
