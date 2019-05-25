#ifndef _BINARYSEARCHTREE_
#define _BINARYSEARCHTREE_

#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

class BinarySearchTree {
public:
	BinarySearchTree();
	void insert(int x, Node* &cur);
	void pre_order(Node* cur);
	void ascending(Node* cur);
	void descending(Node* cur);
	void post_order(Node* cur);
	int height(Node* cur);
	Node* minimum(Node* cur);
	Node* maximum(Node* cur);
	Node* successor(int x, Node* cur, Node* rightCur);
	Node* predecessor(int x, Node* cur, Node* leftCur);
	void deleteTree(Node* &cur);
	~BinarySearchTree();

	void output();

private:
	Node* root = NULL;
	ifstream input;
};

#endif
