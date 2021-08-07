#include<stdio.h>
#include<stdlib.h>

struct apna{
    int total_size;
    int used_size;
    int *ptr;
};

void bana(struct apna *a, int tsize, int usize)
{
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)malloc(tsize*sizeof(int));
}

void daal(struct apna *a){
    for (int i=0; i< a->used_size;i++){
    int n;
    printf("enter the value:");
    scanf("%d",&n);
    a->ptr[i]=n;
}}

void chaap(struct apna *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Entered values are:");
        printf("%d\n",(a->ptr[i]));
    }
}

int main(){
    struct apna mark;
    bana(&mark,10,3);
    printf("dallo\n");
    daal(&mark);
    printf("chaapo\n");
    chaap(&mark);
    return 0;
}   