#include<iostream>
#include<string>
using namespace std;

#define true 1
#define false 0


string dict[] = {"i", "love", "google", "uber", "AmazonA9", "my", "name", "is", "Manohar", "Go-Ar", "Amazon"};


int dictContains(string word) {
	int dictSize = sizeof(dict)/sizeof(dict[0]);

	for (int i=0; i<dictSize; i++) {
		if (0 == dict[i].compare(word)) {
			return true;
		} 
	}

	return false;
}

int wordBreak(string str, string &wordBreakString)
{
	if (str.size() == 0) {
		return true;
	}

	string result = "";
	for (int i=1; i<=str.size(); i++) {
		if (dictContains(str.substr(0, i)) && 
			wordBreak(str.substr(i, str.size()-i), wordBreakString)) {
			result.append(str.substr(0, i));
			wordBreakString.append(result);
			wordBreakString.append(":");
			result.append(str.substr(i, str.size() - i));
			cout << "string is " << wordBreakString << endl;
			return true;
		}
	}


	return false;
}

int main()
{
	string wordBreakString = "";
	int flag = wordBreak("ilovegoogleAmazonuber", wordBreakString);
	

	cout << "Word break segmentation : " << flag << endl;
	return 0;
}

