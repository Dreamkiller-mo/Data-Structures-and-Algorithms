#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef int HeapDataType;
typedef struct Heap
{
    HeapDataType* _arr;
    int _size;
    int _capacity;
}Heap;
//排小堆    --->小的数在上面
void AdjustDown(HeapDataType* arr , int size , int root)
{
    //选取最小的孩子
    int parent = root;
    int child = parent * 2 + 1;         //默认是左孩子
    while(child < size)
    {
        if(child + 1 < size && arr[child + 1] < arr[child]) ++child;
        //和父节点进行比较
        if(arr[child] < arr[parent])
        {
            Swap(&arr[child],&arr[parent]);
            parent = child;
            child = parent*2+1;
        }
        else break;
    }
}
//初始化 
void Inite_Heap(Heap* php,HeapDataType* a,int len)
{
    //先给堆的数组指针一块空间
    php->_arr = (HeapDataType*)malloc(sizeof(HeapDataType)*len);
    assert(php->_arr != NULL);
    //将传入进来的数组拷贝到堆上        
    memcpy(php->_arr,a,sizeof(HeapDataType)*len);
    //更新size and capacity
    php->_size = php->_capacity = len;

    //构建堆
    for(int i = (len-2)/2 ; i >= 0 ; i--)
    {
        AdjustDown(php->_arr,php->_size,i);
    }

}
void Swap(HeapDataType* p1,HeapDataType* p2)
{
    HeapDataType temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Text_heap()
{
    Heap hp;
    int list[]={27,15,19,18,28,34,65,49,25,37};
    Inite_Heap(&hp,list,sizeof(list)/sizeof(HeapDataType));
    for(int i = 0; i < sizeof(list)/sizeof(HeapDataType) ; i++)
    {
        printf("%d ",hp._arr[i]);
    }

}
void Text_heap_sort()
{
    Heap hp;
    int list[]={45,2,15,89,65,425,11,445,1,39,33,666,8};
    int len = sizeof(list)/sizeof(HeapDataType);
    Inite_Heap(&hp,list,len);
    for(int i = 0 ; i < sizeof(list)/sizeof(int) ; i++)
    {
        Swap(&hp._arr[0],&hp._arr[len-1]);
        AdjustDown(hp._arr,len-1,0);
        --len;
    }
    for(int i = 0; i < sizeof(list)/sizeof(HeapDataType) ; i++)
    {
        printf("%d ",hp._arr[i]);
    }
}
int main()
{
    Text_heap_sort();
}