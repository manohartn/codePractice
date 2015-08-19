#include<stdio.h>
#include<string.h>

#define max(a,b) a>b?a:b

int lps(const char *str, int start, int end) 
{
	if (start == end) {
		return 1;
	}

	if ((start+1) == end) { 
		if (str[start] == str[end]) {
			return 2;
		}
		else {
			return 1;
		}
	}

	if (str[start] == str[end]) {
		return 2+ lps(str, start+1, end-1);
	}

	return max (lps(str, start, end-1), lps(str, start+1, end));
}

int main()
{
	char str[] = "GEEKS FOR GEEKS";

	int strlength = strlen(str);

	printf("LPS length : %d", lps(str, 0, strlength-1));
	printf("\n");

	return 0;
}