#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;    
};

void transverse(struct node *ptr){
    printf("Elements are:\n");
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

void reverse(struct node *ptr){
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }while(ptr->prev!=NULL);
}

void transverseResevse(struct node *ptr){
    printf("Transverse Elements are:\n");
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    printf("Reserse Tranverse Elements are:\n");
    while(ptr->prev!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d\n",ptr->data);

}


int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));

    head->prev=NULL;
    head->data=1;
    head->next=second;

    second->prev=head;
    second->data=2;
    second->next=third;

    third->prev=second;
    third->data=3;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=4;
    fourth->next=NULL;

    printf("Transverse:");
    transverse(head);

    printf("Reverse Tranverse:\n");
    reverse(fourth);

    printf("Two in One\n");    
    transverseResevse(head);

    return 0;
}