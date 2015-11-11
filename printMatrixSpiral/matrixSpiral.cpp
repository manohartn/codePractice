#include<iostream>
using namespace std;

#define ROWS 5
#define COLS 5



int main()
{
	//int a[ROWS][COLS] = {{1,2,3},{4,5,6},{7,8,9}};
	//int a[ROWS][COLS] = {{1,2}, {3,4}};
	//int a[ROWS][COLS] = {{1,2,3,10},{4,5,6, 20},{7,8,9, 30}, {10, 11, 12, 40}};
	int a[ROWS][COLS] = {{1,2,3,10, 100},{4,5,6, 20, 200},{7,8,9, 30, 300}, {10, 11, 12, 40, 400}, {13, 14, 15, 50, 500}};

	int rowTop = 0;
	int rowBottom = ROWS - 1;
	int colLeft = 0;
	int colRight = COLS - 1;


	while (rowTop <= rowBottom && colLeft <= colRight) {

		for (int j=colLeft; j<=colRight; j++) {
			cout << a[rowTop][j] << " ";
		}

		rowTop++;

		for (int i=rowTop; i<=rowBottom; i++) {
			cout << a[i][colRight] << " " ;
		}

		colRight--;

		for (int j=colRight; j>=colLeft; j--) {
			cout << a[rowBottom][j] << " ";
		}

		rowBottom--;

		for (int i=rowBottom; i>=rowTop; i--) {
			cout << a[i][colLeft] << " ";
		}

		colLeft++;

	}

	return 0;
}
