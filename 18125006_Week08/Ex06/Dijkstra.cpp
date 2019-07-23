#include "Dijkstra.h"

Graph::Graph(int n)
{
	this->n = n;
	a = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i)
		a[i] = new int[n + 1]{ 0 };
}

void Graph::print(int* prev, int x, int y)
{
	vector<int> result;
	result.push_back(y);
	int k = y;
	while (k != x) {
		result.push_back(prev[k]);
		k = prev[k];
	}
	for (int i = result.size() - 1; i >= 0; --i) cout << result[i] << " ";
}

void Graph::build()
{
	int x, y, w;
	cin >> x;
	while (x != 0) {
		cin >> y >> w;
		a[x][y] = a[y][x] = w;
		cin >> x;
	}
}

void Graph::findShortestPath(int x, int y)
{
	int* path = new int[n + 1];
	int* prev = new int[n + 1];
	bool* visited = new bool[n + 1];
	for (int i = 1; i < n + 1; i++) {
		path[i] = 9999999;
		visited[i] = false;
	}
	path[x] = 0;
	visited[x] = true;
	dijkstra(x, y, path, prev, visited);
	print(prev, x, y);

	delete[]path;
	delete[]prev;
	delete[]visited;
}

void Graph::dijkstra(int x, int y, int * path, int * prev, bool * visited)
{
	if (x == y) {
		return;
	}
	for (int i=1; i < n+1; ++i)
		if (a[x][i] != 0 && path[x] + a[x][i] < path[i]) {
			path[i] = path[x] + a[x][i];
			prev[i] = x;
		}
	int min = 9999999;
	for (int i=1; i<n+1; ++i)
		if (!visited[i] && path[i] < min && path[i]!=0) {
			min = path[i];
			x = i;
		}
	visited[x] = true;
	dijkstra(x, y, path, prev, visited);
}

Graph::~Graph()
{
	for (int i = 0; i < n + 1; ++i) delete[]a[i];
	delete[]a;
}
