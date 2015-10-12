#include<iostream>
#include<stack>
using namespace std;

typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

bool isLeaf(NODE root)
{
	if (root == NULL) {
		return false;
	}

	if (root->left == NULL && root->right == NULL) {
		return true;
	}

	return false;
}

void sumToLeft(NODE root, int &sum)
{
	if (root == NULL) {
		return;
	}

	if (isLeaf(root->left)) {
		sum += root->left->data;

	}

	sumToLeft(root->left, sum);
	sumToLeft(root->right, sum);
}
//New node of a tree
NODE newNode(int data)
{
    NODE node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main()
{
	 NODE root       		   = newNode(20);
	 root->left                = newNode(9);
	 root->right               = newNode(49);
	 root->right->left         = newNode(23);
	 root->right->right        = newNode(52);
	 root->right->right->left  = newNode(50);
	 root->left->left          = newNode(5);
	 root->left->right         = newNode(12);
	 root->left->right->right  = newNode(12);

	int sum = 0;
	sumToLeft(root, sum);

	cout << "Sum of all left leaves " << sum << endl;
	return 0;

}
