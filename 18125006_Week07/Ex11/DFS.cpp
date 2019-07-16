#include"DFS.h"

void Graph::depthFirstSearch(int x, int y)
{
	bool* visited;
	visited = new bool[n + 1]{ false };
	visited[x] = true;

	bool found = false;

	dfs(x, y, visited, found);
	delete[]visited;
}

void Graph::dfs(int x, int y, bool* visited, bool &found)
{
	cout << x << " ";
	if (x == y) {
		found = true;
		return;
	}
	for (int i = 1; i < n + 1; i++) {
		if (a[x][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, y, visited, found);
		}
		if (found) return;
	}
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