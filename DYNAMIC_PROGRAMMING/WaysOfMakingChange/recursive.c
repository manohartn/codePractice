#include<stdio.h>

#define NEWLINE printf("\n");

int WaysOfMakingChange(int s[], int m, int n)
{
	if (n < 0) {
		return 0;
	}

	if (n == 0) {
		return 1;
	}

	if (m <=0) {
		return 0;
	}

	return WaysOfMakingChange(s, m, n-s[m-1]) + WaysOfMakingChange(s, m-1, n);
}


int main()
{
	int i, j;
    int arr[] = {3, 1, 2};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("Ways of making change : %d ", WaysOfMakingChange(arr, m, 4));
    NEWLINE;

    return 0;

}