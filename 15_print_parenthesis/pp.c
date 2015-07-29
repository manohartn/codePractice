#include<stdio.h>

#define N 3

#define MAX_SIZE 100

char str[MAX_SIZE];

void pp (int pos, int open, int close, int n)
{
	if (close == n) {
		printf("%s \n", str);
		return;
	}
	
	else {

	if (open > close) {
		str[pos] = ')';
		pp(pos+1, open, close+1, n);
	}
	
	if (open < n) {
		str[pos] = '(';
		pp(pos+1, open+1, close, n);
	}

	}

}

int main()
{
	pp(0, 0, 0, N);

	printf("after %s \n ", str);
	return 0;		

}
