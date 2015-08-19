#include<stdio.h>
#define NEWLINE printf("\n");

int main()
{
	int i, j;
    int arr[] = {3, 1, 2};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 6;

    int ways[m+1][n+1];

    for (i=0; i<=n; i++) {
    	ways[0][i] = 0;
    }
    for (i=1 ; i<=m; i++) {
    	ways[i][0] = 1;
    }

    for (i=1 ; i<=m; i++) {
    	for (j=1; j<=n; j++) {
    		int x=0, y=0;

    		// Ideally the formula is
    		// j represents columun -- value of n
    		// i represents row -- achieving value j given i number of coins
    		// so consider, if coin i is not considered + if coin i is considered
    		// ways[i][j] = ways[i-1][j] + ways[i][j-arr[i-1]];

    		// The below checks are to make sure they fall appropriately.

    		if (i >=1 ) {
    			x = ways[i-1][j];
    		}

    		if (j-arr[i-1] >=0) {
    			y = ways[i][j-arr[i-1]];
    		}

    		ways[i][j] = x + y;
    	}
    }
    printf("Ways of making change : %d ", ways[m][n]);
    NEWLINE;
}