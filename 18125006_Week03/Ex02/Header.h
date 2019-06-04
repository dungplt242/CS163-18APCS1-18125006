#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

class BinarySearchTree {
public:
	void insert(Node* &cur, int x);
	void deletetree(Node* cur);
	void check(int** view, int pos, int height, int x, int rData, int rLevel);
	void topView(Node* cur, int** view, int height, int pos);
	void print(int** view);
	void build();
	~BinarySearchTree() {
		deletetree(root);
	}
private:
	Node* root = NULL;
};

#endif