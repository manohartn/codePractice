#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define INT_MAX pow(2, 32)  - 3
#define NEWLINE printf("\n")


int main()
{

	int coins[] =  {1, 9, 5, 2, 15,	10};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 100;

    unsigned int table[V+1];
    table[0] = 0U;

    for (int i=1; i<V+1; i++) {
    	table[i] = INT_MAX;
    }

    for (int i=1; i<V+1; i++) {
    	unsigned int coinsReq = INT_MAX;
    	for (int j=0; j<m; j++) {
    		if (i-coins[j] >= 0) {
    			coinsReq = table[i-coins[j]];

    			if (1+coinsReq < table[i]) {
    				table[i] = 1 + coinsReq;
    			}
    		}
    	}
    }

    //for (int i=0; i<=V; i++) {
    //	printf("min coins table[%d]: %u", i, table[i]);
    printf("min coins : %u", table[V]);
    	NEWLINE;
    //}
    //NEWLINE;
	return 0;
}
