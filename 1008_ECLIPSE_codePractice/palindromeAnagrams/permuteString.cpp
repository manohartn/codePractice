#include<iostream>
#include<cstring>
using namespace std;

char allP[1000][1000];
int st = 0;

void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

bool checkExsistingPalindrome(const char *s)
{
	for (int i=0; i<st-1; i++) {
		//cout << allP[i] << endl;
	}
	//cout << endl;

	for (int i=0; i<st; i++) {
			//cout << "comp " << str[i] << " " << str[j] << endl;
			if (strcmp(allP[i], s) == 0) {
				//cout << "comp " << str[i] << " " << str[j] << endl;
				return true;
			}
		}

	return false;
}

bool isPalindrome(string str)
{
	const char *s = (const char*) str.c_str();


	int len = strlen(s);
	//cout << len << endl;

	//int k = st-1;
	//cout << allP[k] << endl;
	if (!checkExsistingPalindrome(s)) {
		strncpy(allP[st++], s, len);

	}

	else {
		// already a palindrome
		return false;
	}

	//cout << allP[st] << endl;

	int i=0, j=len-1;

	while (i < j) {
		if (s[i++] != s[j--]) {
			return false;
		}
	}

	return true;
}

void permute(string str, int strlen, int pos, int &palCount)
{
	if (pos == strlen -1) {
		if (isPalindrome(str)) {
			//cout << str << endl;
			palCount++;
		}
		//cout << str << endl;
	}

	else {
		for (int i=pos; i<strlen; i++) {
			swap(str[i], str[pos]);
			permute(str, strlen, pos+1, palCount);
			swap(str[i], str[pos]);
		}
	}
}

int min(int a, int b)
{
	if (a<b) {
		return a;
	}
	return b;
}

int minRemoval(char *s, int st, int en)
{
	if (st < en) {
		return 0;
	}
	static int cost = 0;
	if (s[st] == s[en]) {
		cost = 0;
		return minRemoval(s, st+1, en-1);
	}

	return min(minRemoval(s, st+1, en), minRemoval(s, st, en-1)) + 1;

	return -1;
}

int main()
{
	string str = "adka";
//	char anagrams[1000][1000];
	int palcount = 0;
	permute(str, str.size(), 0, palcount);
	cout << palcount << endl;
	cout << minRemoval((char *)str.c_str(), 0, strlen(str.c_str())-1);
	return 0;

}
