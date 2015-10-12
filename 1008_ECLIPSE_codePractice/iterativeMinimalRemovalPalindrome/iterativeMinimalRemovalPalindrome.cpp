#include<iostream>
#include<cstring>
using namespace std;

int min(int a, int b)
{
	if (a<b) {
		return a;
	}

	else {
		return b;
	}
}

int minimalRemovalPalindrome(char *s)
{
	int len = strlen(s);

	int dp[len][len];
	int cols = len-1;

	//cout << "size of dp table is: " << sizeof(dp) << endl;
	//cout << "strlen is " << len << endl;
	memset(dp, 0, sizeof(dp));

	int offset = 0;
	for (int rounds=0; rounds< len-1; rounds++) {
		for (int i=0; i<=cols-1-offset; i++) {
			if (s[i] == s[i+1+offset]) {
				dp[i][i+1+offset] = dp[i+1][i+offset];
			}
			else {
				dp[i][i+1+offset] = min(dp[i][i+offset], dp[i+1][i+1+offset]) + 1;
			}
		}
		offset++;
	}

//	for (int i=0; i<len; i++) {
//		for (int j=0; j<len; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

	return dp[0][len-1];
}

int main()
{
	char s[] = "asdllsadjffl;saj;ljjdsljjsasdl";
	cout << "minimal removal : " << minimalRemovalPalindrome(s) << endl;
	return 0;
}
