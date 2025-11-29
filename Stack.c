//栈的实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//定义栈的结构体
typedef char ElemType;
typedef struct Stack
{
    //栈的实现最优解是:动态数组
    //定义一个指针成员指向一块数组空间
    ElemType* p;
    //栈顶
    int top;
    int capacity;
}Stack;

//初始化栈
Stack* StackInite1()
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    //创建一块数组空间，初始化一些字节
    ElemType* temp = (ElemType*)malloc(sizeof(ElemType)*4);
    if (temp != NULL)
    {
        st->p = temp;
    }
    else if(temp == NULL)
    {
        printf("malloc fail!!!\n");
        exit(-1);
    }
    st->top = 0;
    st->capacity = 4;
    return st;
}
void StackInite2(Stack* st)
{
    assert(st);
    ElemType* temp = (ElemType*)malloc(sizeof(ElemType)*4);
    if (temp == NULL)
    {
        printf("malloc fail!!\n");
        exit(-1);
    }
    st->top = 0;
    st->capacity = 4;
    
}

//销毁栈
void Detroy(Stack* st)
{
    assert(st);
    free(st->p);
    st->p = NULL;
    st->capacity = st->top = 0;
}

//增加元素的操作
void StackPush(Stack* st,ElemType x)
{
    assert(st);
    //先判断数组内存空间是否满，满了就扩容
    if (st->top == st->capacity)
    {
        /* 满栈扩容 */
        ElemType* temp = (ElemType*)realloc(st->p,sizeof(ElemType)*2);
        if (temp == NULL)
        {
            printf("realloc fail!!!\n");
            exit(-1);
        }
        st->capacity *= 2;
    }
    //再进行压栈操作---->先赋值，后top++
    st->p[st->top] = x;
    st->top++;
}

//删除元素，只能在栈顶删除
void StackPop(Stack* st)
{
    assert(st);
    st->top--;
}

//获取栈顶元素
ElemType StackTop(Stack* st)
{
    assert(st);
    assert(st->top > 0);
    return st->p[st->top-1];
}
//打印函数
void Print(Stack* st)
{
    for (int i = 0; i < st->top; i++)
    {
        printf("%c\t",st->p[i]);
    }
    
}

//判断栈是否为空
int StackEmpty(Stack* st)
{
    if (st == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
       
}
//测试函数
void Text(Stack* st,ElemType list[])
{
    int flag;
    for (int i = 0; i < 4; i++)
    {
        if (list[i]=='('|| list[i]=='[' || list[i]=='{')
        {
            /* 左括号入栈 */
            StackPush(st,list[i]);
        }
        if (list[i]==')')
        {
            ElemType c = st->p[st->top-1];
            /* 右括号出栈顶元素跟右括号判断是否匹配 */
            if(c == '(')
            {
                StackPop(st);
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if(list[i]==']')
        {
            ElemType c = st->p[st->top-1];
            if(c == '[')
            {
                StackPop(st);
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if(list[i]=='}')
        {
            ElemType c = st->p[st->top-1];
            if(c == '{')
            {
                StackPop(st);
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
    }
    if (flag == 1)
    {
        printf("True!!!");
    }
    else
    {
        printf("Error!!!");
    }
    
    
    Detroy(st);
}
void Text2(Stack* st,ElemType list[])
{
    for (int i = 0; i < 4; i++)
    {
        StackPush(st,list[i]);
    }
    Print(st);
    
}
//主函数
int main()
{
    Stack st;
    StackInite2(&st);
    char list[] = {'(','[',']',')'};
    Text(&st,list);
    return 0;
}
