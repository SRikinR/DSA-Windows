#include<stdio.h>
#include<stdlib.h>

int printarray(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n){
    // int isSorted=0;
    int temp;
    for(int i=0; i<n; i++){          //for number of passes
        printf("Working on Pass: %d\n",i);
        for(int j=0; j<n-1-i; j++){     //for comparision in each pass
        if(A[j]>A[j+1]){
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
        }
        }
    }
}

void adaptiveBubbleSort(int *A, int n){
    int isSorted=0;
    int temp;
    for(int i=0; i<n; i++){          //for number of passes
        printf("Working on Pass: %d\n",i);
        isSorted=1;
        for(int j=0; j<n-1-i; j++){     //for comparision in each pass
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted){
            return;
        }
    }
}


int main(){
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n=11;
    printarray(A,n);
    //bubbleSort(A,n);
    adaptiveBubbleSort(A,n);
    printarray(A,n);
    
    return 0;
}