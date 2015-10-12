#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef struct node* NODE;

struct node {
	int data;
	NODE left;
	NODE right;
	NODE nextRight;
};


void connectRecur(NODE root)
{
	if (root == NULL) {
		return;
	}

	if (root->left) {
		root->left->nextRight = root->right;
	}

	if (root->right) {
		root->right->nextRight = (root->nextRight != NULL) ? root->nextRight->left : NULL;
	}

	connectRecur(root->left);
	connectRecur(root->right);
}

void connect(NODE root)
{
	if (root == NULL) {
		return;
	}

	root->nextRight = NULL;
	connectRecur(root);
}

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;

  return(node);
}

int main()
{

  /* Constructed binary tree is
            10
          /   \
        8      2
      /
    3
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(4);
  root->right->left = newnode(20);
  root->right->right = newnode(30);
  root->left->left->left = newnode(5);
  root->left->left->right = newnode(6);

  // Populates nextRight pointer in all nodes
  connect(root);

  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->right->data,
        root->left->nextRight->left? root->left->nextRight->left->data: -1);
  printf("nextRight of %d is %d \n", root->right->left->data,
        root->left->nextRight->left? root->right->left->nextRight->data: -1);

  return 0;
}
