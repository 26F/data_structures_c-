
#ifndef BINARY_TREE_H
#define BINARY_TREE_H


struct Node {
	int value;
	Node* left;
	Node* right;

	Node(int x) : value(x), left(nullptr), right(nullptr) {}

};


class BinaryTree {
	public:
		Node* root;

		BinaryTree(void) : root(nullptr) {}

		void addNode(int value, Node** node);

		void preorder(Node* node);

		void inorder(Node* node);

		void postorder(Node* node);

		Node** getRoot(void);


};


#endif //BINARY_TREE_H