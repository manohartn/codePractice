#include<stdio.h>
#include<string.h>

#define max(a,b) a>b?a:b

int LPS(char *str, int n)
{
	int L[n][n];

	memset(L, 0, sizeof(L));

	for (int i=n-1; i>=0; i--) {
		for (int j=i; j<n ; j++) {
			if (i==j) {
				L[i][j] = 1;
			}

			else if((j-i) == 1) {
				if (str[i] == str[j]) {
					L[i][j] = 2;
				}

				else {
					L[i][j] = 1;
				}
			}

			else if (str[i] == str[j]) {
				L[i][j] = 2 + L[i+1][j-1];
			}

			else {
				L[i][j] = max(L[i][j-1], L[i+1][j]);
			}
		}

	}

	// print L array

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%d ", L[i][j]);
		}
		printf("\n");
	}

	return L[0][n-1];
}

int main()
{
	char str[] = "GEEKS FOR GEEKS";
	printf("LPS: %d", LPS(str, strlen(str)));
	printf("\n");

	return 0;
}