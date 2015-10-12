#include<stdio.h>

#define INT_MIN -999999

int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(arr)/sizeof(int);
	
	int CR[n+1];

	CR[0] = 0;

	for (int i=1; i<=n ; i++) {
		int res, min = INT_MIN;
		for (int j=0; j<i; j++) {
			res = arr[j] + CR[i-j-1];

			if (res > min) {
				min = res;
				CR[i] = min;
			}
		}
	}

	printf(" Max value of cutting rod is %d\n",  CR[n]);
}