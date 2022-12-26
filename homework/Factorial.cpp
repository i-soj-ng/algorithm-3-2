#include <stdio.h>
#include <iostream>

using namespace std;

int factorial(int n);
int deleteZero(int n);

int main()
{
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        scanf("%d", &num);

        printf("%d\n", factorial(num) % 1000);
    }

    return 0;
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        return deleteZero(n * factorial(n-1));
    }   
}

int deleteZero(int n)
{
    while ((n % 10) == 0)
        n /= 10;
    
    return n % 10000;
}