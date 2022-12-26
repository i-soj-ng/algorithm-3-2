#include <iostream>

#define MAXSIZE 100
#define MAX(a, b) ((a > b ? a : b))

using namespace std;

int mcss(int a[], int left, int right);

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
        
        printf("%d\n", mcss(a, 0, n-1));
    }
    return 0;
}

int mcss(int a[], int left, int right)
{
    if (left == right)
        return a[left];

    int mid = (left + right) / 2;
    int leftMidSum = -2147483647;
    int rightMidSum = -2147483647;

    int leftSum = 0;
    for (int i = mid; i >= left; i--) {
        leftSum += a[i];
        leftMidSum = MAX(leftSum, leftMidSum);
    }

    int rightSum = 0;
    for (int i = mid + 1; i <= right; i++) {
        rightSum += a[i];
        rightMidSum = MAX(rightSum, rightMidSum);
    }

    int midSum = leftMidSum + rightMidSum;
    int conquerSum = MAX(mcss(a, left, mid), mcss(a, mid+1, right));

    if (midSum < 0)
        midSum = 0;

    return MAX(midSum, conquerSum);
}