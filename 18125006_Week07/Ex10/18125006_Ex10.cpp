#include "BFS.h"

int main() {
	int n;
	cin >> n;
	Graph g(n);
	g.insert();
	int x, y;
	cout << "BFS: ";
	cin >> x >> y;
	g.breadthFirstSearch(x, y);
	system("pause");
}