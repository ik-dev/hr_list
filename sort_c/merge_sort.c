#include<stdio.h>

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
        L[i] = a[l+i];
    for(j=0; j<n2; j++)
        R[j] = a[m+j+1];
    i=j=0;
    k=l;
    while(i < n1 && j < n2)
        if(L[i] < R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    while(i < n1)
        a[k++] = L[i++];
    while(j < n2)
        a[k++] = R[j++];
}

void merge_sort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
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
    int a[] = {19, 10, 11, 12, 7};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);
    merge_sort(a, 0, n - 1);
    print(a, n);
}
