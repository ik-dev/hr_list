#include <stdio.h>

int bsearch_r(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return bsearch_r(a, l, mid-1, x);
        return bsearch_r(a, mid+1, r, x);
    }
    return -1;
}

int bsearch_i(int a[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 9, 10, 19, 20, 25, 100, 125};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Found at %d\n", bsearch_i(a, 0, n-1, 5));
}
