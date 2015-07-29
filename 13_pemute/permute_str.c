#include<stdio.h>
#include<string.h>

char str[] = "abc";

void swap(char *c1, char *c2)
{
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void permute(char *a, int i, int n)
{
	int j;
	if (i == n) {
		printf("%s ", a);
	}
	else {
		for (j=i; j<=n; j++) {	
			swap(&a[i], &a[j]);	
			permute(a, i+1, n);
			swap(&a[i], &a[j]);
		}
	}
}

int main()
{
	permute(str, 0, strlen(str)-1);
	printf("\n");
	return 0;

}
