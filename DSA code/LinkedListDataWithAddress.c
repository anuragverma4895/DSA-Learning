#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create(int value){
    struct node *new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
    struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void traverse(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d --> %d\n",temp->data,temp);
        temp=temp->next;
    }
}

int main(){
    int n,value;
    printf("enter the size of element for insert :");
    scanf("%d",&n);
    printf("enter the value :");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        create(value);
    }
    traverse();
    return 0;
}