#include <iostream>

#define MAXSIZE 100
using namespace std;

void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);
int cnt = 0;

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int n;
        scanf("%d", &n);

        cnt = 0;
        int a[MAXSIZE];
        
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        mergeSort(a, 0, n-1);
        printf("%d\n", cnt);
    }
    return 0;
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAXSIZE];

    for (i = low; i <= high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        cnt += 1;
        if (tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while (i <= mid)
        a[k++] = tmp[i++];

    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if (low == high)
        return;

    mid = (low + high) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}