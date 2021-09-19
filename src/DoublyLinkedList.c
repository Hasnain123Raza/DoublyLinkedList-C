#include "DoublyLinkedList.h"

/* Utility Functions */

void terminate(const char *message)
{
	printf("%s", message);
	exit(EXIT_FAILURE);
}

/* Constructor and Destructor */

DoublyLinkedList *createDoublyLinkedList()
{
	DoublyLinkedList *doublyLinkedList = malloc(sizeof(DoublyLinkedList));
	if (!doublyLinkedList)
		return NULL;

	doublyLinkedList->length = 0;
	doublyLinkedList->head = NULL;
	doublyLinkedList->tail = NULL;

	return doublyLinkedList;
}

void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
	DoublyLinkedListNode *previousNode = NULL;
	DoublyLinkedListNode *currentNode = doublyLinkedList->head;

	while (currentNode)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
		free(previousNode);
	}

	free(doublyLinkedList);
}

/* List Abstract Data Type Functions */

int getValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index)
{
	if (index >= doublyLinkedList->length)
		terminate("Attempt to get value at an index out of bounds\n");

	DoublyLinkedListNode *currentNode;
	int midpoint = (doublyLinkedList->length + 1)/2;
	if (index < midpoint)
	{
		currentNode = doublyLinkedList->head;
		for (int counter = 0; counter < index; counter++)
			currentNode = currentNode->next;
	}
	else
	{
		currentNode = doublyLinkedList->tail;
		for (int counter = doublyLinkedList->length; counter > index; counter--)
			currentNode = currentNode->previous;
	}

	return currentNode->value;
}

void setValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index, int value)
{
	if (index >= doublyLinkedList->length)
		terminate("Attempt to set value at an index out of bounds\n");

	DoublyLinkedListNode *currentNode;
	int midpoint = (doublyLinkedList->length + 1)/2;
	if (index < midpoint)
	{
		currentNode = doublyLinkedList->head;
		for (unsigned int counter = 0; counter < index; counter++)
			currentNode = currentNode->next;
	}
	else
	{
		currentNode = doublyLinkedList->tail;
		for (unsigned int counter = doublyLinkedList->length; counter > index; counter--)
			currentNode = currentNode->previous;
	}

	currentNode->value = value;

}

int pushValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value)
{
	DoublyLinkedListNode *newNode = malloc(sizeof(DoublyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;
	newNode->previous = NULL;
	newNode->next = NULL;

	if (doublyLinkedList->length == 0)
	{
		doublyLinkedList->head = newNode;
	}
	else
	{
		doublyLinkedList->tail->next = newNode;
	}

	newNode->previous = doublyLinkedList->tail;
	doublyLinkedList->tail = newNode;
	doublyLinkedList->length++;
	return 1;
}


int popValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
	if (doublyLinkedList->length == 0)
		terminate("Attempt to pop an empty list\n");

	DoublyLinkedListNode *tailNode = doublyLinkedList->tail;

	if (singlyLinkedList->length == 1)
	{
		doublyLinkedList->head = NULL;
		doublyLinkedList->tail = NULL;
	}
	else
	{
		DoublyLinkedListNode *nodeBeforeTailNode = tailNode->previous;
		nodeBeforeTailNode->next = NULL;
		doublyLinkedList->tail = nodeBeforeTailNode;
	}

	int tailValue = tailNode->value;
	free(tailNode);
	doublyLinkedList->length--;
	return tailValue;
}

int insertValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index, int value)
{

}

int removeValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index)
{

}

/* Doubly Linked List Functions */


DoublyLinkedListNode *getNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index)
{

}

int addValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value)
{

}

int removeValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node)
{

}

int addValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value)
{

}

int removeValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node)
{

}
