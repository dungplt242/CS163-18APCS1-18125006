#include"DFS.h"

int main() {
	int n;
	cin >> n;
	Graph g(n);
	g.insert();
	int x, y;
	cin >> x >> y;
	g.depthFirstSearch(x, y);
	system("pause");
}