#include<iostream>
using namespace std;

typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

void printArray(int *a, int k)
{
	for(int i=0; i<=k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void RootToLeafUtil(NODE root, int *a, int k)
{
	if (root == NULL) {
		return;
	}

	a[k] = root->data;

	if (root->left == NULL && root->right == NULL) {
		printArray(a, k);
		return;
	}

	RootToLeafUtil(root->left, a, k+1);
	RootToLeafUtil(root->right, a, k+1);
}

//New node of a tree
NODE newNode(int data)
{
    NODE node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void RootToLeaf(NODE root) {
	int a[100];

	RootToLeafUtil(root, a, 0);
}

// Driver method.
int main()
{
    NODE root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);

    RootToLeaf(root);
    return 0;
}

