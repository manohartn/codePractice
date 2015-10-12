#include<iostream>
using namespace std;;


void getMinMax(int *a, int &min, int &max, int si, int ei)
{
	max = a[si];
	min = a[si];
	for (int i=si; i<=ei; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
}

int getMinUnsortedArrayIndexes(int *a, int &si, int &ei, int size)
{
	si = -1;
	ei = -1;
	int min = 0;
	int max = 0;

	for (int i=0; i<=size-2; i++) {
		if (a[i] > a[i+1]) {
			si =  i;
			break;
		}
	}

	for (int i=size-1; i>=1; i--) {
		if (a[i] < a[i-1]) {
			ei = i;
			break;
		}
	}

	if (si != -1 && ei != -1) {
		getMinMax(a, min, max, si, ei);

		cout << " min max " << min << " : " << max << endl;
		cout << " SI " << si << " EI " << ei << endl;

		for (int i=0; i<=si; i++) {
			if (a[i] >= min) {
				si = i;
				break;
			}
		}

		for (int i=ei+1; i<=size-1; i++) {
			if (a[i] <= max) {
				ei = i;
				break;
			}
		}
	}
}


int main()
{
	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	//int arr[] = {1,2,3,4,5,4,10,9};
	//int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int si = 0, ei = 0;
	getMinUnsortedArrayIndexes(arr, si, ei, arr_size);

	if (si == -1 && ei == -1) {
	cout << " The complete array is sorted" << endl;
	}

	else {
	cout << "The to be sorted indexes are " << si << " : " << ei <<endl;
	}
	return 0;
}
