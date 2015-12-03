#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y =temp;
}

void bubble(int a[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

void print(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {5, 3, 10, 17, 9, 1};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);
    bubble(a, n);
    print(a, n);
}
