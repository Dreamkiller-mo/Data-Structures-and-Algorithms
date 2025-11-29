//带头双向循环链表的实现
//引入相应的头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//自定义数据类型
typedef int ElemType;
//定义双向循环链表的结构体
typedef struct ListNode
{
    //结构体成员:数据，前驱，后继
    ElemType data;
    struct ListNode * prev;
    struct ListNode * next;
}ListNode;
//初始化双向循环链表
ListNode * ListInit()
{
    //创建头结点并将其前驱后后继都指向自己
    ListNode * phead = (ListNode*)malloc(sizeof(ListNode));
    phead->data = 0;
    phead->prev = phead;
    phead->next = phead;

}
//销毁链表
void Destory(ListNode* phead)
{
    //创建一个临时指针指向phead的下一个结点
    ListNode* temp = NULL;
    while (temp != phead)
    {
        temp = phead->next;
        free(phead);
        phead = temp;
    }
    phead = NULL;
    
}
//尾插
void ListPushBack(ListNode* phead,ElemType x)
{
    //先给新结点一片内存空间
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->data = x;
    //然后找到尾结点tail
    ListNode* tail = phead->prev;
    //将尾结点的next指向新结点，新结点的prev指向尾结点
    tail->next = newnode;
    newnode->prev = tail;
    //再将phead的prev指向新结点，新结点的next指向phead
    phead->prev = newnode;
    newnode->next = phead;
    //注意当链表为空（但不包含头结点）时也满足，所以不需要单独讨论
}
//头插
void ListPushFront(ListNode* phead,ElemType x)
{
    //给空间
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    //赋值x给data,定义一个中间指针，指向第一个结点
    ListNode* temp = phead->next;
    newnode->data = x;
    //phead的next指向新节点，新节点prev指向phead
    phead->next = newnode;
    newnode->prev = phead;
    //新结点的next指向第一个结点，第一个结点的prev指向新结点
    newnode->next = temp;
    temp->prev = newnode;
}
//尾删
void ListPopBack(ListNode * phead)
{
    assert(phead);
    //找到尾结点
    ListNode* tail = phead->prev;
    //phead的prev指向尾结点的前一个
    phead->prev = tail->prev;
    //尾结点的前一个结点的next指向phead
    tail->prev->next = phead;
    //free掉尾结点
    free(tail);
    tail = NULL;
}
//头删
void ListPopFront(ListNode* phead)
{
    assert(phead);
    //创建中间指针，指向第二个结点
    ListNode* second = phead->next->next;
    //free掉第一个结点
    ListNode* first = phead->next;
    free(first);
    first = NULL;
    //phead的next指向第二个结点
    phead->next = second;
    //第二个结点的prev指向phead
    second->prev = phead;

}
//查找
ListNode* ListElemFind(ListNode* phead,ElemType x)
{
    assert(phead);
    ListNode* cur = phead->next;
    while (cur != phead)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
//在pos前位置插入一个值
void ListInsertFront(ListNode* phead,ElemType x,ListNode* pos)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->data = x;
    pos->prev->next = newnode;
    newnode->prev = pos->prev;
    pos->prev = newnode;
    newnode->next = pos;
}
//打印
void Print(ListNode* phead)
{
    ListNode* temp = phead->prev;
    while (phead != temp)
    {
        printf("%d\t",phead->next->data);
        phead = phead->next;
    }
}
//测试函数1
void Text1()
{
    ListNode* phead = ListInit();
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,4);
    ListPushBack(phead,5);
    ListPushBack(phead,6);
    Print(phead);
    printf("\n");
    ListPushFront(phead,-1);
    ListPushFront(phead,-2);
    Print(phead);
    printf("\n");
    ListPopBack(phead);
    ListPopBack(phead);
    Print(phead);
    printf("\n");
    ListPopFront(phead);
    ListPopFront(phead);
    Print(phead);
    printf("\n");
    ListNode* pos = ListElemFind(phead,3);
    if (pos)
    {
        //查找并修改
        pos->data *= 10;
        printf("Find !!!\n");
    }
    else
    {
        printf(" No Find The Number!\n");
    }
    Print(phead);
    printf("\n");
    ListInsertFront(phead,10,pos);
    ListInsertFront(phead,20,pos);
    Print(phead);
    Destory(phead);

}
//测试函数2
void Text2()
{

}
//主函数
int main()
{
    Text1();
    return 0;
}