#include<stdio.h>
#include<string.h>

#define true 1
#define false 0

# define max(a,b) a>b?a:b

int lengthOfLongestSubstring(char s[]) 
{
  int n = strlen(s);
  int i = 0, j = 0;
  int maxLen = 0;
  int exist[256] = { false };
  while (j < n) {
    if (exist[s[j]]) {
      maxLen = max(maxLen, j-i);
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  maxLen = max(maxLen, n-i);
  return maxLen;
}

int main()
{
	char *s = "geeksforgemnquvwxyzks";
	printf("longest substr lengthg : %d\n", lengthOfLongestSubstring(s));

}
