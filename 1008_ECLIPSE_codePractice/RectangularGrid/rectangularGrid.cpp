#include<iostream>
#include<vector>
using namespace std;

struct pathPair {
	int i;
	int j;
};

#define ROWS 4
#define COLS 4

void printRoute(vector<struct pathPair> &pv)
{
	vector<struct pathPair>::iterator it;
	for(it=pv.begin(); it != pv.end(); it++) {
		cout << it->i << "," << it->j << endl;;
	}
}

bool GetPath(int (*a)[COLS], int row, int col, vector<struct pathPair> &pv)
{
	if (row <0 || col < 0 || !a[row][col]) {
		return false;
	}

	struct pathPair point;
	point.i = row;
	point.j = col;

	if (row == 0 && col == 0) {
		pv.push_back(point);
		return true;
	}

	if ((GetPath(a, row-1, col, pv)) || GetPath(a, row, col-1, pv)) {
		pv.push_back(point);
		return true;
	}
	return false;
}

int main()
{
	int a[][COLS] =
	{	{1, 1, 0, 1},
		{1, 0, 1, 1},
		{1, 1, 1, 1},
		{0, 1, 1, 1},
	};

	vector < struct pathPair > pathVector;
	if (GetPath(a, ROWS-1, COLS-1, pathVector)) {
		printRoute(pathVector);
	}
	else {
		cout << " No route " << endl;
	}
	return 0;
}
