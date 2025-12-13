#include <iostream>
#include <string>
using namespace std;

const int N = 1e3;

typedef long long LL;

int la ,lc;
void sub(int c[],int a[],int b)
{
    //让t来保存每一次的余数
    LL t = 0;
    //模拟除法 
    for(int i = la -1 ; i >= 0 ; i--)
    {
        t = t * 10 + a[i];
        c[i] = t / b;
        t = t % b;
    }

    //删除前导零
    while (c[lc] == 0 && c[lc -1]==0)
    {
        lc--;
    }
}
int main()
{
    //读入数据
    int a[N]={0},b,c[N]={0};
    string s;
    cin >> s >>b;
    la = s.size();
    lc = la;
    for (int i = 0; i < la; i++)
    {
        //逆序存储在a数组里面
        a[i] = s[la -1 -i] - '0';
    }
    //高精度除法 c = a / b
    sub(c , a , b);

    //逆序输出
    for(int i = lc - 1 ; i >= 0 ; i--)
    {
        cout << c[i];
    }
    cout << endl;
    return 0;
}