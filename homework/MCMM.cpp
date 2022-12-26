#include <iostream>

#define MAXSIZE 101
#define INF 2100000000
#define MIN(a, b) (a > b ? b : a)
using namespace std;

int cache[MAXSIZE][MAXSIZE];
int MatrixChainMemo(int arr[], int m, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
            for (int k = 0; k < MAXSIZE; k++)
                cache[j][k] = -1;

        int n;
        scanf("%d", &n);

        int arr[n+1];
        for (int j = 0; j < n+1; j++)
            scanf("%d", &arr[j]);

        printf("%d\n", MatrixChainMemo(arr, 1, n));
    }
}

int MatrixChainMemo(int arr[], int m, int n)
{
    int min = INF;

    if (m == n)
        return 0;

    if (cache[m][n] != -1)
        return cache[m][n];

    cache[m][n] = min;

    for (int i = m; i < n; i++)
    {
        int left = cache[m][n];
        int right = (MatrixChainMemo(arr, m, i) + MatrixChainMemo(arr, i+1, n) + arr[m-1] * arr[i] * arr[n]);
        cache[m][n] = MIN(left, right);
    }
        
    return cache[m][n];
}