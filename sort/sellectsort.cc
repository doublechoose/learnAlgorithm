#include <iostream>

void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void sellectSort(int a[], int len)
{

    for (int i = 0; i < len; i++)
    {
        int min = i;

        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a, i, min);
    }
}

main(int argc, char const *argv[])
{
    int a[] = {3,7,5,4,1,2,8,6};
    sellectSort(a,8);
    
    for(int i = 0; i < 8; i++)
    {
        std::cout<<a[i]<<" ";
    }
    
    return 0;
}
