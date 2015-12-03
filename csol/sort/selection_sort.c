#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int a[], int n)
{
    int i, j, m;
    for(i=0; i<n-1; i++)
    {
        m = i;
        for(j=i+1; j<n; j++)
            if(a[m] > a[j])
                m = j;
        swap(&a[m], &a[i]);
    }
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
    int a[] = {5, 9, 10, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);
    sort(a, n);
    print(a, n);
}
