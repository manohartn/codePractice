#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	a = a+b;
	b = a-b;
	a = a-b;
}

// in c++ array is taken as reference
void reorderArr(int arr[], int index[], int n)
{
	for (int i=0; i < n; i++) {
		while (index[i] != i) {
			swap(arr[i], arr[index[i]]);
			swap(index[i], index[index[i]]);
		}
	}
}

int main()
{
    //int arr[] = {50, 40, 70, 60, 90};
    //int index[] = {3,  0,  4,  1,  2};

	int arr[] = {2,6,8,10,0,5,16};
	int index[] = {5,3,6,0,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    reorderArr(arr, index, n);

    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    return 0;
}
