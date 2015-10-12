// Array rotation
// http://www.geeksforgeeks.org/array-rotation/


// JUGGLING METHOD
// Space = O(1)
// Time complexity = O(n)

#include<iostream>
using namespace std;

int getGCD(int a, int b)
{
	if (a > b) {
		return getGCD(a-b, b);
	}

	else if (b>a) {
		return getGCD(a, b-a);
	}

	return a;
}

void rotateArray(int *a, int d, int n)
{
	int gcd = getGCD(d, n);

	for (int i=0; i<d; i++) {
		int temp = a[0];
		int j=0;

		while ((j+gcd) < n) {
			a[j] = a[j+gcd];
			j += gcd;
		}
		a[j] = temp;
	}
}

void printArray(int *a, int size)
{
	for (int i=0; i<size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int size = sizeof(a)/sizeof(a[0]);
	int rotateDistance = 1;

	rotateArray(a, rotateDistance, size);

	printArray(a, size);
	return 0;
}
