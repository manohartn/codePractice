#include<iostream>
#include<cstring>
using namespace std;

#define INT_MAX 9999

int min(int a, int b)
{
	if (a < b) {
		return a;
	}
	return b;
}

int minRemovalPal(char *s, int i, int j)
{
	if (i == j) {
		return 0;
	}

	if (i > j) {
		return 0;
	}

	if (s[i] == s[j]) {
		return minRemovalPal(s, i+1, j-1);
	}

	return min(minRemovalPal(s, i, j-1), minRemovalPal(s, i+1, j)) + 1;
}


int main()
{
	char s[] = "asdllsadjffl;saj;ljjdsljjsasdl";
	int startIndex = 0;
	int endIndex = strlen(s) - 1;
	cout << "min chars to be removed to get a palindrome: " << minRemovalPal(s, startIndex, endIndex);

	return 0;
}
