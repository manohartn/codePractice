#include<iostream>
using namespace std;


typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

//New node of a tree
NODE newNode(int data)
{
    NODE node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


bool isFullBT(NODE root)
{
	if (root == NULL) {
		return true;
	}

	if ((root->left && !(root->right)) || (root->right && !(root->left))) {
		return false;
	}

	return isFullBT(root->left) && isFullBT(root->right);

}

int main()
{
    NODE root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);

    root->left->right = newNode(40);
    root->left->left = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    root->left->left->left = newNode(80);
    root->left->left->right = newNode(90);
    root->left->right->left = newNode(80);
    root->left->right->right = newNode(90);
    root->right->left->left = newNode(80);
    root->right->left->right = newNode(90);
    root->right->right->left = newNode(80);
    root->right->right->right = newNode(90);

    if (isFullBT(root))
        cout << "The Binary Tree is full";
    else
        cout << "The Binary Tree is not full";

    return(0);
}
