//http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	a = a+b;
	b = a - b;
	a = a - b;
}

void sort012(int *a, int size)
{
	int low = 0;
	int mid = 0;
	int high = size-1;

	while (mid <= high) {
		switch(a[mid]) {
			case 0: swap(a[low++], a[mid++]);
				break;

			case 1: mid++;
				break;

			case 2: swap(a[mid], a[high--]);
				break;
		}
	}
}

void printArray(int *a, int size)
{
	for (int i=0; i<size; i++) {
		cout << a[i];
	}

	cout << endl;
}

int main()
{
	int a[] = {0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2,1,2,0,1,0,2,0,1,0,0,1,2};

	int size = sizeof(a)/sizeof(a[0]);

	sort012(a, size);
	printArray(a, size);

	return 0;
}
