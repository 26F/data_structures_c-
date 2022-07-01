
// unit testing

#include "linkedlist.h"
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void test(T a, T b, std::string testname) 
{


	if (a != b) {


		throw (std::runtime_error(testname + " failed"));

	}

}

int main(void)
{

	std::vector<int> nums = {1,2,3,4};

	// note since the constructor uses addNodeToTail
	// the tests up to line 86
	LinkedList linkedlst(nums);


	std::vector<int> vec = linkedlst.toVector();

	try {

		test(vec.size(), nums.size(), "Check return array same length as initial");


		for (size_t i = 0; i < nums.size(); i++) {

			test(vec[i], nums[i], "array items the same as initial");

		}
	

		linkedlst.deleteHeadNode();

		vec = linkedlst.toVector();

		for (size_t i = 0; i < nums.size() - 1; i++) {

			test(vec[i], nums[i + 1], "deleteHeadNode test 1");

		}

		linkedlst.deleteHeadNode();

		vec = linkedlst.toVector();

		for (size_t i = 0; i < nums.size() - 2; i++) {

			test(vec[i], nums[i + 2], "deleteHeadNode test 2");

		}

		linkedlst.deleteHeadNode();

		vec = linkedlst.toVector();

		for (size_t i = 0; i < nums.size() - 3; i++) {

			test(vec[i], nums[i + 3], "deleteHeadNode test 3");

		}

		linkedlst.deleteHeadNode();

		vec = linkedlst.toVector();

		test(vec.empty(), std::vector<int>().empty(), "test if two vectors are empty");

		linkedlst.deleteHeadNode();

		vec = linkedlst.toVector();

		test(vec.empty(), std::vector<int>().empty(), "test if trying to delete head node from already empty list fails");

		// testing add node to head

		std::vector<int> toreverse;

		std::copy(nums.begin(), nums.end(), std::back_inserter(toreverse));

		std::reverse(toreverse.begin(), toreverse.end());

		for (int i : nums) {

			linkedlst.addNodeToHead(i);

		}

		vec = linkedlst.toVector();

		test(vec, toreverse, "testing addNodeToHead");

		linkedlst.deleteTailNode();

		vec = linkedlst.toVector();

		for (size_t i = 0; i < nums.size() - 1; i++) {

			test(vec[i], toreverse[i], "deleteTailNode");

		}

		linkedlst.deleteTailNode();

		vec = linkedlst.toVector();

		for (size_t i = 0; i < nums.size() - 2; i++) {

			test(vec[i], toreverse[i], "deleteTailNode");

		}


		linkedlst.deleteTailNode();

		vec = linkedlst.toVector();

		for (size_t i = 0; i < nums.size() - 3; i++) {

			test(vec[i], toreverse[i], "deleteTailNode");

		}

		linkedlst.deleteTailNode();

		vec = linkedlst.toVector();

		test(vec.empty(), true, "testing deleteTailNode");

		linkedlst.deleteTailNode();

		vec = linkedlst.toVector();

		test(vec.empty(), true, "testing deleteTailNode for null");

		// should be empty
		linkedlst.insertNodeAtIndex(2, 1000);

		vec = linkedlst.toVector();

		test(vec.empty(), true, "insertNodeAtIndex for invalid index (should be empty)");

		linkedlst.insertNodeAtIndex(1, 1000);

		test(vec.empty(), true, "insertNodeAtIndex for invalid index (should be empty)");

		linkedlst.insertNodeAtIndex(0, 123);

		test(linkedlst.atIndex(0), 123, "insertNodeAtIndex and atIndex");

		// should be able to insert a node at index 1
		linkedlst.insertNodeAtIndex(1, 1234);

		test(linkedlst.atIndex(1), 1234, "insertNodeAtIndex and atIndex");

		linkedlst.insertNodeAtIndex(2, 12345);

		test(linkedlst.atIndex(2), 12345, "insertNodeAtIndex and atIndex");

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({123, 1234, 12345}), "insertNodeAtIndex in order?");


		linkedlst.insertNodeAtIndex(1, 101);

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({123, 101, 1234, 12345}), "insertNodeAtIndex in order?");

		linkedlst.deleteValueAtIndex(0);

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({101, 1234, 12345}), "deleteValueAtIndex");

		linkedlst.deleteValueAtIndex(2);

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({101, 1234}), "deleteValueAtIndex");

		linkedlst.deleteValueAtIndex(0);
		linkedlst.deleteValueAtIndex(0);

		vec = linkedlst.toVector();

		test(vec.empty(), true, "deleteValueAtIndex 1");

		linkedlst.deleteValueAtIndex(0);

		vec = linkedlst.toVector();

		test(vec.empty(), true, "deleteValueAtIndex 2");

		for (int i : nums) {

			linkedlst.addNodeToTail(i);

		}

		linkedlst.reverse();

		vec = linkedlst.toVector();

		test(vec, toreverse, "reversing the linked list");

		linkedlst.deleteNode(4);

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({3,2,1}), "deleteNode");

		linkedlst.deleteNode(1);

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({3,2}), "deleteNode");

		linkedlst.deleteNode(3);

		vec = linkedlst.toVector();

		test(vec, std::vector<int>({2}), "deleteNode");

		linkedlst.deleteNode(2);

		vec = linkedlst.toVector();

		test(vec.empty(), true, "deleteNode");

		linkedlst.deleteNode(1000);

		vec = linkedlst.toVector();

		test(vec.empty(), true, "deleteNode");


				
	} catch(std::runtime_error& e) {

		std::cout << e.what() << std::endl;
		linkedlst.deleteAllNodes();

		return -1;

	}

	linkedlst.deleteAllNodes();

	test(linkedlst.empty(), true, "check if linked list knows when it's empty");


	std::cout << "all tests passed" << std::endl;


	return 0;

}




