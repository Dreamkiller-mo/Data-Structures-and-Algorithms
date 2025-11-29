#include <iostream>

using namespace std;

void InsertSort(int list[],int len)
{
    for (int i = 1; i <=len-1; i++)
    {
        int end = i+1;
        int temp = list[end];
        while (end != 1)
        {
            if (temp < list[end-1])
            {
                list[end] = list[end-1];
                end--;
            }
            else
            {
                break;
            }
        }
        list[end] = temp;
        
    }
    
}
void TextInsertSort()
{
    int list[] = {0,3,8,9,1,0,2,4,6,11,18};
    int len = sizeof(list)/sizeof(int)-1;
    InsertSort(list,len);
    for(int i = 1;i<=len;i++)
    {
        cout << list[i] << " ";
    }
}
int main()
{
    TextInsertSort();
    return 0;
}