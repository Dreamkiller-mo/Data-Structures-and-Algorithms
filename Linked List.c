#include <stdio.h>
#include <stdlib.h>

// write your code here......
typedef int ElemType ;
//定义链表的结点
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
    struct LinkNode* prev;
}LinkNode;
//链表初始化
LinkNode* LinkInite()
{
    LinkNode* phead = (LinkNode*)malloc(sizeof(LinkNode));
    if (phead == NULL) 
    {
        printf("phead malloc error!\n");
    }
    phead->data = 0;
    phead->next = phead;
    phead->prev = phead;
    return phead;
}
//增加元素进入链表
void LinkPush(LinkNode* p,ElemType x)
{
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    if (newnode == NULL)
    {
        printf("newnode malloc fail!\n");
    }
    newnode->data = x;
    newnode->next = p;
    newnode->prev = p->prev;
    p->prev->next = newnode;
    p->prev = newnode;

}
//打印函数
void Print(LinkNode* phead)
{
    LinkNode* temp = phead->prev;
    while (phead != temp)
    {
        printf("%d\t",phead->next->data);
        phead = phead->next;
    }
}
//销毁链表
void Destory(LinkNode* phead)
{
    //创建一个临时指针指向phead的下一个结点
    LinkNode* first = phead->next;
    LinkNode* second = NULL;
    while (first != phead)
    {
        second = first->next;
        free(first);
        first = second;
    }
    phead = NULL;
    first = second = NULL;
    
}
int main() {

    int n;
    scanf("%d",&n);

    int* arr=(int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }

    // write your code here......
    LinkNode* p = LinkInite();
    for (int i = 0; i < n; i++) {
        LinkPush(p, arr[i]);
    }
    Print(p);
    Destory(p);
    free(arr);
    return 0;
}
