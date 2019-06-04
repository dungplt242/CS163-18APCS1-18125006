#include"Header.h"

void BinarySearchTree::build() {
	int x;
	cin >> x;
	while (x != 0) {
		insert(root, x);
		cin >> x;
	}
}

void BinarySearchTree::insert(Node* &cur, int x) {
	if (!cur) {
		Node* p = new Node(x);
		cur = p;
		return;
	}
	if (x > cur->data) insert(cur->right, x);
	else insert(cur->left, x);
}

void BinarySearchTree::deletetree(Node *& cur)
{
	if (!cur) return;
	deletetree(cur->left);
	deletetree(cur->right);
	delete cur;
}

void BinarySearchTree::findLevelOrder(Node * cur, vector<vector<int>> &level, int height)
{
	if (!cur) return;
	level[height].push_back(cur->data);
	findLevelOrder(cur->left, level, height + 1);
	findLevelOrder(cur->right, level, height + 1);
}

void BinarySearchTree::levelOrder()
{
	vector<vector<int>> level(500);
	findLevelOrder(root, level, 0);
	for (int i = 0; level[i].size() != 0; i++)
		for (int j = 0; j < level[i].size(); j++) cout << level[i][j] << " ";
}
