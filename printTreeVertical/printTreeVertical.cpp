#include<iostream>
using namespace std;


typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

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

void printTreeVerticallyUtil(NODE root, int level, int hd)
{
	if (root == NULL) {
		return;
	}

	if (level == hd) {
		cout << root->data << " ";
	}

	printTreeVerticallyUtil(root->left, level, hd-1);
	printTreeVerticallyUtil(root->right, level, hd+1);
}

void printTreeVertically(NODE root)
{
	int min = 0;
	int max = 0;

	int horiDist = 0;

	getMinMaxTree(root, min, max, horiDist);

	cout << "min " << min << " max " << max << endl;

	for (int i=min; i<=max; i++) {
		printTreeVerticallyUtil(root, i, 0);
		cout << endl;
	}
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
