#include<stdio.h>
void display(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void deletion(int arr[],int size, int index){
    for(int i=0;i<size ;i++){
        if(i>=index){
            arr[i]=arr[i+1];
        }
    }
}

void main(){
    int size,index;
    printf("enter the size of the array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the index number : ");
    scanf("%d",&index);
    display(arr,size);
    deletion(arr,size,index);
    size--;
    display(arr,size);
}