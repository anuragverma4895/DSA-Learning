#include<stdio.h>

int search(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

void main(){
    int size,element;
    printf("enter the size of the array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element for search : ");
    scanf("%d",&element);
    int searchindex = search(arr,size,element);
    printf("the element %d is found at index %d ", element,searchindex);
}