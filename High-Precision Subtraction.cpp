#include <iostream>
#include <string>
#include <algorithm>
const long long N = 10;

using namespace std;
bool Compare(string& s1,string& s2)
{
    //长度相同的情况
    if (s1.size() == s2.size())
    {
        //使用字典序
        return s1 > s2;
    }
    //长度不同的情况
    else
    {
        return s1.size() > s2.size();
    }
}

void Subtraction(int a[],int b[],int c[],int len)
{
    for (int i = 0; i < len; i++)
    {
        int res = a[i] - b[i];
        if (res < 0)
        {
            c[i+1]--;
            res += 10; 
        }
        c[i] = res;
    }
    
}
int main()
{
    int a[N]={0},b[N]={0},c[N]={0};
    string s1,s2;
    cin >> s1;
    cin >> s2;
    int la = s1.size(),lb = s2.size(),lc = max(la,lb);
    //假设s1 > s2;
    for (int i = 0; i < la; i++)
    {
        a[i] = s1[la-i-1]-'0';
    }
    for (int i = 0; i < lb; i++)
    {
        b[i] = s2[lb-i-1]-'0';
    }
    //如果s1 < s2
    if (Compare(s1,s2) == false)
    {
        swap(a,b);
    }
    //实现减法
    Subtraction(a,b,c,lc);
    for (int i = lc-1; i >= 0; i--)
    {
        //不输出前导零
        if (c[lc-1]==0)
        {
            for (int j = lc-2; j > 0; j--)
            {
                if (c[j] == 0)
                {
                    i = j-1;
                }
                else
                    break;
            }
        }
        cout << c[i];
    }
    
    return 0;
}