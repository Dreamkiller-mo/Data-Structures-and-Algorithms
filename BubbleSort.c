#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
//定义一个顺序表结构
typedef struct 
{
    int r[MAXSIZE+1];
    int length;
}SqList;
//交换函数---->交换第i与第j位置上的数据
void Swap(SqList * L,int i,int j)
{
    //定义一个中间变量
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
SqList * Creat()
{
    SqList *L = (SqList *)malloc(sizeof(SqList));
    printf("请输入你要定义的顺序列表的长度:");
    scanf("%d",&L->length);
    for (int i = 1; i < L->length+1; i++)
    {
        /* 循环输入数据 */
        printf("请输入第%d个数:",i);
        scanf("%d",&L->r[i]);
    }
    
    return L;
}
void BubbleSort0(SqList *L)
{
    //从前向后去比较排序
    for (int i = 1; i < L->length+1; i++)
    {
        for (int j = i+1; j < L->length+1; j++)
        {
            if (L->r[i] > L->r[j])
            {
                Swap(L,i,j);
            }
            
        }
        
    }
}
void BubbleSort1(SqList *L)
{
    //从后向前去比较排序
    for (int i = 1; i < L->length+1; i++)
    {
        for (int j = L->length-1; j >= i; j--)
        {
            if (L->r[j] > L->r[j+1])
            {
                Swap(L,i,j);
            }
            
        }
        
    }
    
}
void BubbleSort2(SqList * L)
{
    //如果只有一处需要排序，后面已经不需要的情况下经行冒泡排序的优化
    //添加一个标识flag
    static flag = 1;
    for (int i = 1; i < L->length+1 && flag == 1; i++)
    {
        flag = 0;
        for (int j = L->length-1; j >= i; j--)
        {
            if (L->r[j] > L->r[j+1])
            {
                Swap(L,i,j);
                flag = 1;
            }
            
        }
        
    }
}
void Print(SqList * L)
{
    for (int i = 1; i < L->length+1; i++)
    {
        printf("%d\t",L->r[i]);
    }
    
}
int main()
{
    SqList * L = Creat();
    printf("-----创建成功!!!-----\n");
    BubbleSort2(L);
    printf("----排序成功----\n");
    Print(L);
    free(L);
    return 0;
}