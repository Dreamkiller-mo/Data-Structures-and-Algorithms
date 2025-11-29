#include <stdio.h>
#include <stdlib.h>
typedef struct Seeing_location
{
    /* 结点 */
    char name[10];      //结点数据域
    int number;
    struct Seeing_location * p_next;        //指针域
}Node;
Node * Creat_node(int * sum)
{
    //引入头指针和尾指针------>使用malloc函数创建空间
    Node *head,*p_end,*p_new;
    p_end = p_new = (struct Seeing_location*)malloc(sizeof(Node));
    //引入新指针p_new,并将头指针指向null
    head = NULL;
    //引入变量统计结点个数
    *sum = 0;
    //叫用户输入相关结点数据
    printf("请输入你要去观光的地点和顺序数字:\n");
    scanf("%s %d",&p_new->name,&p_new->number);
    //进入循环，不断添加结点
    while (p_new->number != 0)
    {
        *sum = *sum + 1;
        if (*sum == 1)
        {
            /* 第一个结点即是头结点又是尾结点 */
            p_new->p_next = NULL;
            head = p_new;
            p_end = p_new;
        }
        else
        {
            //将尾结点的指针指向新结点
            p_end->p_next = p_new;
            //新结点指向NULL
            p_new->p_next = NULL;
            p_end = p_new;
        }
        p_new = (struct Seeing_location*)malloc(sizeof(Node));
        printf("再输入下一个(exit 0退出):\n");
        scanf("%s %d",&p_new->name,&p_new->number);
    }
    //释放空间
    free(p_new);
    return head;
    
}
void Print(struct Seeing_location * p_head,int sum)
{
    Node * temp;
    int ilndex = 1;
    printf("----the list has %d members:----\n",sum);
    temp = p_head;
    for (int i = 0; i < sum; i++)
    {
        printf("the NO%d member is:\n地点是: %s\n第%d个参观\n",ilndex,temp->name,temp->number);
        temp = temp->p_next;
        ilndex++;
    }
    
}
Node * Insert_first(Node * p_head,int *sum)
{
    Node * p_new;
    p_new = (Node *)malloc(sizeof(Node));
    printf("请输入想要在开头插入结点的相关数据:\n");
    scanf("%s %d",&p_new->name,&p_new->number);
    //将新结点插入到第一个结点位置----->将新结点的指针指向原来第一个结点
    p_new->p_next = p_head;
    p_head = p_new;
    *sum = *sum+1;
    return p_head;
}
void Delte(Node * head,int ilndex,int * sum)
{
    //创建连接二个前后的指针
    Node * ptr_font;
    Node * ptr_behind;
    ptr_font = head;
    ptr_behind = ptr_font;
    printf("-----删除 NO%d 名成员 ----\n",ilndex);
    for (int i = 1; i < ilndex; i++)
    {
        /* 便利到要删除的位置 */
        //后指针要具有滞后性
        ptr_behind = ptr_font;
        ptr_font = ptr_font->p_next;
    }
    //连接前后二个结点
    ptr_font = ptr_font->p_next;
    free(ptr_font);
    *sum = *sum - 1;
}
void GetElem(Node *L,int i,int *e)
{
    //让指针p指向第一个结点内存地址
    Node * p = L->p_next;
    //定义一个计数器j
    int j = 1;
    while (j<i-1)
    {
        /* 让指针遍历到i */
        p = p->p_next;
        j++;
    }
    *e = p->number;
    
}
void Insert(Node *L,int i,int number)
{
    Node *p,*s;
    //指针p指向头指针---->*L
    p = L;
    //定义计数器
    int j = 1;
    while (j<i)
    {
        /* 指针后移 */
        p = p->p_next;
        j++;
    }
    //核心插入算法,先创建一块空间给新结点s
    s = (Node *)malloc(sizeof(Node));
    s->number = number;
    s->p_next = p->p_next;
    p->p_next = s;
    
}
int main() {
    Node * p_head;
    int sum;
    p_head = Creat_node(&sum);
    free(p_head);
    return 0;
}