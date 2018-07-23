#include <iostream>
using namespace std;

void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void insertSort(int a[], int len)
{
    
    for (int i = 1; i < len; i++)
    {
        for (int j = i; j>0&&a[j]<a[j-1]; j--)
        {
            swap(a,j,j-1);
        }
    }
}

main(int argc, char const *argv[])
{
    int a[] = {3,7,5,4,1,2,8,6};
    insertSort(a,8);
    
    for(int i = 0; i < 8; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}
