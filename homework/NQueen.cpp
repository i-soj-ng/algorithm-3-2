#include <iostream>

#define MAXSIZE 17
using namespace std;

int N;
int A;
int COL[MAXSIZE];
int check(int i);
void nqueen(int i);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        A = 0;
        scanf("%d", &N);
        nqueen(0);
        printf("\n");
    }
}

int check(int i)
{
    int k = 1;
    int p = 1;

    for (int j = 1; j < i && p; j++)
        if (COL[i] == COL[j] || abs(COL[i] - COL[j]) == abs(i - j))
            p = 0;

    return p;
}

void nqueen(int i)
{
    if (A != 0)
        return;
    
    if (check(i))
    {
        if (i == N)
        {
            for (int i = 1; i <= N; i++)
                printf("%d ", COL[i]);

            A = 1;
            return;
        }

        for (int j = 1; j <= N; j++)
        {
            COL[i + 1] = j;
            nqueen(i + 1);
        }
    }
}