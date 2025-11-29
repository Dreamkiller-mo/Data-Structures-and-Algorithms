#include <iostream>

using namespace std;

void ShellSort(int list[],int n)
{
    int gap = n;
    while (gap>1)
    {
        gap = gap/3+1;
        for (int i = 1; i <=n-gap; i++)
        {
            int end = i;
            int temp = list[end+gap];
            while (end >= 0)
            {
                if (temp < list[end])
                {
                    list[end+gap] = list[end];
                    end = end - gap;
                }
                else
                {
                    break;
                }
            }
            list[end+gap] = temp;
            
        }
    }
    
    
}
void TextShelltSort()
{
    int list[] = {0,3,8,9,1,0,2,4,6,11,18,111,2,12,15,154,4,54,45,454,58,55,66,333,2,15,1,515,1};
    int len = sizeof(list)/sizeof(int)-1;
    ShellSort(list,len);
    for(int i = 1;i<=len;i++)
    {
        cout << list[i] << " ";
    }
}
int main()
{
    TextShelltSort();
    return 0;
}