#include <iostream>

#define MAXSIZE 10000
using namespace std;

void balanceScale(int p[], int n);
int dp[] = {100, 50, 20, 10, 5, 2, 1};
int leftSum, rightSum;

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        leftSum = 0;
        rightSum = 0;
        int n;
        scanf("%d", &n);

        int p[MAXSIZE];
        for (int j = 0; j < n; j++)
            scanf("%d", &p[j]);

        balanceScale(p, n);
    }
}

void balanceScale(int p[], int n)
{
    leftSum += p[0];

    for (int i = 1; i < n; i++)
    {
        if (leftSum <= rightSum)
            leftSum += p[i];
        else
            rightSum += p[i];
    }

    int diff = abs(leftSum - rightSum);

    int cnt = 0;
    
    for (int i = 0; i < 7; i++)
    {
        while (diff - dp[i] >= 0)
        {
            cnt++;
            diff -= dp[i];
        }
    }

    printf("%d\n", cnt);
}