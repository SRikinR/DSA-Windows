#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void transverseLL(struct node *head){
    struct node *ptr=head;
    do{
        printf("Elements: %d\n",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
}


struct node *InsertAtStart(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));

    head->data=111;
    head->next=second;  

    second->data=222;
    second->next=third;

    third->data=333;
    third->next=fourth;

    fourth->data=444;
    fourth->next=head;

    transverseLL(head);
    printf("After\n");
    head=InsertAtStart(head,6161);
    transverseLL(head);

    return 0;
}