// Q1. Finding a intersection node of two single linked lists of variable length
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* GetIntersectionNodeUtil(struct node* L1, struct node* L2, int offset)
{
	int i=0;
	for (i=0; i<offset; i++) {
			L1 = L1->next;
	}

	while (L1 != NULL && L2!= NULL && L1 != L2) {
		L1 = L1->next;
		L2 = L2->next;
	}

	return L1;
}

struct node* GetIntersectionNode(struct node* L1, struct node* L2, int length_L1, int length_L2)
{
	int diff = abs(length_L1 - length_L2); // returns absolute difference between two linked lists
	struct node* intersectingNode = NULL;

	if (L1 == NULL || L2 == NULL) {
		return NULL;
	}

	if (L1 > L2) {
		intersectingNode = GetIntersectionNodeUtil(L1, L2, diff);
	}

	else  {
		intersectingNode = GetIntersectionNodeUtil(L2, L1, diff);
	}

	return intersectingNode;
}
