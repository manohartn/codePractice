#include<stdio.h>

#define N 100

long long lookup[N+1];

long long fib(int n)
{
	if (lookup[n] == -1) {
		if (n<=1) {
			lookup[n] = 1LL;
		}
		else {
			lookup[n] = fib(n-1) + fib(n-2);
		}
	}

	return lookup[n];
}

void initializeLookUp()
{
	for (int i=0; i<=N; i++) {
		lookup[i] = -1LL;
	}
}

int main()
{
	initializeLookUp();
	printf("fib : %lld", fib(N-1));
	printf("\n");

	return 0;
}