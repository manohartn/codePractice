#include<iostream>
#include<cstdio>
using namespace std;

void printArray(int *a, int size)
{
	for (int i=0; i<size; i++) {
		printf("%d ", a[i]);
	}
}

int main()
{
	int i=0;

	int a[] = {78, 517, 959, 28, 132, 282, 242, 881, 363, 749, 390};
	//int a[] = {985, 0, 682, 163, 959, 714, 809, 45, 131, 729, 343, 717, 94, 686, 811, 60, 83, 813, 945, 290, 196, 673, 413, 610, 753};
	//int a[] = {874, 180, 338, 767, 391, 560, 769, 397, 46, 147, 468, 428, 46, 873, 716, 491, 811, 876, 279, 545, 602, 961, 123, 259, 250, 431, 531, 637, 114};
	int size = sizeof(a)/sizeof(a[0]);

	int j, swapCount = 0, temp;
	for (i=0; i<size-1; i++) {
		for(j=0; j<size-1; j++) {
			if (a[j+1] < a[j]) {
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				swapCount++;
			}
		}
	}
	printf("%d\n", swapCount);
	printArray(a, size);
}
