#include<stdlib.h>
#include<stdio.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *sp){
    if(sp->top==-1){
        return 1;
    }
    return 0;
}

int isfull(struct stack *sp){
    if(sp->top == sp->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *sp, char val){
    if(isfull(sp)){
        printf("Stack Overflow\n");
    }
    else{
        sp->top++;
        sp->arr[sp->top]=val;
    }
}

char pop(struct stack *sp){
    if(isempty(sp)){
        printf("Stack Underflow.\n");
    }
    else{
        char val;
        val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int parenthesismatching(char *exp){
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size * sizeof(char));
    char popped_ch;
    printf("stack Created\n");

    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(sp,exp[i]);
        }
        else if(exp[i] == ')' || exp[i]==']' || exp[i]=='}'){
            if(isempty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i])){
                return 0;
            }
        }
    }
    if(isempty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    char *exp = "[4+5]";
    if(parenthesismatching(exp)){
        printf("Parenthesis Matching\n");
    }
    else{
        printf("Parenthesis Not Matching\n");
    }

    return 0;
}