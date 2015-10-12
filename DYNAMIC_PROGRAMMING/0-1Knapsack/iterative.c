#include<stdio.h>

#define max(a,b) a>b?a:b


int Knapsack(int W, int N, int *wt, int *val)
{
    int K[N+1][W+1];

    for (int i=0; i<=N; i++) {
    	for (int j=0; j<=W; j++) {
    		if (i == 0 || j == 0) {
    			K[i][j] = 0;
    		} 

    		else if (wt[i-1] <= j) {
    			K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
    		}

    		else {
    			K[i][j] = K[i-1][j];
    		}
    	}
    }

    return K[N][W];
}

int main()
{
	int val[] = {60, 100, 120, 200};
    int wt[] = {10, 20, 30, 5};
    int  W = 50;

    int N = sizeof(wt)/sizeof(int);


    printf("Knapsack : %d\n", Knapsack(W, N, wt, val));
}