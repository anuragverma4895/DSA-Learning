//  code the operations mentioned max(), min(), search(num), insert(i,num), Append() 
//  in the c language by creating array ADT using structure.

#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// Structure for Array ADT
struct Array {
    int arr[MAX_SIZE];
    int size;
};

// Function to find the maximum element
int max(struct Array *array) {
    int maxVal = INT_MIN;
    for (int i = 0; i < array->size; i++) {
        if (array->arr[i] > maxVal) {
            maxVal = array->arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum element
int min(struct Array *array) {
    int minVal = INT_MAX;
    for (int i = 0; i < array->size; i++) {
        if (array->arr[i] < minVal) {
            minVal = array->arr[i];
        }
    }
    return minVal;
}

// Function to search for an element
int search(struct Array *array, int num) {
    for (int i = 0; i < array->size; i++) {
        if (array->arr[i] == num) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to insert an element at a given index
void insert(struct Array *array, int index, int num) {
    if (index >= 0 && index <= array->size && array->size < MAX_SIZE) {
        for (int i = array->size; i > index; i--) {
            array->arr[i] = array->arr[i - 1];
        }
        array->arr[index] = num;
        array->size++;
    } else {
        printf("Invalid index or array full.\n");
    }
}

// Function to append an element to the array
void append(struct Array *array, int num) {
    if (array->size < MAX_SIZE) {
        array->arr[array->size] = num;
        array->size++;
    } else {
        printf("Array is full.\n");
    }
}

// Function to display the array
void display(struct Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Array array = {{10, 20, 30, 40, 50}, 5}; // Initialize the array with 5 elements

    // Display the initial array
    printf("Array: ");
    display(&array);

    // Max element
    printf("Max element: %d\n", max(&array));

    // Min element
    printf("Min element: %d\n", min(&array));

    // Search for an element
    int num = 30;
    int index = search(&array, num);
    if (index != -1) {
        printf("%d found at index %d\n", num, index);
    } else {
        printf("%d not found in array\n", num);
    }

    // Insert element at index 2
    insert(&array, 2, 25);
    printf("Array after inserting 25 at index 2: ");
    display(&array);

    // Append an element
    append(&array, 60);
    printf("Array after appending 60: ");
    display(&array);

    return 0;
}