#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// Deque structure with pointers to front and rear
struct Deque {
    struct Node* front;
    struct Node* rear;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
// Function to initialize the deque
void initDeque(struct Deque* deque) {
    deque->front = deque->rear = NULL;
}
// Check if deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}
// Insert at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}
// Insert at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        newNode->prev = deque->rear;
        deque->rear = newNode;
    }
}
// Delete from the front of the deque
int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int data = temp->data;

    if (deque->front == deque->rear) { // Only one element
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}
// Delete from the rear of the deque
int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }
    struct Node* temp = deque->rear;
    int data = temp->data;

    if (deque->front == deque->rear) { // Only one element
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}
// Get the front element of the deque
int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return deque->front->data;
}
// Get the rear element of the deque
int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return deque->rear->data;
}
// Display the elements in the deque
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = deque->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Deque deque;
    initDeque(&deque);
    insertFront(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);
    insertRear(&deque, 30);
    displayDeque(&deque);
    printf("Front element: %d\n", getFront(&deque));
    printf("Rear element: %d\n", getRear(&deque));
    printf("Deleted from front: %d\n", deleteFront(&deque));
    printf("Deleted from rear: %d\n", deleteRear(&deque));
    displayDeque(&deque);
    return 0;
}
