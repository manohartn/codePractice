#include<iostream>
#include<string>
#include<cstring>

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

int wordBreak(string str, int *wb)
{
	int size = str.size();

	memset(wb, 0, size);

	for (int i=1; i<=size; i++) {
		if (!wb[i] && dictContains(str.substr(0, i))) {
			cout << "hehe" << endl;
			wb[i] = true;
		}

		if (wb[i]) {

			if (i == size) {
				return true;
			}

			for (int j=i+1; j<=size; j++) {
				if (!wb[j] && dictContains(str.substr(i, j-i))) {
					wb[j] = true;
				}

				if (wb[j] && j == size) {
					return true;																																				
				}
			}
		}
	}

	return false;
}


int main()
{
	string sentence = "AmazonA9uber";	

	int *wb = new int[sentence.size() + 1];

	int wordSegment = wordBreak(sentence, wb);

	for (int i = 1; i <= sentence.size(); i++) {
        cout << "wb[ " << i << "]: " << wb[i] << endl; 
	}

	cout << "Word Segmentation: " << wordSegment << endl;
	return 0;
}
