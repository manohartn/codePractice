#include<iostream>
#include<cstdio>
#include<cstdlib>

struct node {
	int data;
	struct node* next;
};

typedef struct node* NODE;

NODE getNode(int data)
{
	NODE node = NULL;

	node = (NODE) malloc(sizeof(struct node));

	if (node != NULL) {
		node->data = data;
		node->next = NULL;
	}

	return node;
}

NODE AddLinkedLists(NODE L1, NODE L2)
{
	int sum = 0;
	int carry = 0;

	NODE head = NULL;
	NODE actual_head = NULL;

	while (L1 != NULL && L2 != NULL) {
		sum = L1->data + L2->data + carry;

		carry = sum/10;
		sum = sum % 10;

		NODE newNode = getNode(sum);
		if (head == NULL) {
			// This only executes for the first time, and points to head pointer to the beginning of the resultant list
			head = newNode;
			actual_head = newNode;
		}
		else {
			head->next = newNode;
		}
		head = newNode;
	}

	if (L1 == NULL) {
		while (L2 != NULL) {
			NODE newNode = getNode(L2->data + carry);
			L2 = L2->next;
			head->next = newNode;
			head = newNode;
		}
	}

	else {
		while (L1 != NULL) {
			NODE newNode = getNode(L1->data + carry);
			L1 = L1->next;
			head->next = newNode;
			head = newNode;
		}
	}

	return actual_head;
}
