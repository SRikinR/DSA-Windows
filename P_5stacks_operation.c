#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr){
    if (ptr->top == -1){
        // printf("Stack is Empty.\tStack Underflow\t");
        return 1;
    }
    return 0;
}

int isfull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        // printf("\nStack OVERFLOW\t");
        return 1;
    }
    return 0;
}

int push(struct stack *ptr, int value){
    if(isfull(ptr)){
        printf("Stack OVERFLOW!!");
    }
    else{
        ptr->top+=1;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("Stack UNDERFLOW.");
    }
    else{
        int value;
        value=ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped %d \n",value);
    }
}

int peek(struct stack *ptr,int i){
    int indarr= ptr->top-i+1;
    if(indarr<0){
        printf("Invalid Search");
    }
    else{
        printf("Peek at index %d is %d \n",i,ptr->arr[indarr]);
    }
}

int top(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int bottom(struct stack *ptr){
    return ptr->arr[0];
}

int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=8;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("Stack Created Successfully.\n");;

    printf("Empty: %d\n",isempty(sp));
    printf("Full: %d\n",isfull(sp));

    printf("%d\n",push(sp,45));
    printf("%d\n",push(sp,34));
    printf("%d\n",push(sp,4));
    printf("%d\n",push(sp,5));
    printf("%d\n",push(sp,41));
    printf("%d\n",push(sp,42));
    pop(sp);
    pop(sp);
    peek(sp,2);
    printf("Top Element: %d \n",top(sp));
    printf("Bottom Element: %d \n",bottom(sp));

    return 0;   
}