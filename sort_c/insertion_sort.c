#include<stdio.h>

void insertion(int a[], int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void print(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

void main()
{
    int a[] = {12, 11, 19, 10, 5};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);
    insertion(a, n);
    print(a, n);
}
