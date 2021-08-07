#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value){
    if(isfull(ptr)){
        printf("Stack OverFlow!, Cannot Push %d to stack.\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("Stack Underflow, cannot pop from the stack.\n");
        return -1; //assuming -1 will neven be in my stack.
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=8;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("Stack Created Successfully.\n");

    printf("Empty %d\n",isempty(sp));
    printf("Full %d\n",isfull(sp));
    push(sp,11);
    push(sp,23);
    push(sp,565);
    push(sp,36);
    push(sp,4);
    //push(sp,563);
    //push(sp,46);
    //push(sp,6);
    push(sp,56);
    printf("Empty %d\n",isempty(sp));
    printf("Full %d\n",isfull(sp));
    printf("TOP: %d\n",sp->top);
    
    printf("Pooped %d from the stack\n",pop(sp));
    printf("Pooped %d from the stack\n",pop(sp));   

    return 0;
}