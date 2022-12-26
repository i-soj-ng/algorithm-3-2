#include <iostream>
#include <stdio.h>

using namespace std;

int pow(int a, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int a;
        int n;
        scanf("%d %d", &a, &n);
        printf("%d\n", int(pow(a, n)) );
    }
    return 0;
}

int pow(int a, int n)
{
    int b;

    if (n == 0)
        return 1;
    else if ((n % 2) == 1)
    {
        b = pow(a, (n-1) / 2);
        return (a * b * b) % 1000;
    }
    else
    {
        b = pow(a, n / 2);
        return (b * b) % 1000;
    }
}