#include<iostream>
#include<cstdlib>
#include<map>

using namespace std;

#define INT_MAX 99999999

void printArray(int *A, int len)
{
	for (int i=0; i<len; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int minimum(int a, int b)
{
	int min = a < b ?a:b;
	return min;
}

int determine_min_frog_jump_time(int *arr, int N, int X, int D)
{
	//int *pos = (int*) malloc(N*sizeof(int));
	map<int, int> pos;
	int *dp = (int *) malloc((X+1)*sizeof(int));

	pos[0] = 0;
	pos[X] = 0;

	for (int i=0; i<N; i++) {
		if (pos.find(arr[i]) == pos.end()) {
			pos[arr[i]] = i;
		}
	}

	for (int i=0; i<=X; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;

	for (int i=1; i<=X; i++) {
		if (pos.find(i) != pos.end()) {
			if (i <= D) {
				dp[i] = pos[i];
			}
			else {
				for (int step=1; step<=D; step++) {
					if (pos[i] > dp[i-step]) {
						dp[i] = minimum(dp[i], pos[i]);
					}
					else {
						dp[i] = minimum(dp[i], dp[i-step]);
					}
				}
			}
		}
	}
	//printArray(pos, N);
	//printArray(dp, X+1);


	if (dp[X] == INT_MAX)
		return -1;

	return dp[X];
}

int main()
{
	int A[] = {1,3,1,4,2,5};
	//int A[] = {5, 4, 1, 2};
	//int A[] = {8, 6, 4, 2, 10};

	int N = sizeof(A)/sizeof(int);
	//cout << "size " << N << endl;
	int D = 3;
	int X = 7;

	cout << determine_min_frog_jump_time(A, N, X, D);

	return 0;

}

