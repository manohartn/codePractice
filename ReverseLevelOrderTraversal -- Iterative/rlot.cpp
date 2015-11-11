#include<iostream>
using namespace std;

#define max(a,b) a>b?a:b

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* NODE = new struct node();
	NODE->data = data;

	return NODE;

}

int getHeight(struct node* root)
{
	if (root == NULL) {
		return 0;
	}

	int lheight = getHeight(root->left);
	int rheight = getHeight(root->right);

	int maxHeight = max(lheight, rheight);
	return maxHeight + 1;
	//return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void printRLot(struct node* root, int level)
{
	if (root == NULL) {
		return;
	}

	if (level == 1) {
		cout << root->data;
	}

	else {
		printRLot(root->left, level-1);
		printRLot(root->right, level-1);
	}
}

void reverseLevelOrder(struct node* root)
{
	int height = getHeight(root);
	cout << "Tree height" << height << endl;

	for (int i=height; i>=1; i--) {
		printRLot(root, i);
	}
}

/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is " << endl;
	reverseLevelOrder(root);

	return 0;
}
