#include<iostream>
using namespace std;


#define ROW 3
#define COLS 3
#define K_MAX 50

int total_ways[ROW][COLS][K_MAX];

int countWtihKPaths(int mat[][COLS], int i, int j, int k)
{
	if (i < 0 || j < 0) {
		return 0;
	}

	if (i == 0 && j == 0) {
		if (mat[i][j] == k) {
			return 1;
		}
		else {
			return 0;
		}
	}

	total_ways[i][j][k] = countWtihKPaths(mat,i-1,j,k-mat[i][j]) + countWtihKPaths(mat, i, j-1, k-mat[i][j]);

	return total_ways[i][j][k];
}

int total_ways_with_K_Paths(int mat[][COLS], int k)
{
	int total_paths_with_K = countWtihKPaths(mat, ROW-1, COLS-1, k);
	return total_paths_with_K;
}

int main()
{
	int k = 12;
	int mat[ROW][COLS] = { {1, 2, 3},
	                      {4, 6, 5},
	                      {3, 2, 1}
	                  };
	 cout << total_ways_with_K_Paths(mat, k);
	 return 0;

}
