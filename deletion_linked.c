#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void transver_list(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr=ptr->next;
    }
}

struct Node * DeleteAtStart(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node *DeleteAtMid(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=p->next;
    for (int i = 0; i <index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    
    return head;
}

struct Node *DeleteAtEnd(struct Node *head){
    struct Node *p=head;
    struct Node *q=p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
        p->next=NULL;
        free(q);
    
    return head;
}

// struct Node *DeleteAfterNode(struct Node *head,struct Node *Node){
//     struct Node *p=head;
//     struct Node *q=Node;
    
//     p->next=q->next;
//     free(q);
//     return head;
// }

struct Node *DeleteAfterNode(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
         p = p->next;
         q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=45;
    head->next=second;

    second->data=23;
    second->next=third;

    third->data=32;
    third->next=fourth;

    fourth->data=78;
    fourth->next=fifth;

    fifth->data=43;
    fifth->next=NULL;
    
    head=DeleteAfterNode(head,32);
    transver_list(head);

    return 0;
}