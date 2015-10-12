#include<iostream>
using namespace std;

#define LESSER_THAN 1
#define GREATER_THAN 2

#define SIZEOF(A) (int) (sizeof(A)/sizeof(A[0]))

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(int *a, int size)
{
	for (int i=0; i<size; i++) {
		cout << a[i] << " ";
 	}
}

int main()
{
	int a[] = {4, 3, 7, 8, 6, 2, 1};

	int size = SIZEOF(a);
	int flag = LESSER_THAN;

	for (int i=0; i<size-1; i++) {
		if (flag == LESSER_THAN) {
			if (a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
			}
		}

		else {
			if (a[i] < a[i+1]) {
				swap(a[i], a[i+1]);
			}
		}

		flag = !flag;
	}

	print(a, size);
	cout << endl;
}
