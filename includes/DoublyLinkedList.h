#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode {
	int value;
	struct DoublyLinkedListNode *previous;
	struct DoublyLinkedListNode *next;
} DoublyLinkedListNode;

typedef struct {
	unsigned int length;
	DoublyLinkedListNode *head;
	DoublyLinkedListNode *tail;
} DoublyLinkedList;

/* Constructor and Destructor */

/* Attempts to allocate a new DoublyLinkedList. Returns the DoublyLinkedList upon success or NULL upon failure */
DoublyLinkedList *createDoublyLinkedList();
/* Frees a DoublyLinkedList */
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

/* List Abstract Data Type Functions */

/* Returns the value at the specified index. Exits if index is out of bounds */
int getValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index);
/* Sets the value at the specified index to the specified value. Exits if index is out of bounds */
void setValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index, int value);
/* Attempts to allocate a new DoublyLinkedListNode and push it with the specified value. Returns 0
 * upon failure and 1 upon success */
int pushValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
/* Pops a DoublyLinkedListNode and returns its value. Exits if the list is empty */
int popValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
/* Attempts to insert a DoublyLinkedListNode at the specified index with the specified value. Returns
 * 0 upon failure and 1 upon success. Exits if index is out of bounds */
int insertValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index, int value);
/* Attempts to remove a DoublyLinkedListNode at the specified index. Returns the value of the removed
 * node. Exits if the list is empty or the index is out of bounds */
int removeValueDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index);

/* Doubly Linked List Functions */

/* Returns the DoublyLinkedListNode at the specified index. Exits if the index is out of bounds */
DoublyLinkedListNode *getNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, unsigned int index);
/* Attempts to allocate a new DoublyLinkedListNode and puts it in front of the specified node. Returns 0
 * upon failure and 1 upon success */
int addValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value);
/* Removes the node after the specified node and returns its value. Exits if the node to remove is NULL. */
int removeValueAfterNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node);
/* Attempts to allocate a new DoublyLinkedListNode and puts it behind the specified node. Returns 0 upon
 * failure and 1 upon success */
int addValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node, int value);
/* Removes the node before the specified node and returns its value. Exits if the node to remove is NULL. */
int removeValueBeforeNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, DoublyLinkedListNode *node);

#endif
