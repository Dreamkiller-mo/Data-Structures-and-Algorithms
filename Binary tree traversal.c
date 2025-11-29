#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//二叉树的实现
typedef char ElemType;
typedef struct Queue
{
    struct QueueNode* front;
    struct QueueNode* rear;
}Queue;

//二叉树的结构体
typedef struct BiTreeArra
{
    //成员:1.数据元素 2.左子树 3.右子树
    ElemType data;
    struct BiTreeArra* left;
    struct BiTreeArra* right;
}BiTreeArra;
//为实现层序遍历而引入的队列
typedef struct QueueNode
{
    //应用链表
    BiTreeArra* data;
    struct QueueNode* next;
}QueueNode;
//二叉树前序遍历:根 左子树 右子树
void PreOrder(BiTreeArra* root)
{
    if (root == NULL)
    {
        printf("NULL\t");
        return;
    }
    //根
    printf("%c\t",root->data);
    //左子树
    PreOrder(root->left);
    //右子树
    PreOrder(root->right);
    
}
//二叉树中序遍历:左子树 根 右子树
void InOrder(BiTreeArra* root)
{
    if (root == NULL)
    {
        printf("NULL\t");
        return;
    }
    //左子树
    PreOrder(root->left);
    //根
    printf("%c\t",root->data);
    //右子树
    PreOrder(root->right);
}
//二叉树后序遍历:左子树 右子树 根
void PostOrder(BiTreeArra* root)
{
    if (root == NULL)
    {
        printf("NULL\t");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c\t",root->data);
}

//销毁二叉树
void freeTree(BiTreeArra *root) {
    if (root == NULL) {
        return;
    }
    //先左再右，如果先销毁根就找不到其子树了
    freeTree(root->left);
    freeTree(root->right);
    free(root);
    root = NULL;
}

//树结点的创建
BiTreeArra* Creat(ElemType x)
{
    BiTreeArra* temp = (BiTreeArra*)malloc(sizeof(BiTreeArra));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//计算总的结点个数
int BinTotalNode(BiTreeArra* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return BinTotalNode(root->left)+BinTotalNode(root->right)+1;
}

//计算树的叶结点
int BinLeavesNode(BiTreeArra* root)
{
    if (root->left == NULL && root->right == NULL)
    {
        /* 结点为空 */
        return 1;
    }
    return BinLeavesNode(root->left)+BinLeavesNode(root->right);
    
}
//计算二叉树的深度
int BinLeaverDepth(BiTreeArra* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (BinLeaverDepth(root->left) >= BinLeaverDepth(root->right))
    {
        return BinLeaverDepth(root->left)+1;
    }
    else
    {
        return BinLeaverDepth(root->right)+1;
    }
}
//队列的初始化
Queue* QueueInite()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("queue malloc fail\n");
    }
    queue->front = queue->rear = NULL;
    return queue;
}
//队列的插入---->尾插
void QueuePush(Queue* q,ElemType TreeNode)
{
    assert(q);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(Queue));
    if (newnode == NULL)
    {
        printf("newnode malloc fail\n");
        exit(-1);
    }
    //新结点初始化
    newnode->data = TreeNode;
    newnode->next = NULL;
    if (q->front == NULL)
    {
        //第一个树结点的插入
        q->front = q->rear = newnode;
    }
    //正常的插入操作,先让前一个结点的next指向新结点,再让rear指向新结点；
    q->rear->next = newnode;
    q->rear = newnode;
}
//队列的头出
BiTreeArra* QueuePop(Queue* q)
{
    //保存当前结点，方便后面释放
    QueueNode* current = q->front;
    //保存当前结点所指向的树结点,方便后面访问树结点中的数据元素
    BiTreeArra* TreeNode = q->front->data; 
    //Queue的头结点指向下一个结点
    q->front = q->front->next;
    //释放结点
    free(current);
    //返回该结点指向的树结点
    return TreeNode;
}
//判空
int isQueueEmpty(Queue* q)
{
    return q->front == NULL;
}
//层序遍历的实现
void levelOrderTraveral(BiTreeArra* root)
{
    assert(root);
    //队列的初始化
    Queue* queue = QueueInite();
    //将指向树的根结点指针传进去
    QueuePush(queue,root);
    printf("\n________________________________________________\n");
    while(!isQueueEmpty(queue))
    {
        //用一个临时变量存储头删的结点
        BiTreeArra* current = QueuePop(queue);
        //输出头删结点的数据
        printf("%c\t",current->data);
        //判断该结点是否有左右结点
        if (current->left)
        {
            QueuePush(queue,current->left);
        }
        if (current->right)
        {
            QueuePush(queue,current->right);
        }
    }
    free(queue);
    queue = NULL;
}
//测试函数------>递归方法的实现
void Text_1()
{
    //为每个结点分配空间并初始化
    BiTreeArra* A = Creat('A');
    BiTreeArra* B = Creat('B');
    BiTreeArra* C = Creat('C');
    BiTreeArra* D = Creat('D');
    BiTreeArra* E = Creat('E');
    //建立连接
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    //使用前序遍历
    PreOrder(A);
    //使用中序的遍历
    printf("\n");
    InOrder(A);
    //使用后序的遍历
    printf("\n");
    PostOrder(A);
    printf("\n");
    //总的结点个数
    printf("-————————————————————————————————————————————————————————————————————————————————\n");
    printf("The total node number is %d",BinTotalNode(A));

    //总的叶结点
    printf("\nThe total leaves-node number is %d\n",BinLeavesNode(A));

    //二叉树的深度
    printf("BinTree's depth is %d\n",BinLeaverDepth(A));
    //释放内存
    freeTree(A);
}
//层序遍历------>非递归的实现(队列的应用)
void Text_2()
{
    BiTreeArra* root;
    root = Creat('A');
    root->left = Creat('B');
    root->right = Creat('C');
    root->left->left = Creat('D');
    root->left->right = Creat('E');
    levelOrderTraveral(root);
    freeTree(root);
}

int main()
{
    Text_1();
    return 0;
}