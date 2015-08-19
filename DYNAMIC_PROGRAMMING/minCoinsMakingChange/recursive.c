#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define INT_MAX pow(2, 32)  - 3
#define NEWLINE printf("\n")

unsigned int minCoins(int coins[], int m, int n) 
{
	if (n <= 0) {
		return 0;
	}

	unsigned int result = (unsigned int)INT_MAX;
	unsigned int coinsReq = (unsigned int)INT_MAX;

	int i=0;
	for (i=0 ; i<m; i++) {
		if (coins[i] <= n) {
			coinsReq = (unsigned int) minCoins(coins, m, n - coins[i]);
        }

		if ((1+coinsReq) < result) {
			result = 1+ coinsReq;
		}
	}

	return result;
}

int main()
{
    int coins[] =  {1, 9, 6, 5, 2, 15, 10};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 100;

    unsigned int result = minCoins(coins, m, V);
    if (result == (unsigned int)INT_MAX) {
    	printf("Change is not possible!\n");
    	exit(-1);
    }
 
    printf("Minimum coins required is: %u ", result);
    NEWLINE;

    return 0;
 }


