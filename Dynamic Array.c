#include <stdio.h>
#include <stdlib.h>

//动态顺序表----->扩容
typedef int ElemType;
typedef struct
{
    //一个指向ElemType类型的指针变量
    ElemType *p_data;
    //当前数据大小
    int size;
    //当前表分配给数据的内存容量大小
    int capacity;
}Node;
typedef Node * SeqList;

//初始化顺序表,数据指针变量设为NULL,size,capacity先设为0
void SeqListInit(SeqList ps)
{
    ps->p_data = NULL;
    ps->size = 0;
    ps->capacity = 0;
}
void SeqListPushBack(SeqList ps,ElemType x)
{
    if(ps->capacity == ps->size)
    //先检查内存空间的大小，判断是否要扩容
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
        ElemType *temp = (ElemType*)realloc(ps->p_data,newcapacity*sizeof(Node));
        if (temp == NULL)
        {
            printf("realloc fall!\n");
            exit(-1);
        }
        ps->p_data = temp;
        ps->capacity = newcapacity;
    }
    //然后在尾部插入数据，size就是要插入数据的下表
    ps->p_data[ps->size] = x;
    ps->size++;
    //最后size++;
}
void SeqListDelete(SeqList ps)
{
    free(ps->p_data);
    ps->capacity = ps->size = 0;
    ps->p_data = NULL;
}
void SeqListPrint(SeqList ps)
{
    for(int i = 0;i < ps->size;i++)
    {
        printf("%d\t",ps->p_data[i]);
    }
}
int main()
{
    Node list;
    SeqList ps = &list;
    SeqListInit(ps);
    SeqListPushBack(ps,1);
    SeqListPushBack(ps,2);
    SeqListPushBack(ps,3);
    SeqListPushBack(ps,4);
    SeqListPushBack(ps,5);
    SeqListPrint(ps);
    SeqListDelete(ps);
}
