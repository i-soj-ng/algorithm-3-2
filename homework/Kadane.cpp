#include <iostream>

#define MAXSIZE 100
using namespace std;

int kadane(int a[], int n, int *start, int *end);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int n;
        scanf("%d", &n);

        int a[MAXSIZE];
        int start, end;
        
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);
        
        int answer = kadane(a, n, &start, &end);

        if ((a[start] == 0) && (start != -1))
            start++;
            
        printf("%d %d %d\n", answer, start, end);
    }
    return 0;
}

int kadane(int a[], int n, int *start, int *end)
{
    int i, j;
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    for (i = 0, j = 0; j < n; j++)
    {
        thisSum += a[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if (thisSum < 0)
        {
            i = j + 1;
            thisSum = 0;
        }
    }
    return maxSum;
}