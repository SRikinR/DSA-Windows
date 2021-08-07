#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void transverse_list(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Elements: %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));;
    struct Node *second=(struct Node *)malloc(sizeof(struct Node));;
    struct Node *third=(struct Node * )malloc(sizeof(struct Node));;
    struct Node *fourth=(struct Node *)malloc(sizeof(struct Node));;
    struct Node *insertation =(struct Node *)malloc(sizeof(struct Node));

    //1st
    head->data=1;
    head->next=second;

    //2nd
    second->data=2;
    second->next=third;

    // //insertation
    // insertation->data=23;
    // insertation->next=third;

    //3rd
    third->data=3;
    third->next=fourth;

    //4th
    fourth->data=4;
    fourth->next=NULL;

    transverse_list(head);

    return 0;

}