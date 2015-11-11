#include<iostream>
#include<map>
#include<vector>
using namespace std;


typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

typedef vector <int > intVec;

typedef map<int, intVec > mapVec;

void getMinMaxTree(NODE root, int &min, int &max, int horiDist)
{
	if (root == NULL) {
		return;
	}

	if (horiDist < min) {
		min = horiDist;
	}

	if (horiDist > max) {
		max = horiDist;
	}

	getMinMaxTree(root->left, min, max, horiDist-1);
	getMinMaxTree(root->right, min, max, horiDist+1);
}

void printTreeVerticallyUtil(NODE root, map< int, vector<int> > &hm, int hd)
{
	if (root == NULL) {
		return;
	}

	hm[hd].push_back(root->data);

	printTreeVerticallyUtil(root->left, hm, hd-1);
	printTreeVerticallyUtil(root->right, hm, hd+1);
}

void printHashMap(map<int, vector<int> > &hm)
{
	for (map<int, vector<int> >::iterator mapIt = hm.begin(); mapIt != hm.end(); mapIt++) {
		for (unsigned int i=0; i < mapIt->second.size();  i++) {
			cout << mapIt->second[i] << " ";

		}
		cout << endl;
	}
}

void printTreeVertically(NODE root)
{
	map<int, vector<int> > hashMap;

	printTreeVerticallyUtil(root, hashMap, 0);
	printHashMap(hashMap);

}

//New node of a tree
NODE newNode(int data)
{
    NODE node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Driver program to test above functions
int main()
{
    // Create binary tree shown in above figure
    NODE root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is \n";
    printTreeVertically(root);

    return 0;
}
