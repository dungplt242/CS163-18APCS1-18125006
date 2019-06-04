#include"Header.h"

void BinarySearchTree::insert(Node* &cur, int x) {
	if (!cur) {
		Node* p = new Node;
		p->data = x;
		cur = p;
	}
	if (x > cur->data) insert(cur->right, x);
	if (x < cur->data) insert(cur->left, x);
}

void BinarySearchTree::deleteTree(Node* cur) {
	if (!cur) return;
	deleteTree(cur->left);
	deleteTree(cur->right);
	delete cur;
}

void BinarySearchTree::save(Node* cur) {
	if (!cur) return;
	save(cur->left);
	treeDel << cur->data << " ";
	save(cur->right);
}

Node* BinarySearchTree::maxLeft(Node* cur) {
	if (!cur) return nullptr;
	if (cur->right) return maxLeft(cur->right);
	else return cur;
}

void BinarySearchTree::deleteX(Node* &cur, int x) {
	if (x > cur->data) deleteX(cur->right, x);
	else if (x < cur->data) deleteX(cur->left, x);
	else {
		if (!cur->right || !cur->left) {
			Node* temp = cur;
			if (!cur->right) cur = cur->left;
			else cur = cur->right;
			delete temp;
		}
		else {
			Node* p = maxLeft(cur->left);
			cur->data = p->data;
			p->data = x;
			deleteX(cur->left, x);
		}
	}
}