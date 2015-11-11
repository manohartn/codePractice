#include<iostream>
using namespace std;

#define R 3
#define C 3

int M[R][C] =
{
	{1, 1, 0},
	{0, 1, 1},
	{1,	1, 1},
};

bool Visited[R][C];
struct point
{
	int x;
	int y;
};

struct point pointArray[100];

struct point getPoint(int r, int c)
{
	struct point newpoint;
	newpoint.x = r;
	newpoint.y = c;

	return newpoint;
}

void printPath(struct point* pointArray, int len)
{
	for (int i=0; i<len; i++) {
		cout << pointArray[i].x << " " << pointArray[i].y << endl;
	}
}

bool findPath(int r, int c, struct point *pointArr, int pathIndex)
{
	if (r < 0 || c < 0 || r >= R || c >= C) {
		return false;
	}

	if (!M[r][c] || Visited[r][c]) {
		return false;
	}

	if (!Visited[r][c]) {
		Visited[r][c] = true;
		pointArr[pathIndex] = getPoint(r, c);
	}

	if (r == R-1 && c == C-1) {
		printPath(pointArr, pathIndex+1);
		return true;
	}

	if (findPath(r, c+1, pointArr, pathIndex+1) ||	findPath(r+1, c, pointArr, pathIndex+1)) {
		//printPath(pointArr, pathIndex+1);
		return true;
	}

	return false;
}

void initializeVisited()
{
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			Visited[i][j] = false;
 		}
	}
}

int main()
{
	bool pathExists = findPath(0, 0, pointArray, 0);
	if (pathExists) {
		cout << "path Exists!" << endl;
	}
	else {
		cout << "No path to destination " << endl;
	}
	return 0;
}

