#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	input.open("input.txt");
	if (input.is_open()) {
		int x;
		while (!input.eof()) {
			input >> x;
			insert(x, root);
		}
		input.close();
	}
	else cout << "File not found!";
}

void BinarySearchTree::insert(int x, Node* &cur)
{
	if (!cur) {
		Node* p = new Node;
		p->data = x;
		cur = p;
		return;
	}
	if (x > cur->data) insert(x, cur->right);
	else insert(x, cur->left);
}

void BinarySearchTree::pre_order(Node* cur)
{
	if (!cur) return;
	cout << cur->data << " ";
	pre_order(cur->left);
	pre_order(cur->right);
}

void BinarySearchTree::ascending(Node * cur)
{
	if (!cur) return;
	ascending(cur->left);
	cout << cur->data << " ";
	ascending(cur->right);
}

void BinarySearchTree::descending(Node * cur)
{
	if (!cur) return;
	descending(cur->right);
	cout << cur->data << " ";
	descending(cur->left);
}

void BinarySearchTree::post_order(Node * cur)
{
	if (!cur) return;
	post_order(cur->left);
	post_order(cur->right);
	cout << cur->data << " ";
}

int BinarySearchTree::height(Node* cur)
{
	if (!cur) return 0;
	int left = height(cur->left);
	int right = height(cur->right);
	if (left > right)
		return left + 1;
	else return right + 1;
}

Node * BinarySearchTree::minimum(Node* cur)
{
	if (!cur || !cur->left) return cur;
	return minimum(cur->left);
}

Node * BinarySearchTree::maximum(Node * cur)
{
	if (!cur || !cur->right) return cur;
	return maximum(cur->right);
}

Node * BinarySearchTree::successor(int x, Node* cur, Node* rightCur)
{
	if (!cur)
		return nullptr;
	if (x == cur->data) {
		if (cur->right) return minimum(cur->right);
		else return rightCur;
	}
	if (x > cur->data) return successor(x, cur->right, rightCur);
	else {
		rightCur = cur;
		return successor(x, cur->left, rightCur);
	}
}

Node * BinarySearchTree::predecessor(int x, Node * cur, Node * leftCur)
{
	if (!cur)
		return nullptr;
	if (x == cur->data) {
		if (cur->left) return maximum(cur->left);
		else return leftCur;
	}
	if (x < cur->data) return predecessor(x, cur->left, leftCur);
	else {
		leftCur = cur;
		return predecessor(x, cur->right, leftCur);
	}
}

void BinarySearchTree::deleteTree(Node *& cur)
{
	if (!cur) return;
	post_order(cur->left);
	post_order(cur->right);
	delete cur;
}

BinarySearchTree::~BinarySearchTree()
{
	deleteTree(root);
}

void BinarySearchTree::output()
{
	cout << "Pre-order: ";
	pre_order(root);
	cout << endl;

	cout << "Ascending: ";
	ascending(root);
	cout << endl;

	cout << "Descending: ";
	descending(root);
	cout << endl;

	cout << "Post-order: ";
	post_order(root);
	cout << endl;

	cout << "Height: " << height(root) << endl;

	cout << "Minimum: " << minimum(root)->data << endl;

	cout << "Maximum: " << maximum(root)->data << endl;

	int x;
	cout << "x= ";
	cin >> x;
	Node* s = successor(x, root, nullptr), *p = predecessor(x, root, nullptr);
	cout << "Successor: ";
	if (s) cout << s->data << endl;
	else cout << "not found" << endl;
	cout << "Predecessor: ";
	if (p) cout << p->data << endl;
	else cout << "not found" << endl;
}
