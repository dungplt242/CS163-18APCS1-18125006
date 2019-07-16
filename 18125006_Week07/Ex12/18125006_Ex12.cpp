#include"Header.h"

int main() {
	int n;
	cin >> n;
	Graph g(n);
	g.insert();
	cout << g.count() << endl;
	system("pause");
}