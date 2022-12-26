#include <iostream>

#define MAXSIZE 100
#define MIN(a, b) (a < b ? a : b)
using namespace std;

void merge(int a[], int low, int mid, int high, int *count);
void mergeSortIterative(int a[], int n, int *count);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        int n;
        scanf("%d", &n);

        int count = 0;
        int a[MAXSIZE];
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        mergeSortIterative(a, n, &count);
        printf("%d\n", count);
    }
}

void merge(int a[], int low, int mid, int high, int *count)
{
    int i, j, k;
    int tmp[MAXSIZE];

    for (i = low; i <= high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid+1;
    while (i <= mid && j <= high)
    {
        *count += 1;
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

void mergeSortIterative(int a[], int n, int *count)
{
    int size = 1;

    while (size < n)
    {
        for (int i = 0; i < n; i += 2 * size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = MIN(i + 2 * size - 1, n - 1);

            if (mid >= n - 1)
                break;
            merge(a, low, mid, high, count);
        }
        size *= 2;
    }
}