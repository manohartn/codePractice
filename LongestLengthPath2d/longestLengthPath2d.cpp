#include<iostream>
#include<cstring>
using namespace std;

#define R 2
#define C 2

#define NO_OF_POSSIBLE_PATHS 8

int dp[R][C];
bool visited[R][C];

int PathRow[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int PathCol[8] = {1, -1, 1, -1, 0, 0, -1, 1};

bool isValid(int i, int j)
{
	if (i <0 || j<0 || i>=R || j>=C) {
		return false;
	}

	return true;
}

int max(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

bool isAdjacent(char prev, char curr)
{
	//cout << curr - prev << endl;
	return ((curr-prev) == 1);
}

int maxLenUtil(char M[R][C], int i, int j, char prev)
{
	if (!isValid(i, j) || !isAdjacent(prev, M[i][j]) || visited[i][j]) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	visited[i][j] = true;
	int result = 0;
	for (int trial=0; trial < NO_OF_POSSIBLE_PATHS; trial++) {
		result = max(result, 1 + maxLenUtil(M, i + PathRow[trial], j + PathCol[trial], M[i][j]));
	}

	dp[i][j] = result;
	visited[i][j] = false;

	return result;
}

int maxLen(char M[R][C], char c)
{
	int ans = 0;
	int result = 0;

	memset(dp, -1, sizeof(dp));

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if (M[i][j] == c) {
				for (int trial=0; trial < NO_OF_POSSIBLE_PATHS; trial++) {
					result = 1+ maxLenUtil(M, i +  PathRow[trial], j + PathCol[trial], M[i][j]);
					ans = max(ans, result);
				}
			}
		}
	}

	return ans;
}

int main() {

//    char mat[R][C] = { {'a','c','d'},
//                     { 'h','b','a'},
//                     { 'i','g','f'}};

    char mat[R][C] = { 	{'a','c'},
    					{'b', 'd'}
    				 };

    cout << "mL " << maxLen(mat, 'c') << endl;
//    cout << maxLen(mat, 'e') << endl;
//    cout << maxLen(mat, 'b') << endl;
//    cout << maxLen(mat, 'f') << endl;

    return 0;
}

