#include<iostream>
#include<vector>
#include<algorithm>


/* Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 150’th ugly number.

http://www.geeksforgeeks.org/ugly-numbers/

*/



using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
        vector<int> uglyNumberList(n);

        vector<int> index(3, 0);
        int factorArr[] = {2, 3, 5};
        vector<int> factor(factorArr, factorArr + sizeof(factorArr)/sizeof(factorArr[0]));

        uglyNumberList[0] = 1;

        cout << "size " << uglyNumberList.size();
        for (int i=1; i<uglyNumberList.size(); i++) {
        	vector<int>::iterator minIt = min_element(factor.begin(), factor.end());
        	int min = *minIt;
        	//cout << factor[0] << " " << factor[1] << " " << factor[2] << endl;
        	uglyNumberList[i] = min;

        	cout << min << " ";

        	if (min == factor[0]) {
        		factor[0] = 2 * uglyNumberList[++index[0]];
        	}
        	if (min == factor[1]) {
        		factor[1] = 3 * uglyNumberList[++index[1]];
        	}
        	if (min == factor[2]) {
        		factor[2] = 5 * uglyNumberList[++index[2]];
        	}

        }
        return uglyNumberList[n-1];
    }
};

int main()
{
	Solution UglyNumberInstance;
	cout <<  endl << UglyNumberInstance.nthUglyNumber(16) << endl;
	return 0;
}
