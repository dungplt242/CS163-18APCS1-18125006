#include <iostream>
using namespace std;

void insert(int** a, int m) {
	int i, j, k;
	for (int i = 0; i < m; i++) {
		cin >> i >> j >> k;
		a[i][j] = a[j][i] = k;
	}
}

void cheapestWay(bool* visited, int** a, int count, int cost, int n) {
	if (count == n) {
		cout << endl;
		cout << cost;
		return;
	}
	int min = 99999, k = 0, m = 0;
	for (int i = 1; i < n + 1; i++)
		if (visited[i]) {
			for (int j = 1; j < n + 1; j++) {
				if (!visited[j] && a[i][j] > 0 && a[i][j] < min) {
					min = a[i][j];
					k = j;
					m = i;
				}
			}
		}
	count++;
	cost += a[m][k];
	visited[k] = true;
	cout << k << " ";
	cheapestWay(visited, a, count, cost, n);
}

int main() {
	int n, m;
	cin >> n;
	int** a;
	a = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		a[i] = new int[n + 1]{ 0 };

	cin >> m;
	insert(a, m);

	bool* visited;
	visited = new bool[n + 1]{ false };
	visited[1] = true;
	int count = 1, cost = 0;

	cheapestWay(visited, a, count, cost, n);

	for (int i = 0; i < n + 1; i++) delete[]a[i];
	delete[]a;
	delete[]visited;
}