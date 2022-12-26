#include <iostream>

#define MAXSIZE 101
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int cache[MAXSIZE][MAXSIZE];
int LCS(char A[], char B[], int m, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        string a;
        cin >> a;
        char A[a.length()];
        a.copy(A, a.length());

        string b;
        cin >> b;
        char B[b.length()];
        b.copy(B, b.length());

        for (int j = 0; j < MAXSIZE; j++)
            for (int k = 0; k < MAXSIZE; k++)
                cache[j][k] = -1;

        printf("%d\n", LCS(A, B, a.length(), b.length()));
    }

    return 0;
}

int LCS(char A[], char B[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (cache[m][n] != -1)
        return cache[m][n];
    
    if (A[m-1] == B[n-1])
        cache[m][n] = LCS(A, B, m-1, n-1) + 1;      
    else
        cache[m][n] = MAX(LCS(A, B, m, n-1), LCS(A, B, m-1, n));
        
    return cache[m][n];
}