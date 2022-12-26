#include <iostream>

#define MAXSIZE 11
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int LCS(char x[], char y[], int m, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        char x[MAXSIZE];
        scanf("%s", x);

        char y[MAXSIZE];
        scanf("%s", y);

        int x_len = 0;
        int j = 0;
        while (x[j])
        {
            x_len++;
            j++;
        }

        int y_len = 0;
        int k = 0;
        while (y[k])
        {
            y_len++;
            k++;
        }

        printf("%d\n", LCS(x, y, x_len, y_len));
    }

    return 0;
}

int LCS(char x[], char y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (x[m - 1] == y[n - 1])
        return 1 + LCS(x, y, m-1, n-1);

    int a = LCS(x, y, m-1, n);
    int b = LCS(x, y, m, n-1);

    return MAX(a, b);
}