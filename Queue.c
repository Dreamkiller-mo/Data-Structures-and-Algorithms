#include <stdio.h>
#include <stdlib.h>
//定义队列的结构体结点
typedef int QElemType;
typedef struct QueueNode
{
    QElemType data;
    QueueNode* next;
}QueueNode;
//队列的头指针和尾指针
typedef struct Queue
{
    QueueNode * head;
    QueueNode * rear;
}Queue;
//初始化队列
void QueueInite(Queue* q)
{
    q->head = NULL;
    q->rear = NULL;
}
//插入队列，只能在队尾插入，对头删除
void QueuePush(Queue* q,QElemType x)
{
    //创建结点的空间
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    //初始化新结点
    newnode->data = x;
    newnode->next = NULL;
    //对尾结点经行判断是否为空队列
    if (q->rear == NULL)
    {
        //如果队列为空，那么让头指针和尾指针都指向第一个结点
        q->head = q->rear = newnode;
    }
    //如果不是第一个结点，就让尾指针指向的这个结点的next指向新结点
    q->rear->next = newnode;
    //尾指针++
    q->rear++;
}
//销毁队列
void Destroy(Queue* q)
{
    
}
//测试函数
void Text()
{
    Queue q;
    QueueInite(&q);
}
int main()
{
    Text();
    return 0;
}