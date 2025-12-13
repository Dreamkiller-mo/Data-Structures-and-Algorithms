#include <iostream>
#include <string>
using namespace std;

const int N = 1e3;

int a[N]={0},b[N]={0},c[N]={0};

int la,lb,lc;
void mul(int c[],int a[],int b[])
{
    //无进位相乘
    for (int i = 0; i < la; i++)
    {
        for(int j = 0 ; j < lb ; j++)
        {
            c[i+j] += a[i] * b[j];
        }
    }
    //处理进位
    for (int i = 0; i <= lc; i++)
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
    //处理前导零
    while (c[lc] == 0 && c[lc-1]==0)
    {
        lc--;
    }
    
}
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    la = s1.size();
    lb = s2.size();
    lc = la + lb;
    for (int i = 0; i < la; i++)
    {
        a[la - 1 - i] = s1[i]-'0';
    }
    for(int i = 0; i < lb ; i++)
    {
        b[lb - 1 -i] = s2[i]-'0';
    }
    //模拟相乘 ---> c = a*b
    mul(c,a,b);
    //打印最终的结果
    for (int i = lc-1; i>=0; i--)
    {
        cout << c[i];
    }
    
    return 0;
}