#include<stdio.h>
#include<stdlib.h>

struct Node {
	int no;
	struct Node* next;
};
typedef struct Node Node;

Node* ortadakiniSil(Node* head) {
	Node* tempHead = head;
	int j = 0;
	while (tempHead != NULL) {
		j++;
		tempHead = tempHead->next;
	}
	if (j == 0)
		return head;
	tempHead = head;

	int index = 0;
	while (index != ( (j - 1) / 2) ) {
		tempHead = tempHead->next;
		index++;
	}
	if (index == 0) {
		head = head->next;
		free(tempHead);
		return head;
	}
	tempHead->next = tempHead->next->next;
	return head;
}
void main() {

	Node* head = NULL;
	for (int i = 1; i <= 6; i++) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->no = i;
		node->next = head;
		head = node;
	}
	head = ortadakiniSil(head);

	while (head != NULL)
	{
		printf("%d\n", head->no);
		head = head->next;
	}
}