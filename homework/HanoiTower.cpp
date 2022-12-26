#include <iostream>
#include <stdio.h>

#define MAX_SIZE 1000
using namespace std;

void Hanoi(int n, int a, int b, int c);

struct stack {
	int arr[MAX_SIZE];
	int last;

	void init() {
		last = -1;
	}
	void push(int data) {
		arr[++last] = data;
	}
	bool empty() {
		return (last < 0);
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		return arr[last--];
	}
	int top() {
		if (empty()) {
			return 0;
		}
		return arr[last];
	}
};

stack st;

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int numDisks;
        scanf("%d", &numDisks);
        
        st.init();
        Hanoi(numDisks, 1, 2, 3);
        printf("\n");
    }
    return 0;
}

void Hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        Hanoi(n-1, a, c, b);
        if (c == 3)
        {
            st.push(n);
            printf("%d ", st.top());
        }
        else if (a == 3)
        {
            st.pop();
            printf("%d ", st.top());
        }
        Hanoi(n-1, b, a, c);
    }
}