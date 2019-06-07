#pragma once
#ifndef _23_TREE_
#define _23_TREE_

#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int data1=0;
	int data2=0;
	Node* left = NULL;
	Node* mid = NULL;
	Node* right = NULL;
	int n = 1;
};

Node* newNode(int x, Node* &left, Node* &mid);

class _23Tree {
public:
	_23Tree();
	void in_order(Node* root);
	void insert(Node *& root, int &x, bool &added, Node* &p1, Node* &p2);
	void deleteTree(Node* &root);
	~_23Tree();
private:
	ifstream input;
	Node* root = NULL;
};

#endif