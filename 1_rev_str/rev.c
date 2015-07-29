#include<stdio.h>
#include<string.h>


char rev_str[10];
char str[] = "h";
void reverse(char *s, int start, int end)
{
	if (start < end) 
	{
		char temp = *(s + start);
		*(s+start) = *(s+end);
		*(s + end) = temp;

		reverse(s, ++start, --end);
	}
}

int main()
{

	int len = strlen(str) - 1;
	reverse(str, 0, len);
	printf("rev string is %s\n", str); 
	return 0;
}
