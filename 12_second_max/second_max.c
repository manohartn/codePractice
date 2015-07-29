#include<stdio.h>
#include<assert.h>


int a[] = {5,5,1,2, 56, 47, 56, 56, 47, 33};

int main()
{
	int N = sizeof(a)/sizeof(int);
	int i = 0;
	
	int max = a[0];
	for (i=1; i<N; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int second_max_index = -1;
	int min_diff = 65535;
	for(i=0; i<N; i++) {
		if (a[i] != max && max-a[i] < min_diff) {
			min_diff = max-a[i];
			second_max_index = i;
		}
	}
	assert(second_max_index != -1);
	printf("Second max element is %d %d\n", a[second_max_index], max);
	return 0;
}
