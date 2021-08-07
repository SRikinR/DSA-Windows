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

int isempty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int enqueue(struct queue *q, int value){
    if(isfull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=value;
    }
}

int AddAtFront(struct queue *q, int value){
    if(isfull(q)){
        printf("Queue is Full");
    }
    else{
        q->arr[q->f]=value;
        q->f--;
    }
}

int DelAtRare(struct queue *q){
    int b=-1;
    if(isempty(q)){
        printf("Queue is Empty\n");
    }
    else{
        b=q->arr[q->r];
        q->r--;
    }
    return b;
}

int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("Queue is Empty\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size=6;
    q.f =q.r = -1;
    q.arr=(int *)malloc(q.size * sizeof(int));

    enqueue(&q,23);
    enqueue(&q,24);
    //enqueue(&q,25);
    AddAtFront(&q,22);
    printf("Dequeued Element: %d\n",dequeue(&q));
    //printf("Dequeued Element: %d\n",dequeue(&q));
    //printf("Dequeued Element: %d\n",dequeue(&q));
    enqueue(&q,26);
    enqueue(&q,27);
    enqueue(&q,28);
    enqueue(&q,29 );
    printf("Dequeued Element: %d\n",dequeue(&q));
    printf("Dequeued Element: %d\n",DelAtRare(&q));
    printf("Dequeued Element: %d\n",DelAtRare(&q));
    AddAtFront(&q,21);
    AddAtFront(&q,20);
    enqueue(&q,30);
    enqueue(&q,31);
    enqueue(&q,32);

    if(isfull){
        printf("Queue Full: %d\n",isfull(&q));
    }
    if(isempty){
        printf("Queue Empty: %d\n",isempty(&q));
    }


    return 0;
}