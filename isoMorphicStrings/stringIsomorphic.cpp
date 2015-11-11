#include<iostream>
#include<cstring>
#include<map>
using namespace std;


// C++ program to check if two strings are isomorphic
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// This function returns true if str1 and str2 are ismorphic
bool areIsomorphic(string str1, string str2)
{

    int m = str1.length(), n = str2.length();

    // Length of both strings must be same for one to one
    // correspondence
    if (m != n)
      return false;

    // To mark visited characters in str2
    bool marked[MAX_CHARS] = {false};

    // To store mapping of every character from str1 to
    // that of str2. Initialize all entries of map as -1.
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));

    // Process all characters one by on
    for (int i = 0; i < n; i++)
    {
        // If current character of str1 is seen first
        // time in it.
        if (map[str1[i]] == -1)
        {
            // If current character of str2 is already
            // seen, one to one mapping not possible
            if (marked[str2[i]] == true)
                return false;

            // Mark current character of str2 as visited
            marked[str2[i]] = true;

            // Store mapping of current characters
            map[str1[i]] = str2[i];
        }

        // If this is not first appearance of current
        // character in str1, then check if previous
        // appearance mapped to same character of str2
        else if (map[str1[i]] != str2[i])
            return false;
    }

    return true;
}

// Driver program
int main()
{
   cout << areIsomorphic("aab", "xxy") << endl;
   cout << areIsomorphic("aab", "xyz") << endl;
   cout << areIsomorphic("ax", "xa") << endl;
   return 0;
}

//bool stringsIsomorphic(char *s1, char *s2)
//{
//	int length_1 = strlen(s1);
//	int length_2 = strlen(s2);
//
//	if (length_1 != length_2) {
//		return false;
//	}
//
//	map<int, int> strMap;
//	map<int, int>::iterator it;
//
//	for (int i=0; i<length_1; i++) {
//		int d1 = s1[i] - 'a';
//		int d2 = s2[i] - 'a';
//
//		it = strMap.find(d1);
//		if (it != strMap.end()) {
//			int mappedValue = it->second;
//
//			if (mappedValue != d2) {
//				return false;
//			}
//		}
//
//		else {
//
//		}
//	}
//}
//
//int main()
//{
//
//}
