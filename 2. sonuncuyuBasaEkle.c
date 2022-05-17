#include<stdio.h>
#include<stdlib.h>

struct Node {
	int no;
	struct Node* next;
};
typedef struct Node Node;

Node* sonuncuyuBasaEkle(Node* head) {
	Node* tempHead = head;

	if (tempHead == NULL || tempHead->next == NULL)
		return head;

	while (tempHead->next->next != NULL)
		tempHead = tempHead->next;

	tempHead->next->next = head;
	head = tempHead->next;
	tempHead->next = NULL;

	return head;
}
void main() {

	Node* head = NULL;
	for (int i = 1; i <= 5; i++) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->no = i;
		node->next = head;
		head = node;
	}
	head = sonuncuyuBasaEkle(head);

	while (head != NULL)
	{
		printf("%d\n", head->no);
		head = head->next;
	}
}