#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int enqueue(struct queue *q, int value){
    if(isfull(q)){
        printf("Queue full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=value;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue Empty.\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    // struct queue *q;
    struct queue q;
    // q->size=100;
    // q->f = -1;
    // q->r = -1;
    // q->arr=(int *)malloc(q->size * sizeof(int));
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size * sizeof(int));
    printf("queue created\n");

    // isEmpty(&q);
    enqueue(&q,23);
    enqueue(&q,32);
    enqueue(&q,3);
    printf("Dequeuing element: %d\n",dequeue(&q));
    printf("Dequeuing element: %d\n",dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is Empty: %d\n",isEmpty(&q));
    }
    if (isfull(&q)){
        printf("Queue is Full: %d\n",isfull(&q));
    }

    return 0;
}