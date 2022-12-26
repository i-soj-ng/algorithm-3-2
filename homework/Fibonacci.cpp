#include <stdio.h>

int fib(int n);

int main()
{
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;

        scanf("%d", &num);
        printf("%d\n", fib(num));
    }

    return 0;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    else
        return (fib(n-1) + fib(n-2));
}