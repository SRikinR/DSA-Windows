#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue Full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        q->f=(q->f+1)%(q->size);
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size=5;
    q.f = -1;
    q.r =-1;
    q.arr=(int *)malloc(q.size * sizeof(int));

    enqueue(&q,23);
    enqueue(&q,23);
    enqueue(&q,23);
    enqueue(&q,23);
    enqueue(&q,23);
    printf("Dequeued Element is: %d\n",dequeue(&q));
    printf("Dequeued Element is: %d\n",dequeue(&q));
    enqueue(&q,43);
    enqueue(&q,43);
    

    if(isEmpty(&q)){
        printf("Queue is Empty: %d",isEmpty(&q));
    }
    if(isFull(&q)){
        printf("Queue is Full: %d",isFull(&q));  
    }
    return 0;
}