#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

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
	BinarySearchTree() {
		tree.open("tree.txt");
		if (tree.is_open()) {
			int x;
			while (!tree.eof()) {
				tree >> x;
				insert(root, x);
			}
			tree.close();
			cout << "Remove x: ";
			cin >> x;
			deleteX(root, x);
		}
		else cout << "File not found";
	}
	void insert(Node* &cur, int x);
	void deleteTree(Node* cur);
	Node* maxLeft(Node* cur);
	void deleteX(Node* &cur, int x);
	void save(Node* cur);
	~BinarySearchTree() {
		treeDel.open("treeout.txt");
		save(root);
		treeDel.close();
		cout << "Success" << endl;
		system("pause");

		deleteTree(root);
	}
private:
	Node* root = NULL;
	ifstream tree;
	ofstream treeDel;
};

#endif