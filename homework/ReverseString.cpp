#include <iostream>
#include <stdio.h>

#define MAX_SIZE 100

using namespace std;

void reverseArray(char a[], int i, int j);
void swap(char a[], int i, int j);

int main()
{
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        char strArray[MAX_SIZE];
        scanf("%s", strArray);

        int length = 0;
        for(int i = 0; strArray[i] != '\0'; i++)
            length++;

        reverseArray(strArray, 0, length - 1);

        printf("%s\n", strArray);
    }

    return 0;
}

void swap(char a[], int i, int j)
{
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void reverseArray(char a[], int i, int j)
{
    if (i < j)
    {
        swap(a, i, j);
        reverseArray(a, i+1, j-1);
    }
}