#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int rear=-1, front=0;

void insert();
void delete();
void display();

void main(){
    int choice;
    do{
        printf("\n------------ QUEUE -----------\n");
        printf("1. insert\n2. delete\n3. display\n4. exit\n");
        printf("-------------------------------\n");
        printf("enter your choice ");
        scanf("%d",&choice) ;
        switch(choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            default : printf("invalid choice\n");
        }
    } while(choice != 4);
}

void insert()
{
    int n;
    if(rear==MAXSIZE-1)
    printf("Queue is overflow\n");
    else
    {
        printf("enter an element ");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}
void delete()
{
    if(front>rear)
    printf("Queue is empty\n");
    else
    {
        int n=queue[front];
        printf("deleted element %d\n", n);
        front++;
    }
}
void display()
{
    if(front>rear)
    printf("Queue is empty\n");
    else
    {
        printf("Queue elements are\n");
        for(int i=rear; i>front-1; i--)
        {
            printf("%d ",queue[i]);
        }
    }
}