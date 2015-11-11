//============================================================================
// Name        : MaxPathSumBT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define INT_MIN -9999
typedef struct node Node;

int max(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

struct node {
	Node* left;
	Node* right;
	int data;
};

int maxPathSum(Node* root, int &res)
{
	if (root == NULL) {
		return 0;
	}

	int l = maxPathSum(root->left, res);
	int r = maxPathSum(root->right, res);

 	int maxSingle = max(max(l,r) + root->data, root->data);
	int maxTop = max(maxSingle, l+r+root->data);

	res = max(res, maxTop);

	return maxSingle;
}

struct node* newNode(int data)
{
	struct node* node1 = new struct node;
	node1->data = data;
	node1->left = NULL;
	node1->right = NULL;

	return node1;
}

int main() {

    struct node* root = newNode(10);
    int res = INT_MIN;
//    root->left = newNode(20);
//    root->right = newNode(30);

    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    maxPathSum(root, res);
    cout << "Max path sum is " << res;
    return 0;


	return 0;
}
