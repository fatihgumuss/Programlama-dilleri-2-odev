#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int no;
	struct Node* next;
};
typedef struct Node Node;

Node* ilkVeSonuDegistir(Node* head)
{
	Node* tempHead = head;

	if (tempHead == NULL || tempHead->next == NULL)
		return head;
	while (tempHead->next->next != NULL)
	{
		tempHead = tempHead->next;
	}
	Node* lastNode = tempHead->next;
	lastNode->next = head->next;
	tempHead->next = head;
	head->next = NULL;
	head = lastNode;
	return head;
}
void main()
{
	Node* head = NULL;
	for (int i = 1; i <= 6; i++)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->no = i;
		node->next = head;
		head = node;
	}
	head = ilkVeSonuDegistir(head);
	while (head != NULL)
	{
		printf("%d\n", head->no);
		head = head->next;
	}
}