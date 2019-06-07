#ifndef _BST_H_
#define _BST_H_

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node* right = NULL;
	Node* left = NULL;
};

class BinarySearchTree {
public:
	BinarySearchTree() {
		int x;
		cin >> x;
		while (x != 0) {
			insert(root, x);
			cin >> x;
		}

		cout << checkBST(root) << endl;
	}
	void in_order(Node* root, vector<int> &test);
	bool checkBST(Node* root);
	void insert(Node* &root, int x);
	void deleteTree(Node* root);
	~BinarySearchTree() {
		deleteTree(root);
	}
private:
	Node* root = NULL;
};

#endif