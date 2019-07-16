#include "BFS.h"

void Queue::enqueue(int x)
{
	if (!head) {
		head = tail = newNode(x);
		return;
	}
	Node* p = newNode(x);
	tail->next = p;
	tail = p;
}

int Queue::dequeue()
{
	int temp = head->data;
	Node* t = head;
	head = head->next;
	if (!head) tail = head;
	delete t;
	return temp;
}

void Queue::remove()
{
	Node* cur = head;
	while (cur) {
		Node* temp = cur;
		cur = cur->next;
		delete temp;
	}
}

Node* newNode(int x) {
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void Graph::insert() {
	cout << "x-y: ";
	int x, y;
	cin >> x;
	while (x != 0) {
		cin >> y;
		a[x][y] = 1;
		a[y][x] = 1;
		cout << "x-y: ";
		cin >> x;
	}
}

void Graph::breadthFirstSearch(int x, int y)
{
	Queue q;
	q.enqueue(x);
	bool* visited;
	visited = new bool[n+1] {false};
	visited[x] = true;
	bfs(y, visited, q);
	delete[]visited;
}

void Graph::bfs(int y, bool* visited, Queue q)
{
	int x = q.dequeue();
	cout << x << " ";
	if (x == y) return;
	for (int i = 1; i < n + 1; i++)
		if (a[x][i] && !visited[i]) {
			q.enqueue(i);
			visited[i] = true;
		}
	bfs(y, visited, q);
}
