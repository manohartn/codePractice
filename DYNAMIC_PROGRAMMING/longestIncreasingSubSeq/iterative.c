#include<stdio.h>

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    //int arr[] = {1, 3, 0, -1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int L[n+1];

    for (int i=0; i<n; i++) {
    	L[i] = 1;
    }

    for (int j=0; j<n; j++) {
    	for (int i=0; i<=(j-1); i++) {
    		if (arr[i] < arr[j] && (L[i] + 1) > L[j]) {
    			L[j] = L[i] + 1;
    		}
    	}
    }

    //find max in L array
    int max = 0;
    for (int i = 0; i < n; i++) {
    	if (L[i] > max) {
    		max = L[i];
    	}
     }

    printf("Length of LIS is %d\n",  max);
	return 0;
}