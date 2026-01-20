#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *add;
};
struct node *start=NULL,*temp,*new1,*prev,*next;

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

void main()
{
    int choice;
    do
    {
        printf("\n---------- Linked List ------------\n");
        printf("\n1. create\n2. insert on first\n3. insert on last\n4. \
insert on middle\n5. delete from first\n6. delete from last\n7. \
delete from middle\n8. display\n9. count\n10. search\n11. exit\n");
        printf("------------------------------------\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
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
            default : printf("invalid choice\n");
        }
    } while(choice!=11);
}


void create()
{
    char ch;
    int n;
    printf("enter the element ");
    scanf("%d",&n);
    start=(struct node*) malloc(sizeof(struct node));
    start->data=n;
    start->add=NULL;
    temp=start;
    getchar();
    printf("want to continue (Y/N) : ");
    ch=getchar();
    while(ch == 'Y' || ch=='y')
    {
        printf("enter the next elements ");
        scanf("%d",&n);
        new1=(struct node*) malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        temp->add=new1;
        temp=temp->add;
        getchar();
        printf("want to continue (Y/N) : ");
        ch=getchar();
    }
}

void insert_first()
{
    int n;
    if(start==NULL)
    printf("list not found\n");
    else
    {
        printf("enter the new element for insert ");
        scanf("%d",&n);
        new1=(struct node*) malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        new1->add=start;
        start=new1;
    }
}

void insert_last()
{
    int n;
    if(start==NULL)
    printf("list not found\n");
    else
    {
        printf("enter new element for insert ");
        scanf("%d",&n);
        new1=(struct node*) malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        temp=start;
        while(temp->add!=NULL)
        {
            temp=temp->add;
        }
        temp->add=new1;
    }
}

void insert_middle()
{
    int n, pos, i=1;
    if(start==NULL)
    printf("list not empty\n");
    else
    {
        printf("enter the new element for insert ");
        scanf("%d",&n);
        new1=(struct node*) malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        printf("enter position ");
        scanf("%d",&pos);
        next=start;
        while(i<pos)
        {
            prev=next;
            next=next->add;
            i++;
            
        }
        prev->add=new1;
        new1->add=next;
    }
}

void delete_first()
{
    if(start==NULL)
    printf("list not found\n");
    else
    {
        temp=start;
        start=start->add;
        printf("deleted node is %d\n",temp->data);
        free(temp);
    }
}

void delete_last()
{
    if(start==NULL)
    printf("list not found\n");
    else
    {
        temp=start;
        while(temp->add!=NULL)
        {
           prev=temp;
           temp=temp->add; 
        }
        prev->add=NULL;
        printf("deleted node %d\n",temp->data);
        free(temp);
    }
}
void delete_middle()
{
    int pos, i=1;
    if(start==NULL)
    printf("list not found\n");
    else
    {
        printf("enter the position ");
        scanf("%d",&pos);
        temp=start;
        while(i<pos)
        {
            prev=temp;
            temp=temp->add;
            i++;
        }
        next=temp->add;
        prev->add=next;
        printf("deleted element is %d\n",temp->data);
        free(temp);
    }
}

void display()
{
    if(start==NULL)
    printf("list not found\n");
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->add;
        }
        printf("\n");
    }
}

void count()
{
    int count=0;
    temp=start;
    while(temp!=NULL)
    {
        count++;
        temp=temp->add;
    }
    printf("total node is %d\n",count);
}

void search()
{
    int s,f=0;
    if(start==NULL)
    printf("list not found\n");
    else
    {
        printf("enter an element for search ");
        scanf("%d",&s);
        temp=start;
        while(temp!=NULL)
        {
            if(temp->data==s)
            
            {
                f=1;
                break;
            }
            temp=temp->add;
        }
        if(f==1)
        printf("searching sucess ");
        else
        printf("seareching not found");
    }
}
