#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;           // Data of the node (queue element)
    struct Node* next;  // Pointer to the next node in the queue
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
// Function to add an element to the queue (enqueue operation)
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode; // Queue is empty
        return;
    }
    q->rear->next = newNode; // Add new node at the end
    q->rear = newNode;       // Update rear pointer
}
// Function to remove an element from the queue (dequeue operation)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next; // Move front pointer to the next node
    if (q->front == NULL) {
        q->rear = NULL; // If the queue becomes empty, update rear as well
    }
    free(temp); // Free the memory of the dequeued node
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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
