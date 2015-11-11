//http://www.geeksforgeeks.org/remove-nodes-root-leaf-paths-length-k/

#include<iostream>
using namespace std;

typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
};

NODE removeRootToLeafLessKUtil(NODE root, int level, int k)
{
	if (root == NULL) {
		return NULL;
	}

	root->left = removeRootToLeafLessKUtil(root->left, level+1, k);
	root->right = removeRootToLeafLessKUtil(root->right, level+1, k);

	if (root->left == NULL && root->right == NULL && level < k) {
		delete root;
		return NULL;
	}

	return root;
}

NODE removeRootToLeafLessK(NODE root, int k)
{
	return removeRootToLeafLessKUtil(root, 1, k);
}

//New node of a tree
NODE newNode(int data)
{
    NODE node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//Method to print the tree in inorder fashion.
void printInorder(NODE root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

// Driver method.
int main()
{
    int k = 4;
    NODE root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
    cout << "Inorder Traversal of Original tree" << endl;
    printInorder(root);
    cout << endl;
    cout << "Inorder Traversal of Modified tree" << endl;
    NODE res = removeRootToLeafLessK(root, k);
    printInorder(res);
    return 0;
}
