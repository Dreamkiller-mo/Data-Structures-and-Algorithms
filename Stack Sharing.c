#include <stdio.h>
#include <stdlib.h>
const MAX = 7;
typedef int ElemType;
typedef struct doublestack
{
    ElemType data[7];
    int top1;
    int top2
}Doublestack;
Doublestack* doublestackInit(Doublestack* dstack)
{
    dstack->top1 = -1;
    dstack->top2 = MAX-1;
}
void doublestackpush(Doublestack* dstack,ElemType e,int stacknumber)
{
    if (dstack->top1+1 == dstack->top2)
    {
        printf("stack is full!");
        exit(-1);
    }
    else if (stacknumber == 1)
    {
        /* Õ»1ÈëÕ» */
        dstack->data[++dstack->top1] = e;
    }
    else if (stacknumber == 2)
    {
        /* Õ»2ÈëÕ» */
        dstack->data[--dstack->top2] = e; 
    }
}
void doublestackpop(Doublestack* dstack,ElemType * e,int stacknumber)
{
    if (dstack->top1 == -1 || dstack->top2 == MAX)
    {
        printf("Error !!!\n");
        exit(-1);
    }
    else
    {
        if (stacknumber == 1)
        {
            /* Õ»1³öÕ» */
            *e = dstack->data[dstack->top1--];
        }
        else if (stacknumber == 2)
        {
            /* Õ»2³öÕ» */
            *e = dstack->data[dstack->top2++];
        }
    }
    
}
void Print(Doublestack* dstack)
{
    for(int i = 0;i<MAX-1;i++)
    {
        printf("%d\t",dstack->data[i]);
    }
}
void Text()
{
    Doublestack* dstack = (Doublestack*)malloc(sizeof(Doublestack));
    doublestackInit(dstack);
    doublestackpush(dstack,1,1);
    doublestackpush(dstack,3,1);
    doublestackpush(dstack,5,1);
    doublestackpush(dstack,90,2);
    doublestackpush(dstack,80,2);
    doublestackpush(dstack,70,2);
    ElemType e;
    doublestackpop(dstack,&e,2);
    printf("%d\n",e);
    doublestackpush(dstack,7,1);
    doublestackpop(dstack,&e,2);
    printf("%d\n",e);
    doublestackpush(dstack,9,1);
    Print(dstack);
    free(dstack);
    printf("\n\nclear successful !!!\n");
}
int main()
{
    Text();
    return 0;
}
