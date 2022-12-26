#include <iostream>

#define MAXSIZE 101
#define INF 2100000000
#define MIN(a, b) (a > b ? b : a)
using namespace std;

int cache[MAXSIZE][MAXSIZE];
int MatrixChainDP(int arr[], int n);
void OrderMatrix(int m, int j);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
            for (int k = 0; k < MAXSIZE; k++)
                cache[j][k] = 0;

        int n;
        scanf("%d", &n);

        int arr[n+1];
        for (int j = 0; j < n+1; j++)
            scanf("%d", &arr[j]);

        int result = MatrixChainDP(arr, n);
        OrderMatrix(1, n);
        printf("\n");
        printf("%d\n", result);
    }
}

int MatrixChainDP(int arr[], int n)
{
    int M[n+1][n+1];
    int cost = 0;
    int min = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            M[i][j] = INF;

    for (int i = 1; i <= n; i++)
        M[i][i] = 0;

    for (int d = 1; d <= n-1; d++)
    {
        for (int i = 1; i <= n-d; i++)
        {
            int j = i + d;
            for (int k = i; k <= j-1; k++)
            {
                cost = M[i][k] + M[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (cost < M[i][j])
                {
                    M[i][j] = cost;
                    min = k;
                }
            }
            cache[i][j] = min;
        }
    }
    return M[1][n];
}

void OrderMatrix(int m, int n)
{
    if(m == n)
    {
        printf("M");
        printf("%d", m);
    }
    else
    {
        int k = cache[m][n];
        printf("(");
        OrderMatrix(m, k);
        OrderMatrix(k + 1, n);
        printf(")");
    }
}