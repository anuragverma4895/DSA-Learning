#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;                // Data part of the node
    struct node *prev;      // Pointer to the previous node
    struct node *next;      // Pointer to the next node
};

struct node *head = NULL;  // Head pointer for the list

// Function declarations
void create();
void insert_first();
void insert_last();
void insert_middle();
void delete_first();
void delete_last();
void delete_middle();
void display();
void count();
void search();

int main() {
    int choice;
    do {
        // Menu options for user
        printf("\n------- Circular Doubly Linked List -------\n");
        printf("1. Create\n2. Insert at First\n3. Insert at Last\n4. Insert at Middle\n");
        printf("5. Delete from First\n6. Delete from Last\n7. Delete from Middle\n");
        printf("8. Display\n9. Count\n10. Search\n11. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;           // Create a new list
            case 2: insert_first(); break;     // Insert a node at the beginning
            case 3: insert_last(); break;      // Insert a node at the end
            case 4: insert_middle(); break;    // Insert a node at a specific position
            case 5: delete_first(); break;     // Delete the first node
            case 6: delete_last(); break;      // Delete the last node
            case 7: delete_middle(); break;    // Delete a node from a specific position
            case 8: display(); break;          // Display the list
            case 9: count(); break;            // Count the nodes in the list
            case 10: search(); break;          // Search for a specific value
            case 11: exit(0); break;           // Exit the program
            default: printf("Invalid choice\n");
        }
    } while (choice != 11); // Continue until the user chooses to exit

    return 0;
}

// Function to create the list
void create() {
    int n;
    char ch;
    struct node *new1, *temp;
    printf("Enter the element: ");
    scanf("%d", &n);

    // Create the first node
    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;
    new1->prev = new1;  // Point to itself
    new1->next = new1;  // Point to itself
    head = new1;
    temp = head;

    // Continue adding nodes
    getchar();
    printf("Want to continue (Y/N)? ");
    ch = getchar();
    while (ch == 'Y' || ch == 'y') {
        printf("Enter the next element: ");
        scanf("%d", &n);

        // Create a new node and link it
        new1 = (struct node*) malloc(sizeof(struct node));
        new1->data = n;
        new1->prev = temp;     // Link new node's prev to current last
        new1->next = head;     // Link new node's next to head
        temp->next = new1;     // Link previous last's next to new node
        head->prev = new1;     // Link head's prev to new node
        temp = new1;           // Move temp to new node

        getchar();
        printf("Want to continue (Y/N)? ");
        ch = getchar();
    }
}

// Function to insert a node at the beginning
void insert_first() {
    int n;
    struct node *new1;
    printf("Enter the element to insert at first: ");
    scanf("%d", &n);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;

    if (head == NULL) {
        // If the list is empty
        new1->prev = new1;  // Point to itself
        new1->next = new1;  // Point to itself
        head = new1;
    } else {
        // If the list is not empty
        new1->next = head;          // New node's next points to current head
        new1->prev = head->prev;    // New node's prev points to the last node
        head->prev->next = new1;    // Last node's next points to new node
        head->prev = new1;          // Head's previous pointer points to new node
        head = new1;                // Update head to new node
    }
}

// Function to insert a node at the end
void insert_last() {
    int n;
    struct node *new1;
    printf("Enter the element to insert at last: ");
    scanf("%d", &n);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;

    if (head == NULL) {
        // If the list is empty
        new1->prev = new1;  // Point to itself
        new1->next = new1;  // Point to itself
        head = new1;
    } else {
        // If the list is not empty
        new1->prev = head->prev;   // New node's prev points to the last node
        new1->next = head;         // New node's next points to head
        head->prev->next = new1;   // Last node's next points to new node
        head->prev = new1;         // Head's previous pointer points to new node
    }
}

// Function to insert a node at a specific position
void insert_middle() {
    int n, pos, i = 1;
    struct node *new1, *temp;
    printf("Enter the element to insert: ");
    scanf("%d", &n);
    printf("Enter position: ");
    scanf("%d", &pos);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;

    if (head == NULL) {
        // If the list is empty
        new1->prev = new1;  // Point to itself
        new1->next = new1;  // Point to itself
        head = new1;
    } else {
        temp = head;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;  // Move to the desired position
            i++;
        }
        new1->next = temp->next;      // New node's next points to the current node
        new1->prev = temp;            // New node's prev points to the previous node
        temp->next->prev = new1;      // Current node's next's prev points to new node
        temp->next = new1;            // Previous node's next points to new node
    }
}

// Function to delete the first node
void delete_first() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (head->next == head) {
        // If there's only one node
        head = NULL;
    } else {
        head->prev->next = head->next;  // Last node's next points to second node
        head->next->prev = head->prev;  // Second node's prev points to last node
        head = head->next;               // Update head to second node
    }
    free(temp); // Free the deleted node
}

// Function to delete the last node
void delete_last() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head->prev; // Get the last node
    if (temp == head) {
        // If there's only one node
        head = NULL;
    } else {
        temp->prev->next = head; // Second last node's next points to head
        head->prev = temp->prev;  // Update head's prev to second last node
    }
    free(temp); // Free the deleted node
}

// Function to delete a node from a specific position
void delete_middle() {
    int pos, i = 1;
    struct node *temp;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (i < pos && temp->next != head) {
        temp = temp->next;  // Move to the desired position
        i++;
    }

    if (temp->next == head) {
        printf("Position out of range\n");
        return;
    }

    temp->prev->next = temp->next;  // Link previous node to next node
    temp->next->prev = temp->prev;  // Link next node to previous node

    if (temp == head) {
        head = temp->next; // Update head if deleting the first node
    }

    free(temp); // Free the deleted node
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data); // Print node data
        temp = temp->next;         // Move to the next node
    } while (temp != head);        // Stop when back to head
    printf("\n");
}

// Function to count the nodes in the list
void count() {
    int count = 0;
    struct node *temp = head;

    if (head == NULL) {
        printf("Total nodes: %d\n", count);
        return;
    }

    do {
        count++;                  // Increment count
        temp = temp->next;       // Move to the next node
    } while (temp != head);      // Stop when back to head

    printf("Total nodes: %d\n", count);
}

// Function to search for an element in the list
void search() {
    int s, found = 0;
    struct node *temp = head;
    printf("Enter an element to search: ");
    scanf("%d", &s);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (temp->data == s) {
            found = 1;
            break; // Element found
        }
        temp = temp->next; // Move to the next node
    } while (temp != head);

    if (found) {
        printf("Element %d found in the list.\n", s);
    } else {
        printf("Element %d not found in the list.\n", s);
    }
}
