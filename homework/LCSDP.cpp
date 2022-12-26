#include <iostream>

#define MAXSIZE 101
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int cache[MAXSIZE][MAXSIZE];
int sec_cache[MAXSIZE][MAXSIZE];

int LCS(char A[], char B[], int m, int n);
void printLCS(char A[], char B[], int m, int n);

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

        printf("%d ", LCS(A, B, a.length(), b.length()));
        printLCS(A, B, a.length(), b.length());
        printf("\n");
    }

    return 0;
}

int LCS(char A[], char B[], int m, int n)
{
    for(int i = 0; i <= m; i++)
        cache[i][0] = 0;

    for(int i = 0; i <= n; i++)
        cache[0][i] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++){
            if (A[i-1] == B[j-1])
            {
                cache[i][j] = cache[i-1][j-1] + 1; // 문자가 같으면 대각선 +1
                sec_cache[i][j] = 0;
            }
            else
            {
                cache[i][j] = MAX(cache[i][j-1], cache[i-1][j]);  //다르면 왼쪽 오른쪽 중 큰거
                if (cache[i][j] == cache[i][j-1])
                    sec_cache[i][j] = 1;
                else
                    sec_cache[i][j] = 2;
            }
        }
    }

    return cache[m][n];
}

void printLCS(char A[], char B[], int m, int n)
{
    if (m == 0 || n == 0)
        return;

    if (sec_cache[m][n] == 0)
    {
        printLCS(A, B, m-1, n-1);
        printf("%c", A[m-1]);
    }
    else if(sec_cache[m][n] == 1)
        printLCS(A, B, m, n-1);
    else if(sec_cache[m][n] == 2)
        printLCS(A, B, m-1, n);
}