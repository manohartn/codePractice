#include<stdio.h>

int main()
{

	int a = -5;
	int b = 121;

	a^= b^=a^=b;

	printf("a=%d and b=%d\n", a,b);
	return 0;
}
