#include <iostream>

using namespace std;

#define MAXSIZE 100
#define MAX(a, b) ((a > b ? a : b))

int recurMax(int a[], int left, int right);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int n;
        scanf("%d", &n);

        int a[MAXSIZE];
        
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        printf("%d\n", recurMax(a, 0, n-1))
    }
    return 0;
}

int recurMax(int a[], int left, int right)
{
    int half;

    if (left == right)
        return a[left];
    else
    {
        half = (left + right) / 2;
        return MAX(recurMax(a, left, half), recurMax(a, half+1, right));
    }
}