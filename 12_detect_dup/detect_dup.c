#include<stdio.h>
#include<string.h>

int a[] = {1,2,3,4,10,33,4};
int k = 2;

#define SIZE 100
int main()
{
	int hash[SIZE];
	int a_size = (sizeof(a)/sizeof(int));

	int i=0;

	memset((void*)hash, 0, sizeof(int)*SIZE);
	for(i=0; i<a_size; i++)
	{
		if (hash[a[i]]) {
			printf("Duplicate detected at pos %d\n", i+1);
		}
		else 
			hash[a[i]] = 1;		

		if (i >= k) {
			hash[a[i-k]] = 0;
		}
	}
	return 0;
}
