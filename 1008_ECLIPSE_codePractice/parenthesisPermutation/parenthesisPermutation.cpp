#include<iostream>
using namespace std;

int totalCount = 0;
void printArray(char *data, int pos)
{
	for (int i=0; i<pos; i++) {
		cout << data[i];
	}
	totalCount++;
	cout << endl;
}

void parenthesisPermute(char *data, int pos, int obc, int cbc, int n)
{
	if (cbc > obc) {
		return;
	}

	if (obc == n && cbc == n) {
		printArray(data, pos);
	}

	if (obc < n) {
		data[pos] = '(';
		parenthesisPermute(data, pos+1, obc+1, cbc, n);
	}

	if (cbc < n) {
		data[pos] = ')';
		parenthesisPermute(data, pos+1, obc, cbc+1, n);
	}
}

int main()
{
	char data[100];
	int n = 3;

	parenthesisPermute(data, 0, 0, 0, n);
	cout << "Total Parenthesis pair : " << totalCount << endl;
	return 0;

}
