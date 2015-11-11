#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* NODE;

NODE getNewNode(int data)
{
	NODE newNode = (NODE) malloc(sizeof(struct node));

	// Make sure memory is allocated for newNode else assert
	assert(newNode != NULL);

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;

}
// This function inserts data to the binary search tree and returns the root
NODE insert_to_binarySearchTree(NODE root, int data)
{
	if (root == NULL) {
		root = getNewNode(data);
		return root;
	}

	if (data <= root->data) {
		root->left = insert_to_binarySearchTree(root->left, data);
	}

	else {
		root->right = insert_to_binarySearchTree(root->right, data);
	}

	return root;
}


// print in descending order
// (Right, root, Left) -- This order prints the elements of the tree in descending order
void print_DescendingOrder(NODE root)
{
	// Traverser right subtree first, visit root and then traverse left subtree
	if (root == NULL) {
		return;
	}

	print_DescendingOrder(root->right);
	printf("%d ", root->data);
	print_DescendingOrder(root->left);
}
