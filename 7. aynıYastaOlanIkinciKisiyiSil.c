#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int yas;
	struct Node* next;
};
typedef struct Node Node;

Node* aynıYastaOlanIkinciKisiyiSil(Node* head, int yas)
{
	Node* tempHead = head;
	Node* oncekinode = NULL;
	
	if (head == NULL || head->next == NULL)
		return head;

	int isSecond = 0;
	while (tempHead != NULL)
	{
		if (tempHead->yas == yas)
		{
			if (isSecond)
			{
				oncekinode->next = tempHead->next;
				free(tempHead);
				break;
			}
			isSecond = 1;
		}
		oncekinode = tempHead;
		tempHead = tempHead->next;
	}
	return head;
}

void main()
{
	Node* head = NULL;
	for (int i = 1; i <= 5; i++)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->yas = 1;
		node->next = head;
		head = node;
	}
	head = aynıYastaOlanIkinciKisiyiSil(head,1);
	while (head != NULL)
	{
		printf("%d\n", head->yas);
		head = head->next;
	}
}
