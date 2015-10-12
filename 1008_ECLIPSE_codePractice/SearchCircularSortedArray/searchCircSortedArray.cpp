#include<iostream>
using namespace std;

int searchCircSortedArr(int *a, int key, int low, int high)
{
	if (low > high ) {
		return -1;
	}

	int mid = (low + high)/2;

	if (key == a[mid]) {
		return mid;
	}

	else if (a[low] <= a[mid]) {
		if (a[low] <= key && key <= a[mid]) {
			return searchCircSortedArr(a, key, low, mid-1);
		}
		else {
			return searchCircSortedArr(a, key, mid+1, high);
		}
	}

	else {
		if (a[mid] <= key && key <= a[high]) {
			return searchCircSortedArr(a, key, mid+1, high);
		}
		else {
			return searchCircSortedArr(a, key, low, mid-1);
		}
	}

}

int main()
{
	int a[] = { 6, 8, 1, 2, 4, 5 };

	int size = sizeof(a)/sizeof(a[0]);

	int low = 0;
	int high = size - 1;
	cout << size << endl;

	int key = 4;

	int pos = searchCircSortedArr(a, key, low, high);

	if (pos == -1) {
		cout << "key not found" << endl;
	}

	else {
		cout << "key " << key << " at pos:" << pos << endl;
	}
	return 0;
}
