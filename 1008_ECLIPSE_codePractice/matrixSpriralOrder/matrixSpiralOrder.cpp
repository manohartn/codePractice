#include<iostream>
#include<vector>
using namespace std;

#define ROWS 3
#define COLS 3


int matrixSpiralOrder(vector<vector<int> > M)
{
	int rowTop = 0;
	int colLeft = 0;
	int rowBottom = ROWS-1;
	int colRight = COLS-1;

	while (rowTop <= rowBottom && colLeft <= colRight) {
		for (int j=colLeft; j<=colRight; j++) {
			cout << M[rowTop][j] << " ";
		}


		for () {
			cout << M[i][j] << " ";
		}
	}

	return 0;
}

void printMatrix(vector<vector<int> > M)
{
	int cols = M[0].size();
	int rows = M.size();

	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			//cout << " asdf ";
			cout << M[i][j];
		}
		cout << endl;
	}

}

void fillMatrix(vector<vector<int> > &M)
{
	int cols = M[0].size();
	int rows = M.size();

	int k=1;
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			M[i][j] = k++;
		}
	}
}


int main()
{
	vector<vector<int> > M(ROWS, vector<int>(COLS));
	fillMatrix(M);
	printMatrix(M);
	return 0;

}
