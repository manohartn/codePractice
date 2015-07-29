#include<stdio.h>

typedef struct size_struct
{
	int a;
	char c;
}sz_struct;

int main()
{
	printf("size of struct = %d\n", (int)sizeof(sz_struct));
 	return 0;
}
