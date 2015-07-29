#include<stdio.h>

int a[] = {5,6,7,8,1,2,3,4};

int circular_bin_search(int a[], int low, int high)
{
	int mid = 0;

	if (a[low] <= a[high]) {
		return low;
	}

	mid = (low+high)/2;

	if (a[mid] <= a[mid+1] && a[mid] <= a[mid-1]) {
		return mid;
	}
	
	if (a[mid] <= a[high]) {
		return circular_bin_search(a, low, mid-1);
	}
	else 
		return circular_bin_search(a, mid+1, high);
}

int main()
{

	int length = sizeof(a)/(sizeof(int));
	printf("length = %d\n", length);
	int pivot_index = circular_bin_search(a, 0, length - 1);
	printf("pivot_index = %d\n", pivot_index);
	printf("The array is circulary rotated (pivot) by %d elements\n", (length - pivot_index)%length);
 	return 0;
}
	
