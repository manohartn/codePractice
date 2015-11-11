#include<iostream>
#include<cstdlib>
#include<map>
#include<math.h>
using namespace std;

map<unsigned long, unsigned long> hashMap;

bool isNumberInMagicSequence(unsigned long n)
{
	if (hashMap.find(n) != hashMap.end()) {
		return true;
	}

	return false;
}

bool isMagicNumber(unsigned long n)
{
	unsigned long res = 0;
	if (n == 1) {
		return true;
	}

	while (1) {

		if (isNumberInMagicSequence(n)) {
			//cout << n << endl;
			break;
		}

		hashMap[n] = 0;

		while(n) {
			unsigned long digit = n%10;
			res += pow(digit,2);
			n = n/10;
		}

		if (res == 1) {
			return true;
		}

		;

		n = res;
		res = 0;
	}

	return false;
}


int main()
{
	unsigned long number = 314159;
	string desc;

	if (isMagicNumber(number)) {
		desc = "Happy Number";
	}

	else {
		desc = "Unhappy";
	}

	cout << hashMap.size() << " " << desc << endl;

	return 0;

}
