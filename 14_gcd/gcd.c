#include<stdio.h>

int gcd(a,b)
{
	if (a == b)
		return a;
	return ((a>b)? gcd(a-b, b):gcd(a, b-a));
}

int main()
{
	printf(" gcd(56, 32) is %d\n", gcd(16,32));
	return 0;
}
