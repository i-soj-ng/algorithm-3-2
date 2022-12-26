#include <iostream>

#define MAXSIZE 4
using namespace std;

void init();
void sudoku(int n);
int check(int n, int x, int y);
int grid[MAXSIZE][MAXSIZE];
bool flag = false;

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        init();
        for (int j = 0; j < MAXSIZE; j++)
            for (int k = 0; k < MAXSIZE; k++)
                scanf("%d", &grid[j][k]);

        sudoku(0);
    }
}

void init()
{
    flag = false;
    
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++)
            grid[i][j] = 0;
}

void sudoku(int n)
{
    if (n == MAXSIZE * MAXSIZE)
    {
        if (flag == false)
        {
            for (int i = 0; i < MAXSIZE; i++)
            {
                for (int j = 0; j < MAXSIZE; j++)
                    printf("%d ", grid[i][j]);

                printf("\n");
            }
            flag = true;
        }
    }

    else
    {
        int x = n / MAXSIZE;
        int y = n % MAXSIZE;

        if (grid[x][y] == 0)
        {
            for (int i = 1; i <= MAXSIZE; i++)
            {
                if (check(i, x, y) == 1)
                {
                    grid[x][y] = i;
                    sudoku(n + 1);
                    grid[x][y] = 0;
                }
            } 
        }
        else
            sudoku(n + 1);
    }
}

int check(int n, int x, int y)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (n == grid[x][i])
            return 0;
        else if (n == grid[i][y])
            return 0;
    }

    int row = x / 2 * 2;
    int col = y / 2 * 2;

    for (int i = row; i < row + 2; i++)
    {
        for (int j = col; j < col + 2; j++)
            if (n == grid[i][j])
                return 0;
    }

    return 1;
}
