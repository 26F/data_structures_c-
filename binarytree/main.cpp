
#include <iostream>
#include <vector>
#include "binarytree.h"


int main(void)
{

	BinaryTree bt;

	std::vector<int> vec{0,1,2,3,4,5,6};

	for (int i : vec) {

		bt.addNode(i, bt.getRoot());

	}

	bt.preorder(bt.root);

	std::cout << std::endl;

	bt.inorder(bt.root);

	std::cout << std::endl;

	bt.postorder(bt.root);

	std::cout << std::endl;

	bt.levelorder(bt.root);

	std::cout << std::endl;

	return 0;

}