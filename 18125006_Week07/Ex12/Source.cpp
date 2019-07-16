#include"Header.h"

void Graph::dfs(int x, bool* visited)
{
	for (int i = 1; i < n + 1; i++) {
		if (a[x][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, visited);
		}
	}
}
int Graph::count()
{
	bool* visited, checkAll = false;
	visited = new bool[n + 1]{ false };
	int x = 1, temp = 0;
	visited[x] = true;

	while (!checkAll) {
		temp++;
		dfs(x, visited);
		checkAll = true;
		for (int i = 1; i < n + 1; i++) {
			if (!visited[i]) {
				x = i;
				checkAll = false;
				break;
			}
		}
	}

	delete[]visited;
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

