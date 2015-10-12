#include<iostream>
using namespace std;

void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void permute(string str, int strlen, int pos)
{
	if (pos == strlen -1) {
		cout << str << endl;
	}

	else {
		for (int i=pos; i<strlen; i++) {
			swap(str[i], str[pos]);
			permute(str, strlen, pos+1);
			swap(str[i], str[pos]);
		}
	}
}

int main()
{
	string str = "abcd";
	permute(str, str.size(), 0);
	return 0;

}
