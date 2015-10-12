#include<iostream>
using namespace std;

#define ROW 4
#define COL 3

int main()
{
	int a[ROW][COL] = {{1,2,3},{4,5,6},{7,8,9}, {10, 11, 12}};

	int D = ROW+COL-2;

	for (int d = 0; d<=D; d++) {
		for (int i=0; i<=d; i++) {
			if (i < ROW && d-i < COL) {
				cout << a[i][d-i] << " " ;
			}
		}
		cout << endl;
	}
	return 0;
}
