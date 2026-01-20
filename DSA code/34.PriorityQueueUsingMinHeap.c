#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the tree (for Min-Heap)
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest); // Recursively heapify the affected subtree
    }
}

// Function to insert a new element into the heap (priority queue)
void insert(int arr[], int* n, int key) {
    // First insert the new element at the end of the array
    (*n)++;
    arr[*n - 1] = key;
    
    // Fix the min heap property by comparing with the parent
    int i = *n - 1;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove the element with the lowest priority (i.e., root of the heap)
int extractMin(int arr[], int* n) {
    if (*n <= 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    // Store the root element and remove it
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;

    // Call heapify on the root to maintain the heap property
    heapify(arr, *n, 0);

    return root;
}

// Function to get the element with the lowest priority without removing it
int peekMin(int arr[]) {
    return arr[0];
}

// Function to display the elements of the priority queue (heap)
void display(int arr[], int n) {
    printf("Priority Queue (Min-Heap): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n = 0;  // Initially, the heap is empty

    insert(arr, &n, 10);
    insert(arr, &n, 20);
    insert(arr, &n, 15);
    insert(arr, &n, 5);
    insert(arr, &n, 30);

    display(arr, n);  // Display the heap after insertions

    printf("Min element (priority): %d\n", peekMin(arr));

    printf("Extracted min: %d\n", extractMin(arr, &n));
    display(arr, n);  // Display the heap after extracting min

    printf("Extracted min: %d\n", extractMin(arr, &n));
    display(arr, n);  // Display the heap after extracting min

    return 0;
}
