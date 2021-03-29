#include <stdio.h>
#include <stack>

using namespace std;
#define SIZE 8


void spans2(int X[], int S[], int n) {
	stack<int> A;
	for (int i = 0; i < n; i++) {
		while (!A.empty() && (X[A.top()] <= X[i]))
			A.pop();
		if (A.empty())
			S[i] = i + 1;
		else
			S[i] = i - A.top();
		A.push(i);
	}
	while (!A.empty())
	{
		A.pop();
	}
}

int main(int argc, char* argv[]) {
	int n = 8;
	int X[SIZE] = { 60,30,40,10,20,30,50,40 };
	int S[SIZE] = { 0 };
	spans2(X, S, n);

	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", S[i]);
	}


	return 0;
}