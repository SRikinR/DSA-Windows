#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

void transverse_list(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Elements: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * InsertAtBeginning(struct Node *head){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=1;
    ptr->next=head;
    return ptr;
}

struct Node * InsertAtIndex(struct Node *head, int index){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=2015;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node * InsertAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}

struct Node * InsertAfterNode(struct Node *high,struct Node * preNode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=preNode->next;
    preNode->next=ptr;

    return high;
}


int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second =(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    printf("Elements:\n");
    head=InsertAfterNode(head,third,278);
    transverse_list(head);
    

    return 0;
}