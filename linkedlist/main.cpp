
#include "linkedlist.h"
#include <iostream>
#include <vector>



int main(void)
{

	LinkedList linkedlst;

	linkedlst.addNodeToHead(1);
	linkedlst.printNodes();

	linkedlst.deleteTailNode();
	linkedlst.printNodes();

	linkedlst.addNodeToTail(2);
	linkedlst.printNodes();

	linkedlst.deleteHeadNode();
	linkedlst.printNodes();

	linkedlst.addNodeToHead(100);
	linkedlst.deleteHeadNode();
	linkedlst.printNodes();

	linkedlst.addNodeToTail(100);
	linkedlst.deleteTailNode();
	linkedlst.printNodes();

	
	for (int i = 0; i < 1; i++) {

		linkedlst.addNodeToTail(i);

	}

	linkedlst.deleteNode(6);

	linkedlst.printNodes();

	linkedlst.deleteValueAtIndex(0);

	linkedlst.printNodes();

	for (int i = 0; i < 100; i++) {

		linkedlst.addNodeToHead(i);

	}

	for (int i = 0; i < 100; i++) {

		linkedlst.deleteHeadNode();

	}

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

	linkedlst.printNodes();

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

	for (int i = 0; i < 10; i++) {

		linkedlst.addNodeToTail(i);

	}

	for (int i = -1; i < 11; i++) {

		std::cout << linkedlst.atIndex(i) << " ";

	}

	linkedlst.deleteAllNodes();

	std::cout << std::endl;
	

	linkedlst.insertNodeAtIndex(0, 20);
	linkedlst.printNodes();

	linkedlst.insertNodeAtIndex(1, 50);
	linkedlst.printNodes();

	linkedlst.insertNodeAtIndex(0, 100);
	linkedlst.printNodes();

	linkedlst.insertNodeAtIndex(3, 200);
	linkedlst.printNodes();

	linkedlst.insertNodeAtIndex(1, 23);
	linkedlst.printNodes();

	linkedlst.insertNodeAtIndex(3, 32);
	linkedlst.printNodes();

	linkedlst.deleteHeadNode();
	linkedlst.printNodes();

	linkedlst.deleteTailNode();
	linkedlst.printNodes();

	linkedlst.deleteValueAtIndex(1);
	linkedlst.printNodes();

	linkedlst.deleteValueAtIndex(2);
	linkedlst.printNodes();

	linkedlst.deleteValueAtIndex(0);
	linkedlst.printNodes();

	linkedlst.deleteValueAtIndex(0);
	linkedlst.printNodes();



	//linkedlst.deleteAllNodes();

	return 0;

}




