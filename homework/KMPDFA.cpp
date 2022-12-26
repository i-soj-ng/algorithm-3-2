#include <iostream>
#include <string>
using namespace std;

#define MAX 1001

int DFA[MAX][MAX];
int wordToInt(char c);
void constructDFA(string pattern); 
void KMP(string text, int patLength);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        string pattern;
        string text;
        cin >> pattern >> text;

        int patLength = pattern.length();

        for (int j = 0; j < 3; j++)
            for (int k = 0; k < patLength + 1; k++)
                DFA[i][j] = 0;

        constructDFA(pattern);
        KMP(text, patLength);
    }
    return 0;
}

int wordToInt(char c)
{
    if (c == 'A') return 0;
    if (c == 'B') return 1;
    if (c == 'C') return 2;

    return -1;
}

void constructDFA(string pattern)
{
    int patLength = pattern.length();

    int x = 0;
    for (int i = 0; i < patLength + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            DFA[j][i] = DFA[j][x];

        x = DFA[wordToInt(pattern[i])][x];

        if (patLength - 1 >= i)
            DFA[wordToInt(pattern[i])][i] = i + 1;
    }
}

void KMP(string text, int patLength)
{
    int state = 0;
    int cnt = 0;
    int node = 0;
    int txtLength = text.length();

    for (int i = 0; i < txtLength + 1; i++)
    {
        if (state == patLength)
        {
            cnt++;
            state = DFA[wordToInt(text[i])][state];
        }
        else state = DFA[wordToInt(text[i])][state];
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < patLength + 1; j++)
            if (DFA[i][j] != 0)
                node++;

    printf("%d %d\n", node, cnt);
}