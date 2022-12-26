#include <iostream>

#define MAX 2002
using namespace std;

int L[MAX];
int cnt;
int HeapSort(int n);
void FixHeap(int root, int a, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++)
    {
        int n;
        scanf("%d", &n);

        for (int j = 0; j < MAX; j++)
            L[j] = 0;

        cnt = 0;
        for (int j = 1; j <= n; j++)
            scanf("%d", &L[j]);

        printf("%d\n", HeapSort(n));
    }
}

int HeapSort(int n)
{
    for (int i = n / 2; i >= 1; i--)
        FixHeap(i, L[i], n);

    for (int heapsize = n; heapsize >= 2; heapsize--)
    {
        int max = L[heapsize];
        FixHeap(1, L[heapsize], heapsize - 1);
        L[heapsize] = max;
    }
    
    return cnt;
}

void FixHeap(int root, int k, int n)
{
    int vacant = root;
    int largerChild;

    while ((L[vacant * 2] != 0 && vacant * 2 <= n) || (L[vacant * 2 + 1] != 0 && vacant * 2 + 1 <= n))
    {
        if ((L[vacant * 2 + 1] != 0) && (vacant * 2 + 1 <= n))
        {
            cnt += 2;
            if (L[vacant * 2] > L[vacant * 2 + 1])
                largerChild = vacant * 2;
            else
                largerChild = vacant * 2 + 1;
        }
        else
        {
            cnt++;
            largerChild = vacant * 2;
        }

        if (k < L[largerChild])
        {
            L[vacant] = L[largerChild];
            vacant = largerChild;
        }
        else
            break;
    }

    L[vacant] = k;
}