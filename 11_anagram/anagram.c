#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[] = "nohamar";
char str2[] = "manohar";

int anagram(char *s1, char *s2)
{
	int buf[256];
	int i = 0;

	memset(buf, 0, sizeof(buf));

	if (strlen(s1) != strlen(s2))
 		return 0;

	while (*s1 != '\0' && *s2!= '\0')
	{
		buf[*s1] += 1;
		buf[*s2] -= 1;
		s1++;
		s2++;
	}
	
	for (i=0; i<256; i++)
	{
		if (buf[i] != 0)
			return 0;
	}
	return 1;
}

int main()
{
	if (anagram(str1, str2))
		printf("Two Strings are Anagrams!\n");
	else 
		printf("Not Anagrams!\n");
	return 0;
}
