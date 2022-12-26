#include <iostream>

#define MAXSIZE 10
#define INF 2100000000
#define MIN(a, b) (a > b ? b : a)
using namespace std;

int MatrixChainOrder(int arr[], int m, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        int n;
        scanf("%d", &n);

        int arr[n+1];
        for (int j = 0; j < n+1; j++)
            scanf("%d", &arr[j]);

        printf("%d\n", MatrixChainOrder(arr, 1, n));
    }
}

int MatrixChainOrder(int arr[], int m, int n)
{
    int min = INF;

    if (m == n)
        return 0;

    for (int i = m; i < n; i++)
    {
        int count = (MatrixChainOrder(arr, m, i) + MatrixChainOrder(arr, i+1, n) + arr[m-1] * arr[i] * arr[n]);
        min = MIN(count, min);
    }
        
    return min;
}