
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *last = NULL;


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
        printf("\n---------- Circular Linked List ------------\n");
        printf("\n1. create\n2. insert on first\n3. insert on last\n\
4. insert on middle\n5. delete from first\n6. delete from last\n\
7. delete from middle\n8. display\n9. count\n10. search\n11. exit\n");
        printf("---------------------------------------------\n");
        printf("enter your choice: ");
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
            default: printf("invalid choice\n");
        }
    } while (choice != 11);
    return 0;
}

void create() {
    int n;
    char ch;
    struct node *new1;
    printf("enter the element: ");
    scanf("%d", &n);
    new1 = (struct node*) malloc(sizeof(struct node));
    new1->data = n;
    if (last == NULL) {
        last = new1;
        last->next = last;
    } else {
        new1->next = last->next;
        last->next = new1;
        last = new1;
    }
    getchar();
    printf("want to continue (Y/N): ");
    ch = getchar();
    while (ch == 'Y' || ch == 'y') {
        printf("enter the next element: ");
        scanf("%d", &n);
        new1 = (struct node*) malloc(sizeof(struct node));
        new1->data = n;
        new1->next = last->next;
        last->next = new1;
        last = new1;
        getchar();
        printf("want to continue (Y/N): ");
        ch = getchar();
    }
}

void insert_first() {
    int n;
    struct node *new1;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        printf("enter the new element to insert: ");
        scanf("%d", &n);
        new1 = (struct node*) malloc(sizeof(struct node));
        new1->data = n;
        new1->next = last->next;
        last->next = new1;
    }
}

void insert_last() {
    int n;
    struct node *new1;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        printf("enter the new element to insert: ");
        scanf("%d", &n);
        new1 = (struct node*) malloc(sizeof(struct node));
        new1->data = n;
        new1->next = last->next;
        last->next = new1;
        last = new1;
    }
}

void insert_middle() {
    int n, pos, i = 1;
    struct node *new1, *temp;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        printf("enter the new element to insert: ");
        scanf("%d", &n);
        new1 = (struct node*) malloc(sizeof(struct node));
        new1->data = n;
        printf("enter position: ");
        scanf("%d", &pos);
        temp = last->next;
        while (i < pos-1) {
            temp = temp->next;
            i++;
        }
        new1->next = temp->next;
        temp->next = new1;
    }
}

void delete_first() {
    struct node *temp;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        temp = last->next;
        if (last->next == last) {
            last = NULL;
        } else {
            last->next = temp->next;
        }
        printf("deleted node is %d\n", temp->data);
        free(temp);
    }
}

void delete_last() {
    struct node *temp, *prev;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        temp = last->next;
        if (last->next == last) {
            printf("deleted node is %d\n", last->data);
            free(last);
            last = NULL;
        } else {
            while (temp->next != last->next) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = last->next;
            printf("deleted node is %d\n", last->data);
            free(last);
            last = prev;
        }
    }
}

void delete_middle() {
    int pos, i = 1;
    struct node *temp, *prev;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        printf("enter the position: ");
        scanf("%d", &pos);
        temp = last->next;
        while (i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        printf("deleted node is %d\n", temp->data);
        free(temp);
    }
}

void display() {
    struct node *temp;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        temp = last->next;
        do {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != last->next);
        printf("\n");
    }
}

void count() {
    int count = 0;
    struct node *temp;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        printf("total nodes are %d\n", count);
    }
}

void search() {
    int s, f = 0;
    struct node *temp;
    if (last == NULL) {
        printf("list not found\n");
    } else {
        printf("enter the element to search: ");
        scanf("%d", &s);
        temp = last->next;
        do {
            if (temp->data == s) {
                f = 1;
                break;
            }
            temp = temp->next;
        } while (temp != last->next);
        if (f == 1)
            printf("element found\n");
        else
            printf("element not found\n");
    }
}
