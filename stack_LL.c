#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void transverse(struct node *ptr){
    while (ptr!=NULL)
    {                   
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isempty(struct node *ptr){
    if (ptr == NULL){
        return 1;
    }
    return 0;
}

int isfull(struct node *ptr){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    return 1;
    else
    return 0;
}

struct node * push(struct node *ptr,int value){
        if(isfull(ptr)){
            printf("Stack Overflow\n");
        }
        else{
        struct node *n=(struct node*)malloc(sizeof(struct node));
        n->data=value;
        n->next=ptr;
        ptr=n;
        return ptr;
        }
}

struct node *pop(struct node *ptr){
    if(isempty(ptr)){
        printf("Stack Underflow.\n");
    }
    else{
        struct node *n=ptr;
        int w= ptr->data;
        struct node *m=ptr->next;
        ptr=m;
        //int x= n->data;
        free(n);
        printf("Element popped %d\n",w);
        return ptr;
    }

}

int stackTop(struct node *ptr){
    return ptr->data;
}

int stackBottom(struct node *ptr){
    
}

int peek(struct node *ptr,int pos){
    struct node *p=ptr;
    //struct node *q=p->next;
    for(int i=1; (i<= pos && p!=NULL);i++){
      //  q=q->next;
        p=p->next;
    }
    if(p!=NULL){
        printf("PEEK VALUE IS: %d",p->data);
        return p->data;
    }
    return -1;
}

int main(){
    struct node * top=NULL;
    top= push(top,56);
    top=push(top,65);
    top=push(top,23);
    top=push(top,28);
    top=push(top,31);
    top=push(top,68);
    top=push(top,898);
    top=push(top,282);

    printf("List After Push operation:\n");
    transverse(top);
    printf("\n");
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    printf("\nList After POP operation:\n");
    transverse(top);
    printf("\n");
    int ST=stackTop(top);
    printf("Top Elements is: %d\n", ST);
    peek(top,2);
    
    return 0;
}