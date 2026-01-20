#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

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
        printf("\n------- Doubly Linked List -------\n");
        printf("1. Create\n2. Insert at First\n3. Insert at Last\n4. Insert at Middle\n");
        printf("5. Delete from First\n6. Delete from Last\n7. Delete from Middle\n");
        printf("8. Display\n9. Count\n10. Search\n11. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_first(); break;
            case 3: insert_last(); break;
            case 4: insert_middle(); break;
            case 5: delete_first(); break;
            case 6: delete_last(); break;
            case 7: delete_middle(); break;
            case 8: display(); break;
            case 9: count(); break;
            case 10: search(); break;
            case 11: exit(0); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 11);

    return 0;
}

void create() {
    int n;
    char ch;
    struct node *new1, *temp;
    printf("Enter the element: ");
    scanf("%d", &n);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;
    new1->prev = NULL;
    new1->next = NULL;
    head = new1;
    temp = head;

    getchar();
    printf("Want to continue (Y/N)? ");
    ch = getchar();
    while (ch == 'Y' || ch == 'y') {
        printf("Enter the next element: ");
        scanf("%d", &n);

        new1 = (struct node*) malloc(sizeof(struct node));
        new1->data = n;
        new1->prev = temp;
        new1->next = NULL;
        temp->next = new1;
        temp = temp->next;

        getchar();
        printf("Want to continue (Y/N)? ");
        ch = getchar();
    }
}

void insert_first() {
    int n;
    struct node *new1;
    printf("Enter the element to insert at first: ");
    scanf("%d", &n);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;
    new1->prev = NULL;
    new1->next = head;

    if (head != NULL) {
        head->prev = new1;
    }
    head = new1;
}

void insert_last() {
    int n;
    struct node *new1, *temp;
    printf("Enter the element to insert at last: ");
    scanf("%d", &n);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;
    new1->next = NULL;

    if (head == NULL) {
        new1->prev = NULL;
        head = new1;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new1;
        new1->prev = temp;
    }
}

void insert_middle() {
    int n, pos, i = 1;
    struct node *new1, *temp;
    printf("Enter the element to insert: ");
    scanf("%d", &n);
    printf("Enter position: ");
    scanf("%d", &pos);

    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
    } else {
        new1->next = temp->next;
        new1->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = new1;
        }
        temp->next = new1;
    }
}

void delete_first() {
    struct node *temp;
    if (head == NULL) {
        printf("List not found\n");
    } else {
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

void delete_last() {
    struct node *temp;
    if (head == NULL) {
        printf("List not found\n");
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

void delete_middle() {
    int pos, i = 1;
    struct node *temp;
    if (head == NULL) {
        printf("List not found\n");
    } else {
        printf("Enter the position: ");
        scanf("%d", &pos);

        temp = head;
        while (i < pos && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            printf("Deleted node is %d\n", temp->data);
            free(temp);
        }
    }
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List not found\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void count() {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", count);
}

void search() {
    int s, f = 0;
    struct node *temp;
    if (head == NULL) {
        printf("List not found\n");
    } else {
        printf("Enter the element to search: ");
        scanf("%d", &s);

        temp = head;
        while (temp != NULL) {
            if (temp->data == s) {
                f = 1;
                break;
            }
            temp = temp->next;
        }

        if (f == 1) {
            printf("Element found\n");
        } else {
            printf("Element not found\n");
        }
    }
}


