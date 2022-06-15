
#include "linkedlist.h"

// Constructor
Node::Node(int value) : value(value), next(NULL) {}

// get value from Node
int Node::getValue(void)
{

	return value;

}


// set Nodes value
void Node::setValue(int val)
{

	value = val;

}



// get next node
Node* Node::getNext() 
{

	return next;

}


// set Node's next node
void Node::setNext(Node* node)
{

	next = node;

}



// Add node to linked list head
void LinkedList::addNodeToHead(int value)
{

	// this must be freed later.
	Node* new_node = new Node(value);

	// If head is null, head becomes first node.
	if (head == NULL) {

		head = new_node;

	} else {

		// else the new node becomes the head
		new_node->setNext(head);
		head = new_node;

	}

}


// add node to tail of linked list
void LinkedList::addNodeToTail(int value)
{


	Node* new_node = new Node(value);
	Node* temp = head;

	// if head is NULL it becomes 
	// new node
	if (head == NULL) {

		head = new_node;

	} else {

		// we find the tail (NULL node)
		// and set it to a new node.
		while (temp->getNext() != NULL) {

			temp = temp->getNext();

		}

		temp->setNext(new_node);	

	}

}


// delete head node.
void LinkedList::deleteHeadNode(void)
{

	// no point deleting if it is already not there
	if (head == NULL) {

		return ;

	}


	Node* temp = head->getNext();
	delete head;
	head = temp;

}



// delete tail node.
void LinkedList::deleteTailNode(void)
{

	// if head is already NULL it means the list
	// is empty;
	if (head == NULL) {

		return ;

	}

	// iterate through nodes without changing head.
	Node* temp = head;
	Node* prev = NULL;

	// find the last valid node.
	while (temp->getNext() != NULL) {

		// get the node before the last valid node
		prev = temp;
		temp = temp->getNext();

	}


	// delete the tail node
	delete temp;
	temp = NULL;

	// in the case that head wasn't already tail, 
	// 
	if (prev != NULL) {

		// e.g set it NULL
		prev->setNext(temp);

	} else {

		// We deleted head and set it NULL
		head = temp;

	}

}



// insert a node into the linked list at a given index.
void LinkedList::insertNodeAtIndex(int index, int value)
{

	// add node to head if index zero since head is first 
	if (index == 0) {

		addNodeToHead(value);
		return ;

	}


	// create a new node
	Node* new_node = new Node(value);
	
	// we need to be able to iterate through nodes
	// without changing head.
	Node* temp = head;
	
	int count = 1;

	// if head is NULL and index is zero
	// set head to point to new node.
	if (head == NULL && index == 0) {

			head = new_node;		

	} else {

		// If either of these conditions are broken, we
		// either have reached the index or there is no
		// such index since node null before reaching. 
		while (temp != NULL && count < index) {

			temp = temp->getNext();
			count++;

		}


		// If temp is NULL at this point it means
		// that head was NULL when index wasn't zero.
		// so we clean up new node.
		if (count > index || temp == NULL) {

			delete new_node;
			return ;

		}


		// assign a new node to the linked list
		new_node->setNext(temp->getNext());
		temp->setNext(new_node);

	}
}



int LinkedList::atIndex(int index)
{


	if (index < 0) {

		return -1;

	}

	int count = 0;
	Node* temp = head;

	while (temp != NULL && count < index) {

		temp = temp->getNext();
		count++;

	}


	if (count < index) {

		return -1;

	}


	if (temp != NULL) {

		return temp->getValue();

	} else {

		return -1;

	}

}



void LinkedList::deleteValueAtIndex(int index)
{

	if (head == NULL || index < 0) {
		return ;

	}

	if (index == 0) {
		deleteHeadNode();
		return ;

	}


	Node* temp = head;
	Node* target = NULL;

	int count = 1;

	while (temp != NULL && count < index) {

		temp = temp->getNext();
		count++;

	}

	if (count < index || temp == NULL) {

		return ;

	}

	target = temp->getNext();


	if (target != NULL) {

		temp->setNext(target->getNext());
		delete target;

	} else {

		return ;

	}

}



void LinkedList::deleteNode(int value)
{

	if (head == NULL) {

		return ;

	}	


	if (head->getValue() == value) {

		deleteHeadNode();
		return ;

	}


	Node* temp = head;
	Node* target = NULL;


	while (temp->getNext() != NULL && temp->getNext()->getValue() != value) {

		temp = temp->getNext();

	}


	if (temp == NULL) {

		return ;

	}


	target = temp->getNext();


	if (target != NULL) {

		temp->setNext(target->getNext());
		delete target;

	} else {

		return ;

	}

}


// simply check if head is NULL
bool LinkedList::empty(void)
{

	return (head == NULL);

}



void LinkedList::printNodes(void)
{

	if (head == NULL) {

		std::cout << "EMPTY" << std::endl;

		return ;

	}

	Node* temp = head;

	while (temp != NULL) {

		std::cout << temp->getValue() << " ";
		temp = temp->getNext();

	}

	std::cout << std::endl;

}



void LinkedList::deleteAllNodes(void)
{

	Node* temp = head;

	while (head != NULL) {

		temp = head->getNext();
		delete head;
		head = temp;

	}

}



LinkedList::LinkedList(void)
{



}


LinkedList::LinkedList(std::vector<int> vec)
{


	for (int val : vec) {

		addNodeToTail(val);

	}

}







