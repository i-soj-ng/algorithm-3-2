#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

void fail(string pattern);
int kmp(string text, string pattern);
int pi[MAX];

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        string pattern;
        string text;
        cin >> pattern >> text;

        int m = pattern.length();
        fail(pattern);
        for (int j = 0; j < m; j++)
            printf("%d ", pi[j]);

        printf("\n%d\n", kmp(text, pattern));
    }
    return 0;
}

void fail(string pattern)
{
    int m = pattern.length();

    for (int i = 0; i < m; i++)
        pi[i] = 0;

    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
}

int kmp(string text, string pattern)
{
    int m = pattern.length();
    int n = text.length();

    int p = 0;
    int pos[MAX];
    int cnt = 0;
    
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j])
        {
            if (j == m - 1)
            {
                pos[p++] = i - m + 1;
                cnt++;
                j = pi[j];
            }
            else j++;
        }
    }
    return cnt;
}