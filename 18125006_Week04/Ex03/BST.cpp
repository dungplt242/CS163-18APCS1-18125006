#include "BST.h"

void BinarySearchTree::in_order(Node * root, vector<int> &test)
{
	if (!root) return;
	in_order(root->left, test);
	test.push_back(root->data);
	in_order(root->right, test);
}

bool BinarySearchTree::checkBST(Node * root)
{
	vector<int> test;
	in_order(root, test);
	for (int i = 0; i < test.size() - 1; i++)
		if (test[i] >= test[i + 1]) return false;
	return true;
}

void BinarySearchTree::insert(Node * &root, int x)
{
	if (!root) {
		root = new Node;
		root->data = x;
		return;
	}
	if (x < root->data) insert(root->left, x);
	else insert(root->right, x);
}

void BinarySearchTree::deleteTree(Node * root)
{
	if (!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
