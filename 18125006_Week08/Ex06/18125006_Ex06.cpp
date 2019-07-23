#include "Dijkstra.h"

int main() {
	int n;
	cin >> n;
	Graph g(n);
	g.build();
	int x, y;
	cin >> x >> y;
	g.findShortestPath(x, y);
	system("pause");
}