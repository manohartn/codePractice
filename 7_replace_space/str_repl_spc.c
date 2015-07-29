#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100] = "Mr John Smith married angelina and now they are good";

int count_spaces(char* str)
{
	int spaces = 0;
	int i = 0;

	for (i=0 ; i < strlen(str); i++)
	{
		if (*(str+i) == ' ' && *(str+i+1) != ' ')
			spaces++;
	}
	printf("No. of spaces = %d\n", spaces);
	return spaces;
}

int main()
{
	char *string = str;

	int spaces = count_spaces(str);
	str[strlen(str)+spaces] = '\0';
	int p = strlen(str) + spaces - 1;
	int q = strlen(str) - 1;
	int shift = 2*spaces;
	while (spaces)
	{
		if (str[q] == ' ' && str[q-1] != ' ') {
			--spaces;
			shift = 2 * spaces;
			strncpy(string+q+shift, "%20", 3);
		}
		if (spaces == 0) break;			
		while (*(string+q) == ' ') --q;
		*(string+q+shift) = str[q];
		--q;
	}
	printf("After - %s\n", str);
	return 0;
	
}

