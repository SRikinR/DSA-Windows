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
    else{
        return 0;
    }
}

int isfull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack *ptr, int value){
    if(isfull(ptr)){
        printf("Stack OVERFLOW, %d can't be PUSHED",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("Stack UNDERFLOW, It's empty");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int i){
    int indarr = ptr->top-i+1;
    //if(ptr->top-i+1 < 0)
    if(indarr < 0){
        printf("Not a valid position.");
    }
    else{
        return ptr->arr[indarr];
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}


int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=8;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size * sizeof(int));

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
    
    printf("Popped %d from the stack\n",pop(sp));
    printf("Popped %d from the stack\n",pop(sp));

    // for(int j=1;j<=sp->top+1;j++){
    // printf("The value of Position %d is %d: \n",j,peek(sp,j));
    // }
    printf("Toppest Value of the stack is: %d\n", stackTop(sp));
    printf("Bottom Value of the stack is: %d\n",stackBottom(sp));

    return 0;
}