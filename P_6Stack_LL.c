#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void transverse(struct node *ptr){
    printf("List of Element:\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node *push(struct node *ptr, int value ){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=value;
    p->next=ptr;
    ptr=p;
    return ptr;
}

struct node *pop(struct node *top){
    struct node *p=top;
    struct node *q=p->next;
    top=q;
    printf("Popped %d\n",p->data);
    free(p);
    return top;
}

struct node *stacktop(struct node *ptr){
    printf("Top Element in the Stack is: %d\n",ptr->data);
}

// struct node *stackbottom(struct node *ptr){
    
//     printf("%d\n",ptr->data);
//     return ptr;
// }

struct node *peek(struct node *ptr, int pos){
    struct node *p=ptr;
    for(int i=1; (i<=pos && p!=NULL); i++){
        p=p->next;
    }
    if(p!=NULL){
        printf("PEEK: value at position %d is: %d\n",pos,p->data);
    }
}

int main(){
    struct node *top=NULL;
    top = push(top,56);
    top = push(top,66);
    top = push(top,76);
    top = push(top,86);
    top = push(top,96);
    transverse(top);

    top =pop(top);

    transverse(top);
    stacktop(top);
    //printf("Stack Bottom %d\n",stackbottom(top));
    peek(top,2);


    return 0;
}