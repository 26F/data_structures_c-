
#include "binarytree.h"
#include <iostream>
#include <queue>

void BinaryTree::addNode(int value, Node** node)
{


	if (*node == nullptr) {

		*node = new Node(value);

		return;

	}


	std::queue<Node*> q;
	q.push(*node);


	while (!q.empty()) {

		Node* temp = q.front();

		q.pop();

		if (temp->left != nullptr) {

			q.push(temp->left);

		} else {

			temp->left = new Node(value);

			return;

		}


		if (temp->right != nullptr) {

			q.push(temp->right);

		} else {

			temp->right = new Node(value);

			return ;

		}

	}

}



void BinaryTree::preorder(Node* node)
{


	if (node == nullptr) {

		return;

	}

	std::cout << node->value << " ";

	preorder(node->left);
	preorder(node->right);

}



void BinaryTree::inorder(Node* node)
{


	

	if (node == nullptr) {

		return;

	}

	inorder(node->left);

	std::cout << node->value << " ";

	inorder(node->right);

}



void BinaryTree::postorder(Node* node)
{


	if (node == nullptr) {

		return;

	}

	postorder(node->left);
	postorder(node->right);

	std::cout << node->value << " ";


}



void BinaryTree::levelorder(Node* node)
{


	if (!(node)) {

		return;

	}


	std::queue<Node*> process;
	process.push(node);

	while (!(process.empty())) {

		int n = process.size();

		for (int i = 0; i < n; i++) {

			Node* current = process.front();
			process.pop();

			if (current->left) {

				process.push(current->left);

			}


			if (current->right) {

				process.push(current->right);

			}


			std::cout << current->value << " ";

		}

	}

}



Node** BinaryTree::getRoot(void)
{

	return &root;

}

