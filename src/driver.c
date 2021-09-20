#include <stdio.h>

#include "DoublyLinkedList.h"

void printDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
	int length = doublyLinkedList->length;
	printf("Length: %d\n", length);
	if (length > 0)
	{
		printf("Head: %d\n", doublyLinkedList->head->value);
		printf("Tail: %d\n", doublyLinkedList->tail->value);
	}

	int counter = 0;
	DoublyLinkedListNode *node = doublyLinkedList->head;
	while (counter < length)
	{
		printf("%d: %d\n", counter, node->value);
		node = node->next;
		counter++;
	}

	printf("\n");
}

int main(void)
{
	printf("Creating new DoublyLinkedList\n");
	DoublyLinkedList *doublyLinkedList = createDoublyLinkedList();
	printDoublyLinkedList(doublyLinkedList);

	printf("Pushing 10 integers to the DoublyLinkedList\n");
	for (int counter = 0; counter < 10; counter++)
		pushValueDoublyLinkedList(doublyLinkedList, counter);
	printDoublyLinkedList(doublyLinkedList);

	printf("Popping 5 integers from the DoublyLinkedList\n");
	for(int counter = 0; counter < 5; counter++)
		popValueDoublyLinkedList(doublyLinkedList);
	printDoublyLinkedList(doublyLinkedList);

	printf("Inserting the value 99 at index 2\n");
	insertValueDoublyLinkedList(doublyLinkedList, 2, 99);
	printDoublyLinkedList(doublyLinkedList);

	printf("Removing the value at index 2\n");
	removeValueDoublyLinkedList(doublyLinkedList, 2);
	printDoublyLinkedList(doublyLinkedList);

	printf("Inserting the value 99 at index 5\n");
	insertValueDoublyLinkedList(doublyLinkedList, 5, 99);
	printDoublyLinkedList(doublyLinkedList);

	printf("Removing the value at index 5\n");
	removeValueDoublyLinkedList(doublyLinkedList, 5);
	printDoublyLinkedList(doublyLinkedList);

	printf("Inserting the value 99 at index 0\n");
	insertValueDoublyLinkedList(doublyLinkedList, 0, 99);
	printDoublyLinkedList(doublyLinkedList);

	printf("Removing the value at index 0\n");
	removeValueDoublyLinkedList(doublyLinkedList, 0);
	printDoublyLinkedList(doublyLinkedList);

	printf("Adding 99 after the last node\n");
	DoublyLinkedListNode *node = getNodeDoublyLinkedList(doublyLinkedList, doublyLinkedList->length - 1);
	printf("Got %d\n", node->value); /* REMOVE ME */
	addValueAfterNodeDoublyLinkedList(doublyLinkedList, node, 99);
	printDoublyLinkedList(doublyLinkedList);

	printf("Removing the value after second last node\n");
	removeValueAfterNodeDoublyLinkedList(doublyLinkedList, node);
	printDoublyLinkedList(doublyLinkedList);

	printf("Adding 99 before the last node\n");
	node = getNodeDoublyLinkedList(doublyLinkedList, 0);
	addValueBeforeNodeDoublyLinkedList(doublyLinkedList, node, 99);
	printDoublyLinkedList(doublyLinkedList);

	printf("Removing the value before second node\n");
	removeValueBeforeNodeDoublyLinkedList(doublyLinkedList, node);
	printDoublyLinkedList(doublyLinkedList);

	printf("Destroying the DoublyLinkedList\n");
	destroyDoublyLinkedList(doublyLinkedList);

	return 0;
}
