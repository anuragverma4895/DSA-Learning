#include <stdio.h>

#define MAX 100  // Maximum number of non-zero elements
#define ROWS 4   // Number of rows in the matrix
#define COLS 5   // Number of columns in the matrix

// Structure to store non-zero elements
struct Sparse {
    int row;
    int col;
    int value;
};
// Function to convert a normal matrix to sparse matrix representation
int convertToSparse(int matrix[ROWS][COLS], struct Sparse sparse[]) {
    int count = 0;  //To count non-zero elements
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                sparse[count].row = i;
                sparse[count].col = j;
                sparse[count].value = matrix[i][j];
                count++;
            }
        }
    }
    return count;  // Return the number of non-zero elements
}
// Function to display a sparse matrix in tuple form
void displaySparse(struct Sparse sparse[], int count) {
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}
int main() {
    // Example matrix (most of the elements are zero)
    int matrix[ROWS][COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    // Array of structures to store the sparse matrix
    struct Sparse sparse[MAX];
    // Convert the normal matrix to sparse matrix
    int nonZeroCount = convertToSparse(matrix, sparse);
    // Display the sparse matrix
    printf("Sparse Matrix Representation:\n");
    displaySparse(sparse, nonZeroCount);
    return 0;
}
