#include<stdio.h>
int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
            printf("%d is found at %d index",element,mid);
            return 0;
        }
        else if(arr[mid]<=element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    printf("element not found");
    return 0;
}
int main(){
    int size,element;
    printf("enter the size of an array: ");
    scanf("%d",&size);
    int arr[size];
    printf("elements of array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element for search: ");
    scanf("%d",&element);
    binarySearch(arr,size,element);
    return 0;
}
