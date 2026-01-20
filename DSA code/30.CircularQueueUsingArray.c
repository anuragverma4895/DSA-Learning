#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int cq[MAXSIZE], rear=-1, front=-1;

void insert();
void delete1();
void display();

void main()
{
    int choice;
    do
    {
        printf("--------------- Circular Queue --------------\n");
        printf("1. insert\n2. delete\n3. display\n4. exit\n");
        printf("---------------------------------------------\n");
        printf("enter you choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(); break;
            case 2: delete1(); break;
            case 3: display(); break;
            default:printf("invalid choice\n");
        }
    }while(choice!=4);
}

void insert()
{
    int n;
    if((rear+1)%MAXSIZE == front)
    printf("Queue is overflow\n");
    else
    {
        printf("enter an element ");
        scanf("%d",&n);
        if(rear==-1 && front==-1)
        {
            rear=0;
            front=0;
        }
        else{
            rear=(rear+1)%MAXSIZE;
        }
        cq[rear]=n;
    }
}

void delete1()
{
    int n;
    if(rear==-1 && front==-1)
    printf("Queue is empty\n");
    else
    {
        n=cq[front];
        printf("deleted element %d\n",n);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAXSIZE;
        }
    }
}

void display()
{
    int i;
    if(rear==-1 && front==-1)
    printf("QUEUE is empty\n");
    else
    {
        printf("elements of queue are ");
        for(i=front;i!=rear; (i=(i+1)%MAXSIZE))
        {
            printf("%d  ",cq[i]);
        }
        printf("%d\n",cq[i]);
    }
}