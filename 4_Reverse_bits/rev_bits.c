#include<stdio.h>

int main()
{
	int num = 0x01;
	int itr = sizeof(num) * 8;
	int mask = 0x00000001;
	int temp = 0;
	int rev = 0;

	while (itr) 
	{
		temp = (num ^ mask) & mask;
		rev = rev | temp;
		mask <<= 1;
		--itr;
	}
	printf("%x\n", rev);

}
