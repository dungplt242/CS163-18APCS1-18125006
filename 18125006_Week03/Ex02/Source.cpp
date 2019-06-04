#include "Header.h"

void BinarySearchTree::insert(Node* &cur, int x)
{
	if (!cur) {
		Node* p = new Node;
		p->data = x;
		cur = p;
	}
	if (x > cur->data) insert(cur->right, x);
	if (x < cur->data) insert(cur->left, x);
}

void BinarySearchTree::deletetree(Node* cur)
{
	if (!cur) return;
	deletetree(cur->left);
	deletetree(cur->right);
	delete cur;
}

void BinarySearchTree::check(int ** view, int pos, int height, int x, int rData, int rLevel)
{
	if (view[rData][pos] && view[rLevel][pos] < height) return;
	view[rData][pos] = x;
	view[rLevel][pos] = height;
}

void BinarySearchTree::topView(Node* cur, int** view, int height, int pos)
{
	if (!cur) return;
	if (pos < 0) check(view, -pos, height, cur->data, 0, 1);
	else if (pos > 0) check(view, pos, height, cur->data, 2, 3);
	topView(cur->left, view, height + 1, pos - 1);
	topView(cur->right, view, height + 1, pos + 1);
}

void BinarySearchTree::print(int** view) {
	topView(root, view, 0, 0);
	int n = 0;
	for (int i = 1; view[0][i] != 0; i++) n++;
	for (int i = n; i >= 1; i--) cout << view[0][i] << " ";
	cout << root->data << " ";
	for (int i = 1; view[2][i] != 0; i++) cout << view[2][i] << " ";
}

void BinarySearchTree::build()
{
	int x;
	cin >> x;
	while (x != 0) {
		insert(root, x);
		cin >> x;
	}
}
