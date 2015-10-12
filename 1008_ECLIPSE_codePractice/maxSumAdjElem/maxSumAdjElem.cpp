#include<iostream>
using namespace std;

int max(int a, int b)
{
	int res = a>b?a:b;

	return res;
}

int main()
{
	//int a[] = {5,  5, 10, 40, 50, 35};
	int a[] = {3, 2, 7, 10 };
	int size = sizeof(a)/sizeof(a[0]);

	int incl = a[0];
	int excl = 0;

	for (int i=1; i<size; i++) {
		int temp = incl;
		incl = (excl + a[i]);
		excl = max(temp, excl);
	}

	cout << "Max sum -- Such that no two elements are adjacent: " << max(incl, excl) << endl;

	return 0;

}
