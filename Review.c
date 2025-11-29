#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//线性表的实现---->静态
const Max = 100;
typedef int ElemType;
typedef struct List
{
    ElemType data[100];
    int lenth;
}List;
//动态顺序表的结构体
typedef struct DynamicArr
{
    ElemType* pointer;
    int len;
    int capacity;
}DyArr;
//带头的单向不循环链表的结构体
typedef struct LinkList
{
    ElemType data;
    struct LinkList* next;
}LinkList;
//循环链表的结构体
typedef struct SinglyCircular
{
    ElemType data;
    struct SinglyCircular* next;
}SClink;
//栈的结构体
typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
}StackNode;
//链栈的结构体
typedef struct LinkStack
{
    StackNode* top;
    int count;
}LinkStack;
//队列的结构体
typedef struct QNode
{
    ElemType data;
    struct QNode* next;
}QNode;
typedef struct LinkQueue
{
    QNode* front;
    QNode* rear;
}LinkQueue;
//二叉树的结构体
typedef struct BinTree
{
    ElemType data;
    struct BinTree* left;
    struct BinTree* right;
}BinTree;
//线性表初始化
void SqInite(List* s)
{
    assert(s);
    s->lenth = 0;
}
//线性表的创建
List* ListCreat()
{
    List* temp = (List*)malloc(sizeof(List));
    if (temp == NULL)
    {
        printf("temp malloc fail\n");
        exit(-1);
    }
    SqInite(temp);
    return temp;
}
//增
void ListInsert(List* s,int pos,ElemType x)
{
    if (pos > s->lenth+1 || pos < 1)
    {
        printf("pos is over arr's lenth\n");
        return;
    }
    if (pos == Max)
    {
        printf("pos over arr's Max\n");
        return;
    }
    for (int i = s->lenth; i >= pos; i--)
    {
        s->data[i+1] = s->data[i];   
    }
    s->data[pos] = x;
    s->lenth++;
}
//删
void ListDelete(List* s,int pos ,ElemType* e)
{
    assert(s);
    if (pos > s->lenth+1 || pos < 1)
    {
        printf("pos is unmeaning\n");
        exit(-1);
    }
    if(pos == Max)
    {
        printf("pos arrive Max\n");
        exit(-1);
    }
    *e = s->data[pos];
    for (int i = pos; i <= s->lenth; i++)
    {
        s->data[i] = s->data[i+1];
    }
    s->lenth--;
}
//查
void ListCheck(List* s,ElemType pos,ElemType* e)
{
    assert(s);
    if (pos > s->lenth+1 || pos < 1)
    {
        printf("pos is unmeaning\n");
        exit(-1);
    }
    if(pos == Max)
    {
        printf("pos arrive Max\n");
        exit(-1);
    }
    *e = s->data[pos];
}
//改
void ListChange(List* s,int pos,ElemType x)
{
    assert(s);
    if (pos > s->lenth+1 || pos < 1)
    {
        printf("pos is unmeaning\n");
        exit(-1);
    }
    if(pos == Max)
    {
        printf("pos arrive Max\n");
        exit(-1);
    }
    s->data[pos] = x;

}
//打印
void ListPrint(List* s)
{
    assert(s);
    for (int i = 1; i <= s->lenth; i++)
    {
        printf("%d\t",s->data[i]);
    }
    
}
//销毁
void Destroy(List* s)
{
    assert(s);
    free(s);
    s = NULL;
}
//静态顺序表
void Text_1()
{
    List* s = ListCreat();
    ListInsert(s,1,1);
    ListInsert(s,2,2);
    ListInsert(s,3,3);
    ListInsert(s,4,4);
    ListInsert(s,5,5);
    ListInsert(s,2,99);
    int e;
    ListDelete(s,3,&e);
    printf("delete a data %d\n",e);
    ListCheck(s,2,&e);
    printf("find a data %d\n",e);
    ListChange(s,4,44);
    ListPrint(s);
    Destroy(s);
}
//动态顺序表的初始化
void DyArrInite(DyArr* p)
{
    assert(p);
    p->capacity = p->len = 0;
    p->pointer = NULL;
}
//动态顺序表的创建
DyArr* DyArrCreat()
{
    DyArr* temp = (DyArr*)malloc(sizeof(DyArr));
    DyArrInite(temp);
    if (temp == NULL)
    {
        printf("DyArr malloc fail\n");
        exit(-1);
    }
    ElemType* p = (ElemType*)malloc(sizeof(ElemType)*4);
    if (p == NULL)
    {
        printf("p malloc fail\n");
        exit(-1);
    }
    temp->pointer = p;
    temp->capacity = 4;
    return temp;
}
//动态扩容
void DyArrAdd(DyArr* p)
{
    assert(p);
    int newcapacity = p->capacity * 2;
    ElemType *newData = (ElemType*)realloc(p->pointer, sizeof(ElemType) * newcapacity);
    if (newData == NULL)
    {
        printf("扩容失败!\n");
        return -1;
    }
    p->pointer = newData;
    p->capacity = newcapacity;
}
//增
void DyArrInsert(DyArr* p,int pos,ElemType x)
{
    assert(p);
    if (p->len >= p->capacity)
    {
        DyArrAdd(p);
    }
    if (pos > p->len+1 || pos < 1)
    {
        printf("pos is unmeaning\n");
        return;
    }
    if(pos >= p->capacity)
    {
        printf("pos arrive capacity\n");
        DyArrAdd(p);
    }
    for (int i = p->len; i >= pos; i--)
    {
        p->pointer[i+1] = p->pointer[i];
    }
    p->pointer[pos] = x;
    p->len++;
}
//删
void DyArrDelete(DyArr* p,int pos ,ElemType * e)
{
    assert(p);
    if (p->len < 1)
    {
        printf("the DyArr is empty");
        return;
    }
    *e = p->pointer[pos];
    for (int i = pos; i <= p->len; i++)
    {
        p->pointer[i] = p->pointer[i+1];
    }
    p->len--;
}
//查找其中是非有其元素
void DyArrCheck(DyArr* p,ElemType x)
{
    assert(p);
    for (int i = 1; i <= p->len; i++)
    {
        if (p->pointer[i] == x)
        {
            printf("the elem in %d was found!!!\n",i);
            return;
        }
        else if(i >= p->len+1)
        {
            printf("range is over,the elem wasn't found\n");
            return;
        }
        
    }
    
}
//改
void DyArrChange(DyArr* p,int pos,ElemType x)
{
    assert(p);
    if (pos < 1)
    {
        return;
    }
    if (pos > p->capacity || pos>p->len)
    {
        return;
    }
    p->pointer[pos] = x;
}
//打印
void DyArr_Print(DyArr* p)
{
    assert(p);
    for (int i = 1; i <= p->len; i++)
    {
        printf("%d\t",p->pointer[i]);
    }
    
}
//销毁
void DyArr_Destroy(DyArr* p)
{
    assert(p);
    free(p->pointer);
    p->pointer = NULL;
    free(p);
    p = NULL;
}
//动态顺序表
void Text_2()
{
    DyArr* p = DyArrCreat();
    DyArrInsert(p,1,1);
    DyArrInsert(p,2,2);
    DyArrInsert(p,3,3);
    DyArrInsert(p,4,4);
    DyArrInsert(p,5,5);
    DyArrInsert(p,2,22);
    ElemType e;
    DyArrDelete(p,p->len,&e);
    printf("you delete %d\n",e);
    DyArrCheck(p,22);
    DyArrChange(p,1,11);
    DyArr_Print(p);
    DyArr_Destroy(p);
}
//单链表的初始化
LinkList* LinkListInite()
{
    LinkList* head = (LinkList*)malloc(sizeof(LinkList));
    if (head == NULL)
    {
        printf("head node malloc fail\n");
        exit(-1);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}
//头插
void LinkListHead(LinkList* phead,ElemType x)
{
    assert(phead);
    LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
    if (newnode == NULL)
    {
        printf("newnode malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = phead->next;
    phead->next = newnode;
}
//尾插
void LinkListTail(LinkList* phead,ElemType x)
{
    assert(phead);
    LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
    if (newnode == NULL)
    {
        printf("newnode_tail_insert malloc fail");
        exit(-1);
    }
    //找尾指针
    LinkList* tail = phead->next;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    //实现尾插
    newnode->data = x;
    tail->next = newnode;
    newnode->next = NULL;
}
//头删
void LinkListHeadDelete(LinkList* phead)
{
    assert(phead);
    LinkList* q = phead->next->next;
    free(phead->next);
    phead->next = q;
}
//尾删
void LinkListTailDelete(LinkList* phead)
{
    assert(phead);
    //找尾指针前一个
    LinkList* tail = phead;
    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }
    free(tail->next);
    tail->next = NULL;
}
//查
void LinkListCheck(LinkList* phead,ElemType x)
{
    assert(phead);
    LinkList* temp = phead->next;
    while (temp != NULL)
    {
        if(temp->data == x)
        {
            printf("the elem is in linklist\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("no found the elem in the linklist\n");
    }
    
}
//改
void LinkListChange(LinkList* phead,int pos,ElemType x)
{
    assert(phead);
    LinkList* temp = phead->next;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;   
    }
    temp->data = x;
    temp = NULL;
}
//打印
void LinkListPrint(LinkList* phead)
{
    assert(phead);
    LinkList* temp = phead->next;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}
//销毁
void LinkLinkDestoy(LinkList* phead)
{
    assert(phead);
    LinkList* next;
    LinkList* front = phead;
    while (front != NULL)
    {
        next = front->next;
        free(front);
        front = next;
    }
    phead = NULL;
}
//带头的单向不循环链表的实现
void Text_3()
{
    LinkList* phead = LinkListInite();
    LinkListHead(phead,1);
    LinkListHead(phead,2);
    LinkListHead(phead,3);
    LinkListHead(phead,4);
    LinkListHead(phead,5);
    LinkListHead(phead,6);
    LinkListTail(phead,0);
    LinkListTail(phead,1);
    LinkListTail(phead,2);
    LinkListTail(phead,3);
    LinkListHeadDelete(phead);
    LinkListHeadDelete(phead);
    LinkListHeadDelete(phead);
    LinkListTailDelete(phead);
    LinkListCheck(phead,2);
    LinkListCheck(phead,6);
    LinkListChange(phead,2,100);
    LinkListPrint(phead);
    LinkLinkDestoy(phead);
}
//循环链表的初始化
void SCLinklistIninte(SClink* phead)
{
    assert(phead);
    phead->data = 0;
    phead->next = phead;
}
//循环链表的创建
SClink* SCLinklistCreat()
{
    SClink* temp = (SClink*)malloc(sizeof(SClink));
    if (temp == NULL)
    {
        printf("temp malloc fail\n");
        exit(-1);
    }
    SCLinklistIninte(temp);
    return temp;
}
//增
void SCLinklistInsert(SClink* phead,ElemType x)
{
    assert(phead);
    LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
    if (newnode == NULL)
    {
        printf("newnode_tail_insert malloc fail");
        exit(-1);
    }
    //找尾指针
    if (phead->next == NULL)
    {
        newnode->data = x;
        phead->next = newnode;
        newnode->next = phead;
    }
    LinkList* tail = phead->next;
    while(tail->next != phead)
    {
        tail = tail->next;
    }
    //实现尾插
    newnode->data = x;
    tail->next = newnode;
    newnode->next = phead;

}
//添加元素尾插
void SCLinklistAdd(LinkList* phead,int len)
{
    assert(phead);
    for (int i = 1; i <= len; i++)
    {
        SCLinklistInsert(phead,i);
    }
    
}
//二个循环链表融合
void BinSCLinklist(SClink* phead,SClink* p)
{
    assert(phead);
    assert(p);
    //尾指针
    SClink* rear1;
    SClink* rear2;
    SClink* temp_1 = phead->next;
    SClink* temp_2 = p->next;
    while (temp_1->next != phead)
    {
        temp_1 = temp_1->next;
    }
    rear1 = temp_1;
    while (temp_2->next != p)
    {
        temp_2 = temp_2->next;
    }
    rear2 = temp_2;
    SClink* head_1 = rear1->next;
    SClink* head_2 = rear2->next; 
    SClink* first_2 = rear2->next->next;
    rear1->next = first_2;
    rear2->next =head_1;
    free(head_2);
    head_2 = NULL; 
}
//打印
void SCLinklistPrint(SClink* phead)
{
    assert(phead);
    SClink* temp = phead->next;
    while (temp != phead)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}
//销毁
void SCLinlistDestroy(SClink* phead)
{
    assert(phead);
    SClink* temp = phead->next;
    SClink* next = NULL;
    while (temp != phead)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(phead);
    phead = NULL;
}
//循环链表的实现
void Text_4()
{
    SClink* phead = SCLinklistCreat();
    SCLinklistAdd(phead,4);
    SClink* p = SCLinklistCreat();
    SCLinklistInsert(p,5);
    SCLinklistInsert(p,6);
    SCLinklistInsert(p,7);
    BinSCLinklist(phead,p);
    SCLinklistPrint(phead);
    SCLinlistDestroy(phead);
} 
//栈的实现
//链栈的初始化
LinkStack* LinkStackInite()
{
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    assert(s);
    s->top = NULL;
    s->count = 0;
    return s;
}
//压栈
void StackPush(LinkStack*s,ElemType x)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL)
    {
        printf("stack creat malloc fail\n");
        exit(-1);
    }
    temp->data = x;
    temp->next = s->top;
    s->top = temp;
    s->count++;
}
//出栈
void StackPop(LinkStack* s,ElemType* e)
{
    assert(s);
    StackNode* p = s->top;
    *e = s->top->data;
    s->top = s->top->next;
    free(p);
    p = NULL;
    s->count--;
}
void Text_5()
{
    ElemType e;
    LinkStack* s = LinkStackInite();
    StackPush(s,1);
    StackPop(s,&e);
    printf("%d\t",e);
    StackPush(s,2);
    StackPop(s,&e);
    printf("%d\t",e);
    StackPush(s,3);
    StackPush(s,4);
    StackPop(s,&e);
    printf("%d\t",e);
    StackPop(s,&e);
    printf("%d\t",e);
}
//队列的实现
//队列的初始化
LinkQueue* QueueInite()
{
    LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
    if (q == NULL)
    {
        printf("q malloc fail!!!");
        exit(-1);
    }
    q->front = q->rear = NULL;
    return q;
}
//入队
void QueuePush(LinkQueue* q,ElemType x)
{
    assert(q);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        printf("QNOde newnode malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    if (q->front == NULL)
    {
        q->front = q->rear = newnode;
        newnode->next = NULL;
    }
    q->rear->next = newnode;
    newnode->next = NULL;
    q->rear = newnode;
}
//出队
void QueuePop(LinkQueue* q,ElemType* e)
{
    assert(q);
    *e = q->front->data;
    QNode* temp = q->front;
    q->front = q->front->next;
    if (temp == NULL)
    {
        printf("Queue front over!!!");
        exit(-1);
    }
    free(temp);
    temp = NULL;
}
void Text_6()
{
    LinkQueue* q = QueueInite();
    QueuePush(q,1);
    QueuePush(q,2);
    QueuePush(q,3);
    QueuePush(q,4);
    QueuePush(q,5);
    QueuePush(q,6);
    ElemType e;
    QueuePop(q,&e);
    printf("%d\t",e);
    QueuePop(q,&e);
    printf("%d\t",e);
    QueuePop(q,&e);
    printf("%d\t",e);
    QueuePop(q,&e);
    printf("%d\t",e);
    QueuePop(q,&e);
    printf("%d\t",e);
    QueuePop(q,&e);
    printf("%d\t",e);
    free(q);
    q = NULL;
}
//二叉树的实现
//创建
BinTree* BinTreeCreat(ElemType x)
{
    BinTree* temp = (BinTree*)malloc(sizeof(BinTree));
    if (temp == NULL)
    {
        exit(-1);
    }
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
//前序遍历
void PreOrder(BinTree* T)
{
    if (T == NULL)
    {
        printf("NULL\t");
        return;
    }
    printf("%d\t",T->data);
    PreOrder(T->left);
    PreOrder(T->right);
}
//中序遍历
void InOrder(BinTree* T)
{
    if (T == NULL)
    {
        printf("NULL\t");
        return;
    }
    PreOrder(T->left);
    printf("%d\t",T->data);
    PreOrder(T->right);
}
//后序遍历
void OutOrder(BinTree* T)
{
    if (T == NULL)
    {
        printf("NULL\t");
        return;
    }
    PreOrder(T->left);
    PreOrder(T->right);
    printf("%d\t",T->data);
}
//删
void BinTreeDestroy(BinTree* T)
{
    if (T == NULL)
    {
        return;
    }
    BinTreeDestroy(T->left);
    BinTreeDestroy(T->right);
    free(T);
}
void Text_7()
{
    BinTree* num_1 = BinTreeCreat(1);
    BinTree* num_2 = BinTreeCreat(2);
    BinTree* num_3 = BinTreeCreat(3);
    BinTree* num_4 = BinTreeCreat(4);
    BinTree* num_5 = BinTreeCreat(5);
    BinTree* num_6 = BinTreeCreat(6);
    num_1->left = num_2;
    num_1->right = num_3;
    num_2->left = num_4;
    num_2->right = num_5;
    num_4->left = num_4->right = NULL;
    num_5->left = num_5->right = NULL;
    num_3->left = num_6;
    num_3->right = NULL;
    num_6->left = num_6->right = NULL;
    PreOrder(num_1);
    printf("\n");
    InOrder(num_1);
    printf("\n");
    OutOrder(num_1);
    printf("\n");
    BinTreeDestroy(num_1);
}
int main()
{
    Text_7();
    return 0;
}