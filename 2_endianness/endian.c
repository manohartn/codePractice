#include<stdio.h>

int main()
{

	int a = 0x01;
	char * p = (char*)&a;
	if (*p == 1) {
		printf("LE\n");
	}
	else printf("BE\n");

	return 0;
}
