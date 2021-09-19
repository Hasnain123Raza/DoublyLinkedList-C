#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode {
	int value;
	DoublyLinkedListNode *previous;
	DoublyLinkedListNode *next;
} DoublyLinkedListNode;

typedef struct {
	unsigned int length;
	DoublyLinkedListNode *head;
	DoublyLinkedListNode *tail;
} DoublyLinkedList;

/* Constructor and Destructor */

DoublyLinkedList *createDoublyLinkedList();
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

/* List Abstract Data Type Functions */

int getValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index);
void setValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index, int value);
int pushValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
int popValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int insertValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index, int value);
int removeValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index);

/* Doubly Linked List Functions */

DoublyLinkedListNode *getNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index);
int addValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value);
int removeValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node);
int addValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value);
int removeValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node);

#endif
