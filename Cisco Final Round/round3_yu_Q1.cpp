#include<iostream>
#include<cstdio>
#include<cstdlib>


struct node {
	int data;
	struct node* left;
	struct node* right;
};


void recursive_Inorder(struct node* root)
{
	if (root == NULL) {
		return;
	}

	recursive_Inorder(root->left);
	printf("%d \n", root->data);
	recursive_Inorder(root->right);
}


// There is assumed to be a Stack supporting push, pop and empty operations
// I can implement Stack in 'C' using a singly linked list
// PUSH --> Insert node always at front, so this preserves the LIFO order
// POP --> Remove node at the front of the linked list -- removes the LIFO order

void iterative_inorder (struct node* root)
{
	if (root == NULL) {
		return ;
	}

	Stack S1;
	S1.push(root);

	while (!S1.empty()) {
		while (root->left != NULL) {
			S1.push(root->left);
			root = root->left;
		}

		struct node* node = S1.pop();
		printf("%d \n", node->data);

		root = node;

		if (root->right) {
			S1.push(root->right);
			root = root->right;
		}
	}
}
