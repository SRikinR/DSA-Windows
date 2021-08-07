#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void transverseLL(struct node *head){
    struct node *ptr=head;
    while (ptr!=head){
        printf("Elements: %d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("Elements: %d\n",ptr->data);
    ptr=ptr->next;
}


struct node *InsertAtStart(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p!=head){
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

    head->data=43;
    head->next=second;

    second->data=454;
    second->next=third;

    third->data=654;
    third->next-fourth;

    fourth->data=83;
    fourth->next=head;

    printf("Circular_LL Before Insertion:\n");
    transverseLL(head);

    printf("Circular_LL After Insertion:\n");   
    head=InsertAtStart(head,90);
    transverseLL(head);

    return 0;
}