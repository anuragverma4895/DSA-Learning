#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;           // Data of the node (queue element)
    struct Node* next;  // Pointer to the next node
};
// Queue structure containing front and rear pointers
struct Queue {
    struct Node* front; // Points to the front element of the queue
    struct Node* rear;  // Points to the rear element of the queue
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}
// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}
// Function to insert an element into the queue (enqueue)
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    // If the queue is empty, both front and rear will point to the new node
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // Make it circular
    } else {
        q->rear->next = newNode;  // Point current rear to the new node
        q->rear = newNode;        // Update rear to the new node
        q->rear->next = q->front; // Make it circular again
    }
}
// Function to delete an element from the queue (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    // If there is only one element in the queue
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;  // Move front to the next node
        q->rear->next = q->front;   // Update rear's next to the new front
    }
    free(temp);  // Free the memory of the dequeued node
    return data;
}
// Function to get the front element without dequeuing it
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}
// Function to display all elements in the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != q->rear) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", q->rear->data);  // Print the last element (rear)
}
int main() {
    struct Queue q;
    initQueue(&q);

    // Enqueue some elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    // Display queue elements
    displayQueue(&q);
    // Dequeue an element
    printf("Dequeued: %d\n", dequeue(&q));
    // Display queue elements after dequeue
    displayQueue(&q);
    // Front element of the queue
    printf("Front element: %d\n", front(&q));
    return 0;
}
