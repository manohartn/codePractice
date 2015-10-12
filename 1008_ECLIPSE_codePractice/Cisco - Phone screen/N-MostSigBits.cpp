#include<stdio.h>
#include<stdlib.h>

// This method is using a library function pow(2,n)

unsigned int GetNMostSigBits(unsigned int number, unsigned int n)
{
	unsigned int result = 0;
	unsigned int mask = 1;

	if (n == 32) {
		// to handle the corner case if n == 32
		return number;
	}

	mask = pow(2, n); // Here, in order to avoid the usage of standard lib, we can replace, mask = mask << n
	mask = mask - 1;

	mask = mask << (32-n);

	result = number & mask;

	return result;
}

// Without using any library function

unsigned int GetNMostSigBits(unsigned int number, unsigned int n)
{
	unsigned int result = 0;
	unsigned int mask = 1;

	if (n == 32) {
		// to handle the corner case if n == 32
		return number;
	}

	mask = mask << n;
	mask = mask - 1;

	mask = mask << (32-n);

	result = number & mask;

	return result;
}
