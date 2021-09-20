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

	if (doublyLinkedList->length == 1)
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
	if (index > doublyLinkedList->length)
		terminate("Attempt to insert value at an index out of bounds\n");

	DoublyLinkedListNode *newNode = malloc(sizeof(DoublyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;
	newNode->previous = NULL;
	newNode->next = NULL;

	if (doublyLinkedList->length == 0)
	{
		doublyLinkedList->head = newNode;
		doublyLinkedList->tail = newNode;
	}
	else
	{
		if (index == 0)
		{
			newNode->next = doublyLinkedList->head;
			doublyLinkedList->head->previous = newNode;
			doublyLinkedList->head = newNode;
		}
		else if (index == doublyLinkedList->length)
		{
			doublyLinkedList->tail->next = newNode;
			newNode->previous = doublyLinkedList->tail;
			doublyLinkedList->tail = newNode;
		}
		else
		{
			DoublyLinkedListNode *targetNode;
			int midpoint = (doublyLinkedList->length + 1)/2;
			if (index < midpoint)
			{
				targetNode = doublyLinkedList->head;
				for (unsigned int counter = 0; counter < index - 1; counter++)
					targetNode = targetNode->next;
			}
			else
			{
				targetNode = doublyLinkedList->tail;
				for (unsigned int counter = doublyLinkedList->length; counter > index + 1; counter--)
					targetNode = targetNode->previous;
			}

			newNode->next = targetNode->next;
			targetNode->next->previous = newNode;
			targetNode->next = newNode;
			newNode->previous = targetNode;
		}
	}

	doublyLinkedList->length++;
	return 1;
}

int removeValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index)
{
	if (doublyLinkedList->length == 0)
		terminate("Attempt to remove value from an empty list\n");

	if (index >= doublyLinkedList->length)
		terminate("Attempt to remove value at an index out of bounds\n");

	DoublyLinkedListNode *targetNode;

	if (doublyLinkedList->length == 1)
	{
		targetNode = doublyLinkedList->head;
		doublyLinkedList->head = NULL;
		doublyLinkedList->tail = NULL;
	}
	else
	{
		if (index == 0)
		{
			targetNode = doublyLinkedList->head;
			doublyLinkedList->head = targetNode->next;
			doublyLinkedList->head->previous = NULL;
		}
		else if (index == doublyLinkedList->length - 1)
		{
			targetNode = doublyLinkedList->tail;
			doublyLinkedList->tail = targetNode->previous;
			doublyLinkedList->tail->next = NULL;
		}
		else
		{
			int midpoint = (doublyLinkedList->length + 1)/2;
			if (index < midpoint)
			{
				targetNode = doublyLinkedList->head;
				for (unsigned int counter = 0; counter < index; counter++)
					targetNode = targetNode->next;
			}
			else
			{
				targetNode = doublyLinkedList->tail;
				for (unsigned int counter = doublyLinkedList->length; counter > index; counter--)
					targetNode = targetNode->previous;
			}

			targetNode->previous->next = targetNode->next;
			targetNode->next->previous = targetNode->previous;
		}
	}

	int targetValue = targetNode->value;
	free(targetNode);
	doublyLinkedList->length--;
	return targetValue;
}

/* Doubly Linked List Functions */


DoublyLinkedListNode *getNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index)
{
	if (index >= doublyLinkedList->length)
		terminate("Attempt to get node at an index out of bounds\n");

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
		for (int counter = doublyLinkedList->length - 1; counter > index; counter--)
			currentNode = currentNode->previous;
	}

	return currentNode;
}

int addValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value)
{
	DoublyLinkedListNode *newNode = malloc(sizeof(DoublyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;
	newNode->previous = NULL;
	newNode->next = NULL;

	if (node == doublyLinkedList->tail)
		doublyLinkedList->tail = newNode;
	newNode->next = node->next;
	newNode->previous = node;
	node->next = newNode;

	doublyLinkedList->length++;
	return 1;
}

int removeValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node)
{
	if (node->next == NULL)
		terminate("Attempt to remove a NULL node\n");

	DoublyLinkedListNode *targetNode = node->next;
	node->next = targetNode->next;
	if (targetNode == doublyLinkedList->tail)
		doublyLinkedList->tail = node;
	else
		node->next->previous = node;

	int targetValue = targetNode->value;
	free(targetNode);
	doublyLinkedList->length--;
	return targetValue;
}

int addValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value)
{
	DoublyLinkedListNode *newNode = malloc(sizeof(DoublyLinkedListNode));
	if (!newNode)
		return 0;
	newNode->value = value;
	newNode->previous = NULL;
	newNode->next = NULL;

	if (node == doublyLinkedList->head)
		doublyLinkedList->head = newNode;
	newNode->previous = node->previous;
	newNode->next = node;
	node->previous = newNode;

	doublyLinkedList->length++;
	return 1;
}

int removeValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node)
{
	if (node->previous == NULL)
		terminate("Attempt to remove a NULL node\n");

	DoublyLinkedListNode *targetNode = node->previous;
	node->previous = targetNode->previous;
	if (targetNode == doublyLinkedList->head)
		doublyLinkedList->head = node;
	else
		node->previous->next = node;

	int targetValue = targetNode->value;
	free(targetNode);
	doublyLinkedList->length--;
	return targetValue;
}
