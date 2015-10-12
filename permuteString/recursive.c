#include<iostream>
#include<string>
using namespace std;

void perumteString(string pre, string str)
{
	if (str.length() == 0) {
		cout << pre << endl;
	}

	for (int i=0; i<str.length(); i++) {
		perumteString(pre + str[i], str.substr(0, i) + str.substr(i+1));
	}
}

int main()
{
	perumteString("", "abcd");
	return 0;

}