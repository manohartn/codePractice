#include<iostream>
#include<algorithm>
using namespace std;

int *slidingWindowMin(int in[], int w, int n) {
    int *min_left = new int[n];
    int *min_right = new int[n];

    min_left[0] = in[0];
    min_right[n-1] = in[n-1];

    for (int i = 1; i < n; i++) {
        min_left[i] = (i % w == 0) ? in[i] : min(min_left[i - 1], in[i]);

        int j = n - i - 1;
        min_right[j] = (j % w == 0) ? in[j] : min(min_right[j + 1], in[j]);
    }

    int *sliding_min = new int[n - w + 1];
    for (int i = 0, j = 0; (i + w-1) < n; i++) {
        sliding_min[j++] = min(min_right[i], min_left[i + w - 1]);
    }

    return sliding_min;
}

void printArray(int *a, int n)
{
	for (int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
	int n = sizeof(a)/sizeof(a[0]);
	int w= 3;

	int sliding_window_size = n-w+1;
	int *sliding_min = slidingWindowMin(a, w, n);
	printArray(sliding_min, sliding_window_size);

	return 0;
}
