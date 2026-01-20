#include <stdio.h>

// Recursive function for binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        // Base case: key found
        if (arr[mid] == key)
            return mid;
        // Search in the left half
        if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);
        // Search in the right half
        return binarySearch(arr, mid + 1, high, key);
    }
    // Element not found
    return -1;
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, size - 1, key);
    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);
    return 0;
}
