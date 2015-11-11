#include<iostream>
#include<cstdio>

struct node {
	int data;
	struct node* next;
};

typedef struct node* NODE;


NODE mergeLists(NODE L1, NODE L2)
{
	NODE head = NULL; // pointer to the head of the merged list
	NODE prev = NULL;

	if (L1 == NULL) {
		return L2;
	}

	if (L2 == NULL) {
		return L1;
	}

	if (L1->data < L2->data) {
		head = L1;
	}

	else {
		head = L2;
	}

	while (L1 != NULL && L2 != NULL) {
		while (L1 != NULL && L1->data < L2->data) {
			prev = L1;
			L1 = L1->next;
		}
		prev->next = L2;

		if (L1 == NULL) {
			return head;
		}

		while (L2 != NULL && L2->data <= L1->data) {
			prev = L2;
			L2 = L2->next;
		}
		prev->next = L1;

	}

	return head;
}
