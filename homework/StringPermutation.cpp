#include <iostream>
#include <stdio.h>
#include <cmath>

#define MAX_SIZE 1000
using namespace std;

int result = 0;
void permuteString(char *str, int begin, int end);
void computeValue(char* str, int k);

int main()
{
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        result = 0;
        char str[MAX_SIZE];
        scanf("%s", str);

        int length = 0;
        for(int i = 0; str[i] != '\0'; i++)
            length++;

        permuteString(str, 0, length);
        printf("%d\n", result);
    }

    return 0;
}

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void computeValue(char *str, int k)
{
    float value = 0;
    for (int i = 0; i < k; i++)
    {
        value = value + (pow(-1, i) * (int(str[i]) - int('a')));
    }

    if (value > 0)
        result += 1; 
}

void permuteString(char *str, int begin, int end)
{
    int range = end - begin;

    if (range == 1)
    {
        computeValue(str, end);
    }
    else
    {
        for (int i = 0; i < range; i++)
        {
            swap(&str[begin], &str[begin+i]);
            permuteString(str, begin+1, end);
            swap(&str[begin], &str[begin+i]);
        }
    }
}