
#include <iostream>
#include <vector>

class Node {
    private:
        int value;
        Node * next;
    public:

        Node(int value) : value(value), next(NULL) {}

        int getValue() {
            return value;
        }

        void setValue(int val) {
            value = val;
        }

        Node * getNext() {
            return next;
        }

        void setNext(Node * node) {
            next = node;
        }
};

class LinkedLIst {
    private:
        Node * head = NULL;

    public:
        void addNodeToHead(int value) {
            Node * new_node = new Node(value);

            // first node gets added.
            if (head == NULL) {
                head = new_node;
            }
            else
            {
                new_node->setNext(head);
                head = new_node;
            }
        }

        void deleteHeadNode() {
            if (head == NULL) {
                return;
            }

            Node * temp = head->getNext();
            delete head;
            head = temp;
        }

        void deleteTailNode() {

            if (head == NULL) {
                return;
            }

            Node * temp = head;
            Node * prev = NULL;

            while (temp->getNext() != NULL) {
                prev = temp;
                temp = temp->getNext();
            }

            delete temp;
            temp = NULL;

            if (prev != NULL) {
                prev->setNext(temp);    
            }
            else
            {
                head = temp;
            }
            
        }

        void addNodeToTail(int value) {
            Node * new_node = new Node(value);
            Node * temp = head;

            if (head == NULL) {
                head = new_node;
            }
            else
            {
                while (temp->getNext() != NULL) {
                    temp = temp->getNext();
                }
                temp->setNext(new_node);
            }
        }

        void insertNodeValueAtIndex(int index, int value) {

            if (index == 0) {
                addNodeToHead(value);
                return;
            }

            Node * new_node = new Node(value);
            Node * temp = head;
            int count = 1;

            if (head == NULL) {
                head = new_node;
            }
            else
            {
                while (temp != NULL && count < index) {
                    temp = temp->getNext();
                    count++;
                }

                if (count > index || temp == NULL) {
                    delete new_node;
                    return;
                }

                new_node->setNext(temp->getNext());
                temp->setNext(new_node);
            }
        }

        int getValueAtIndex(int index) {
            int count = 0;
            Node * temp = head;

            while (temp != NULL && count < index) {
                temp = temp->getNext();
                count++;
            }

            if (count < index) {
                return -1;
            }

            if (temp != NULL) {
                return temp->getValue();    
            }
            else
            {
                return -1;
            }

            
        }

        void deleteValueAtIndex(int index) {
            if (head == NULL) {
                return;
            }

            if (index == 0) {
                deleteHeadNode();
                return;
            }

            Node * temp = head;
            Node * target = NULL;

            int count = 1;

            while (temp != NULL && count < index) {
                temp = temp->getNext();
                count++;
            }

            if (count < index || temp == NULL) {
                return;
            }

            target = temp->getNext();
            
            if (target != NULL) {
                temp->setNext(target->getNext());
                delete target;
            }
            else
            {
                return;
            }

        }

        void printAllNodesValues() {
            if (head == NULL) {
                return;
            }

            Node * temp = head;

            while (temp != NULL) {
                std::cout << temp->getValue() << " ";
                temp = temp->getNext();
            }
        }

        void deleteAllNodes() {
            Node * temp = NULL;

            while (head != NULL) {
                temp = head->getNext();
                delete head;
                head = temp;
            }
        }
};

int main() {
    std::vector<int> values = {1,2,3,4,5,6,7};

    LinkedLIst linkedlist;

    for (int val : values) {
        linkedlist.addNodeToTail(val);
    }

    linkedlist.printAllNodesValues();

    linkedlist.deleteAllNodes();
    return 0;
}