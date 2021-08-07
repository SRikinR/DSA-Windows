#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linked_list(struct node *ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct node *head  =(struct node *)malloc(sizeof(struct node));
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //head=(struct node *)malloc(sizeof(struct node));
    first=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=first;

    first->data=17;
    first->next=second;

    second->data=27;
    second->next=third;

    third->data=37;
    third->next=fourth;

    fourth->data=47;
    fourth->next=NULL;

    linked_list(head);
    return 0;


}