
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 10
int stack[MAXSIZE], top=-1;

void push();
void pop();
void display();

void main(){
    int choice;
    do{
        printf("--------------- stack --------------");
        printf("\n1. push\n2. pop\n3. display\n4. exit\n");
        printf("-------------------------------------\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            default: printf("invalid choice\n");
        }
        
     }while(choice!=4);
}

void push(){
    int n;
    if(top == MAXSIZE-1)
    printf("\n stack is overflow\n");
    else{
        printf("enter an element ");
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
}

void pop(){
   int n;
   if(top==-1)
   printf("stack is empty\n");
   else{
       n=stack[top];
       top--;
       printf("poped element %d\n",n);
   }
}

void display(){
    int i;
    if(top==-1)
    printf("stack is empty\n");
    else{
        printf("elements of stacks are\n");
        for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);    
        
    }
}