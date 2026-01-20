#include <stdio.h>

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
    // Degree of the polynomial
    int degree = 3;
    // Array to store the coefficients of the polynomial 4x^3 + 3x^2 + 0x + 2
    int poly[] = {2, 0, 3, 4};
    printf("The polynomial is: ");
    displayPolynomial(poly, degree);
    return 0;
}
