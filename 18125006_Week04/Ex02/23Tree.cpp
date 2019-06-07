#include "23Tree.h"

Node * newNode(int x, Node* &left, Node* &mid)
{
	Node* p = new Node;
	p->data1 = x;
	p->n = 1;
	p->left = left;
	p->mid = mid;
	return p;
}

_23Tree::_23Tree()
{
	input.open("input.txt");
	if (input.is_open()) {
		int x;
		bool added;
		Node* p1, *p2;
		while (!input.eof()) {
			input >> x;
			added = false;
			p1 = NULL; p2 = NULL;
			insert(root, x, added, p1, p2);
		}
	}
	else cout << "Can't find file." << endl;
	input.close();

	in_order(root);
}

void _23Tree::in_order(Node * root)
{
	if (!root) return;
	in_order(root->left);
	cout << root->data1 << " ";
	if (root->n == 2) {
		in_order(root->mid);
		cout << root->data2 << " ";
		in_order(root->right);
	}
	else in_order(root->mid);
}

void _23Tree::insert(Node *& pRoot, int &x, bool & added, Node* &p1, Node* &p2)
{
	//first node
	if (!this->root) {
		Node* p = new Node;
		p->data1 = x;
		root = p;
		return;
	}

	//traverse to leaf
	if (pRoot->left) {
		if (pRoot->n == 1) {
			if (x < pRoot->data1) insert(pRoot->left, x, added, p1, p2);
			else insert(pRoot->mid, x, added, p1, p2);
		}
		else if (pRoot->n == 2) {
			if (x < pRoot->data1) insert(pRoot->left, x, added, p1, p2);
			else if (x > pRoot->data2) insert(pRoot->right, x, added, p1, p2);
			else insert(pRoot->mid, x, added, p1, p2);
		}
	}

	//if finished, return
	if (added) return;

	//add
	//1 data
	if (pRoot->n == 1) {
		if (x > pRoot->data1) {
			pRoot->data2 = x;
			pRoot->right = p2;
			pRoot->mid = p1;
		}
		else {
			pRoot->data2 = pRoot->data1;
			pRoot->data1 = x;
			pRoot->left = p1;
			pRoot->right = pRoot->mid;
			pRoot->mid = p2;
		}
		pRoot->n = 2;
		added = true;
	}
	//2 data
	else {
		Node* temp1 = p1, *temp2 = p2;
		int temp;
		if (x < pRoot->data1) {
			temp = pRoot->data1;
			pRoot->data1 = x;
			//x<data1
			p1 = newNode(pRoot->data1, temp1, temp2);
			p2 = newNode(pRoot->data2, pRoot->mid, pRoot->right);
		}
		else if (x > pRoot->data2) {
			temp = pRoot->data2;
			pRoot->data2 = x;
			//x>data2
			p1 = newNode(pRoot->data1, pRoot->left, pRoot->mid);
			p2 = newNode(pRoot->data2, temp1, temp2);
		}
		else {
			temp = x;
			//data1<x<data2
			p1 = newNode(pRoot->data1, pRoot->left, temp1);
			p2 = newNode(pRoot->data2, temp2, pRoot->right);
		}

		delete pRoot;

		if (pRoot == this->root) {
			Node* tempNode = new Node;
			tempNode->data1 = temp;
			tempNode->data2 = 0;
			tempNode->left = p1;
			tempNode->mid = p2;
			tempNode->n = 1;
			pRoot = tempNode;
		}

		x = temp; //update x to add x to parent
	}
}

void _23Tree::deleteTree(Node *& root)
{
	if (!root) return;
	deleteTree(root->left);
	deleteTree(root->mid);
	deleteTree(root->right);
	delete root;
}

_23Tree::~_23Tree()
{
	deleteTree(root);
}
