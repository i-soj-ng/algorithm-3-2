#include <iostream>

#define MAXSIZE 1000
using namespace std;

void HoareQuickSort(int a[], int low, int high, int *hoareSwapCnt, int *hoareCompCnt);
int HoarePartition(int a[], int low, int high, int *hoareSwapCnt, int *hoareCompCnt);
void LomutoQuickSort(int b[], int low, int high, int *lomutoSwapCnt, int *lomutoCompCnt);
int LomutoPartition(int b[], int low, int high, int *lomutoSwapCnt, int *lomutoCompCnt);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int n;
        scanf("%d", &n);

        int a[MAXSIZE], b[MAXSIZE];
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        for (int j = 0; j < n; j++)
            b[j] = a[j];
        
        int hoareSwapCnt = 0, lomutoSwapCnt = 0;
        int hoareCompCnt = 0, lomutoCompCnt = 0;

        HoareQuickSort(a, 0, n-1, &hoareSwapCnt, &hoareCompCnt);
        LomutoQuickSort(b, 0, n-1, &lomutoSwapCnt, &lomutoCompCnt);

        printf("%d %d %d %d\n", hoareSwapCnt, lomutoSwapCnt, hoareCompCnt, lomutoCompCnt);
    }
    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void HoareQuickSort(int a[], int low, int high, int *hoareSwapCnt, int *hoareCompCnt)
{
    if (low >= high)
        return;
    
    int p = HoarePartition(a, low, high, hoareSwapCnt, hoareCompCnt);
    HoareQuickSort(a, low, p, hoareSwapCnt, hoareCompCnt);
    HoareQuickSort(a, p+1, high, hoareSwapCnt, hoareCompCnt);
}

int HoarePartition(int a[], int low, int high, int *hoareSwapCnt, int *hoareCompCnt)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i = i + 1;
            *hoareCompCnt += 1;
        } while (a[i] < pivot);
        
        do
        {
            j = j - 1;
            *hoareCompCnt += 1;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(a[i], a[j]);
            *hoareSwapCnt += 1;
        }
        else
            return j;
    }
}

void LomutoQuickSort(int b[], int low, int high, int *lomutoSwapCnt, int *lomutoCompCnt)
{
    if (low >= high)
        return;

    int p = LomutoPartition(b, low, high, lomutoSwapCnt, lomutoCompCnt);
    LomutoQuickSort(b, low, p-1, lomutoSwapCnt, lomutoCompCnt);
    LomutoQuickSort(b, p+1, high, lomutoSwapCnt, lomutoCompCnt);
}

int LomutoPartition(int b[], int low, int high, int *lomutoSwapCnt, int *lomutoCompCnt)
{
    int pivot = b[low];
    int j = low;

    for (int i = low + 1; i <= high; i++)
    {
        *lomutoCompCnt += 1;
        if (b[i] < pivot)
        {
            j = j + 1;
            swap(b[i], b[j]);
            *lomutoSwapCnt += 1;
        }
    }
    int pivotPos = j;
    swap(b[pivotPos], b[low]);
    *lomutoSwapCnt += 1;

    return pivotPos;
}