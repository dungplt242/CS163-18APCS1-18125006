#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	Node(int x) {
		data = x;
	}
	int data;
	Node* right = NULL;
	Node* left = NULL;
};

class BinarySearchTree {
public:
	void build();
	void insert(Node* &cur, int x);
	void deletetree(Node* &cur);
	void findLevelOrder(Node* cur, vector<vector<int>> &level, int height);
	void levelOrder();
	~BinarySearchTree() {
		deletetree(root);
	}
private:
	Node* root = NULL;
};

#endif