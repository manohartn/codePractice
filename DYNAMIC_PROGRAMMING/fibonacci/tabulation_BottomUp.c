#include<stdio.h>

#define N 160

long long fib[N+1];

int main()
{
	fib[0] = fib[1] = 1;
	for (int i=2 ; i<N; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	printf("fib : %lld", fib[N-1]);
	printf("\n");

	return 0;
}