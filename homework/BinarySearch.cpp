#include <iostream>

#define MAXSIZE 1000
using namespace std;

int binarySearch(int a[], int left, int right, int value);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        int a[MAXSIZE];
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        printf("%d\n", binarySearch(a, 0, n, k));
    }
    return 0;
}

int binarySearch(int a[], int left, int right, int value)
{
    int mid;

    if (left > right)
        return -1;
    else
    {
        mid = (left + right) / 2;

        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid-1, value);
        else
            return binarySearch(a, mid+1, right, value);
    }
}