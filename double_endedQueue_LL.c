#include<stdio.h>
#include<stdlib.h>


struct node *f=NULL;
struct node *r=NULL;

struct node
{
    int data;
    struct node *next;
};

int transverse(struct node *ptr){
    while(ptr !=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int enqueue(int value){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue Full\n");
    }
    else{
        n->data=value;
        n->next=NULL;
        if(f == NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue(){
    int value =-1;
    struct node *p=f;
    if(f==NULL){
        printf("Queue Empty\n");
    }
    else{
        f=f->next;
        value=p->data;
        free(p);
    }
    return value;

}

// int DELinRare(){
//     struct node *p=r;
//     struct node *q;
//     int value;
//     if(f==r){
//         printf("Queue is Empty\n");
//     }
//     else{
//         r=p;
//         value=r->data;
//         free(p);
//     }
//     return value;
// }

int ADDinFront(int value){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    struct node *p=f;
    if(n==NULL){
        printf("Queue is full\n");
    }
    else{
        if(f==r){
            f=r=n;
        }
        else{
            n->data=value;
            n->next=p;
            f=n;
        }
    }
}

int main(){
    

    enqueue(23);
    enqueue(24);
    enqueue(25);
    enqueue(26);

    transverse(f);
    printf("Dequeued: %d\n",dequeue());
    printf("Dequeued: %d\n",dequeue());

    transverse(f);
    printf("now: \n");
    ADDdequeue(23);
    ADDdequeue(24);
    transverse(f);

    return 0;
}