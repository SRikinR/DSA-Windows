#include<stdio.h>

int linearsearch(int arr[],int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element){
            return i;
        }
        
    }
    return -1;
}

int binarysearch(int arr[],int size,int element){
    int low, mid, high;
    low =0;
    high=size-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    //int arr[]={1,3,5,24,54,2,7};
    int arr[]={1,13,25,224,354,442,557};
    int size= sizeof(arr)/sizeof(int);
    int element = 25;
    int searchindex = binarysearch(arr,size,element);
    printf("Element %d is at the index %d",element,searchindex);
    return 0;
}