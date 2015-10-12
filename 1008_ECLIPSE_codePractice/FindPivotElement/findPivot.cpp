#include<iostream>
using namespace std;

int findPivotindex(int *a, int low, int high)
{
	if (low > high || low == high ) {
		return -1;
	}

	int mid = (low + high)/2;

	if (a[mid-1] <= a[mid] && a[mid] <= a[mid+1]) {
		if (a[low] <= a[mid]) {
			return findPivotindex(a, mid+1, high);
		}
		else {
			return findPivotindex(a, low, mid-1);
		}
	}

	else {
		if (a[mid-1] <= a[mid]) {
			return mid+1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

int main()
{
	//int a[] = { 6, 8, 1, 2, 4, 5 };
	//int a[] = {100, 20, 30, 60, 80, 83, 88, 88, 89, 90};

	// Already sorted array
	//int a[] = {1, 2, 3, 4, 5, 6};

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};

	int size = sizeof(a)/sizeof(a[0]);

	int low = 0;
	int high = size - 1;

	int pos = findPivotindex(a, low, high);

	if (pos == -1) {
		cout << "array already in sorted order" << endl;
	}

	else {
		cout << "pivot@ pos: " <<  pos << endl;
	}
	return 0;
}
