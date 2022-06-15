
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>

/*
Tested implementation of a linked list.

*/

// Linked lists are made from connected nodes.
class Node {
	private:
		int value;
		Node* next;

	public:

		Node(int value);

		int getValue(void);

		void setValue(int val);

		Node* getNext();

		void setNext(Node* node);

};

// Linked list has a head
class LinkedList {
	private:
		Node* head = NULL;

	public:

		LinkedList(void);
		LinkedList(std::vector<int> vec);

		void addNodeToHead(int value);
		void addNodeToTail(int value);

		void deleteHeadNode(void);
		void deleteTailNode(void);

		void insertNodeAtIndex(int index, int value);

		int atIndex(int index);

		void deleteValueAtIndex(int index);
		void deleteNode(int value);

		bool empty(void);

		void printNodes(void);

		void deleteAllNodes(void);

};

#endif //LINKED_LIST_H


