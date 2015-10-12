//http://www.geeksforgeeks.org/maximum-product-subarray/
#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a>b? a: b;
}

int min(int a, int b)
{
	return a<b?a:b;
}

int maxProductSubArray(int *a, int size)
{
	int max_prod_ending_here = 1;
	int min_prod_ending_here = 1;

	int max_so_far = 1;

	for (int i=0; i<size; i++) {
		if (a[i] > 0) {
			max_prod_ending_here = max_prod_ending_here*a[i];
			min_prod_ending_here = min(min_prod_ending_here*a[i], 1);
		}

		else if (a[i] < 0) {
			int temp = max_prod_ending_here;
			max_prod_ending_here = max(min_prod_ending_here*a[i], 1);
			min_prod_ending_here = temp*a[i];
		}

		else if (a[i] == 0) {
			max_prod_ending_here = 1;
			min_prod_ending_here = 1;
		}

		if (max_prod_ending_here > max_so_far) {
			max_so_far = max_prod_ending_here;
		}
	}

	return max_so_far;
}


int main()
{
	   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
	   //int a[] = {1, -2, -3, 0, 7, -8, -2};
	   int n = sizeof(a)/sizeof(a[0]);
	   int max_sum = maxProductSubArray(a, n);
	   cout << "Maximum subArray prod is: " << max_sum << endl;
	   return 0;
}
