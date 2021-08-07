#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myarray *a, int tsize, int usize){
    //(*a).total_size = tsize;
    //(*a).used_size = usize;
    //(*a).ptr = (int*)malloc(tsize*sizeof(int));

    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize*sizeof(int));
}

void setval(struct myarray *a){
    for (int i = 0; i<a->used_size; i++)
    {
        int n;
        printf("Enter the Element");
        scanf("%d",&n);
        a->ptr[i] = n;
    }
    
}

void show(struct myarray* a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n",(a->ptr[i]));
    }
}

int main(){
    struct myarray marks;
    createArray(&marks,10,2);
    printf("Setval Function is running now.\n");
    setval(&marks);

    printf("show function is running now\n");
    show(&marks);

    return 0;
}

