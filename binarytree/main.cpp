
#include <iostream>
#include <vector>
#include "binarytree.h"


int main(void)
{

	BinaryTree bt;

	std::vector<int> vec{1,2,3,4,5,6,7,8,9,10,11,12};

	for (int i : vec) {

		bt.addNode(i, bt.getRoot());

	}

	bt.preorder(bt.root);

	std::cout << std::endl;

	bt.inorder(bt.root);

	std::cout << std::endl;

	bt.postorder(bt.root);

	std::cout << std::endl;

	return 0;

}