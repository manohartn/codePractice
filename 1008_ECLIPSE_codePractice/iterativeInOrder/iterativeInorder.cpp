#include<iostream>
#include<stack>
using namespace std;

typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

void iterativeInOrder(NODE root)
{
	if (root == NULL) {
		return;
	}

	stack<NODE> nodeStack;
	do {
		while (root != NULL) {
			nodeStack.push(root);
			root = root->left;
		}
		NODE node = nodeStack.top();
		nodeStack.pop();

		cout << node->data;
		root = node->right;
	} while(!nodeStack.empty() || root != NULL);
}

//New node of a tree
NODE newNode(int data)
{
    NODE node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void recursiveInOrder(NODE root)
{
	if (root == NULL) {
		return;
	}

	recursiveInOrder(root->left);
	cout << root->data;
	recursiveInOrder(root->right);
}

// Driver method.
int main()
{
    NODE root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);;
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);

    cout << "Iterative inorder is ";
    iterativeInOrder(root);
    cout << endl << "Recursive inorder is ";
    recursiveInOrder(root);
    cout << endl;
    return 0;
}

