#include<iostream>
#include<queue>
#include<stack>

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

void reverseLevelOrder(struct node* root)
{
	if (root == NULL) {
		return;
	}

	queue<struct node*> nodeQ;
	stack<struct node*> nodeS;

	nodeQ.push(root);
	while (!nodeQ.empty()) {
		struct node *treeNode = nodeQ.front();
		nodeQ.pop();

		if (treeNode && treeNode->right) {
			nodeQ.push(treeNode->right);
		}
		if (treeNode && treeNode->left) {
			nodeQ.push(treeNode->left);
		}

		nodeS.push(treeNode);
	}

	while (!nodeS.empty()) {
		struct node* popNode = nodeS.top();
		nodeS.pop();

		cout << popNode->data;
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
	cout << endl;

	return 0;
}
