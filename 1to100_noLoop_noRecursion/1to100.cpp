#include<iostream>
using namespace std;

class print
{
public:
	static int printVar;

	static void increment_printVar()
	{
		printVar++;
	}

	print()
	{
		cout << printVar << endl;
		increment_printVar();
	}


};

int print::printVar = 1;

int main()
{

	print obj[100];
	return 0;
}
