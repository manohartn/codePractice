#include<iostream>
using namespace std;

class MinHeap
{
	int *arr;
	int heap_size;

public:
	MinHeap(int *array, int size);
	void minHeapify(int i);
	int parent_index(int index){ return (index-1)/2;   }
	int left_index(int index)  { return (2*index) + 1; }
	int right_index(int index) { return (2*index) + 2; }
	void printArray();
};


MinHeap::MinHeap(int *array, int size)
{
	arr = array;
	heap_size = size;

	int i = heap_size/2;

	while (i>=0) {
		minHeapify(i);
		i--;
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MinHeap::minHeapify(int index)
{
	int left_ind = left_index(index);
	int right_ind = right_index(index);

	int smallest = index;

	if (left_ind < heap_size && arr[left_ind] < arr[index]) {
		smallest = left_ind;
	}

	if (right_ind < heap_size && arr[right_ind] < arr[smallest]) {
		smallest = right_ind;
	}

	if (smallest != index) {
		swap(&arr[index], &arr[smallest]);
		minHeapify(smallest);
	}
}

void MinHeap::printArray()
{
	for (int i=0; i < heap_size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
    int arr[] = {12, 3, 5, 7, 19};

    int n = sizeof(arr)/sizeof(arr[0]);
    MinHeap minHeapInstance(arr, n);
    cout << "hello" << endl;
    minHeapInstance.printArray();
    //cout << "K'th smallest element is " << kthSmallest(arr, n, k);

	return 0;
}

