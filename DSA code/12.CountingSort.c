#include <stdio.h>
#define RANGE 255

void countingSort(int arr[], int n) {
    int output[n];
    int count[RANGE + 1] = {0};
    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // Update count array to store cumulative positions
    for (int i = 1; i <= RANGE; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // Copy output array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
