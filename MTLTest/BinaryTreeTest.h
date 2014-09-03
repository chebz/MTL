#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
#pragma once

class TestHarness {
public:

	static int comparisonInt(int a, int b)
	{
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	void traverse(BinarySearchTree<int> &tree, TreeTraversal t) {
		auto it = tree.begin(t);
		while (it != tree.end()) {
			int n = *it;
			it++;
			cout << n << ",";
		}
		cout << endl;
	}

	void doTraversals(BinarySearchTree<int> &tree) {
		cout << "Levelorder traversal:\n";
		traverse(tree, TreeTraversal::Levelorder);
		cout << endl;

		cout << "Preorder traversal:\n";
		traverse(tree, TreeTraversal::Preorder);
		cout << endl;

		cout << "Inorder traversal:\n";
		traverse(tree, TreeTraversal::Inorder);
		cout << endl;

		cout << "Postorder traversal:\n";
		traverse(tree, TreeTraversal::Postorder);
		cout << endl;
	}

	void test() {
		BinarySearchTree<int> tree(&TestHarness::comparisonInt);
		tree.insert(5);
		tree.insert(3);
		tree.insert(4);
		tree.insert(1);
		tree.insert(11);
		tree.insert(21);

		int * n = tree.search(1);
		cout << *n << endl;
		n = tree.search(11);
		cout << *n << endl;

		doTraversals(tree);

		cout << "Deleted 3\n\n";
		tree.deleteNode(3);

		doTraversals(tree);
	}

	
};