// Excellent solution
// http://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/


#include<iostream>
#include<vector>
using namespace std;


vector<int> findZeroes(int arr[], int n, int m)
{
	int wl = 0;
	int wr=0;
	int bestWindow = 0;
	int bestWindow_L = 0;
	int zeroCount = 0;

	vector<int> result_zeroIndices;

	while (wr < n) {

		while (zeroCount <= m && wr < n) {
			if (arr[wr] == 0) {
				zeroCount++;
			}
			wr++;
		}

		if ((wr - wl) > bestWindow) {
			bestWindow = wr - wl;
			bestWindow_L = wl;
		}

		while (zeroCount > m) {
			if (arr[wl] == 0) {
				zeroCount--;
			}
			wl++;
		}
	}

	for (int i=0; i<bestWindow; i++) {
		if (arr[bestWindow_L + i] == 0) {
			result_zeroIndices.push_back(bestWindow_L + i);
		}
	}

	return result_zeroIndices;
}


int main()
{
	int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
	int m = 2;
	int n =  sizeof(arr)/sizeof(arr[0]);
	cout << "Indexes of zeroes to be flipped are ";
	vector<int> result = findZeroes(arr, n, m);

	for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
