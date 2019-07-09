#include "AVL.h"

int main() {
	StudentList a;
	Student* root = a.getRoot();
	cout << "ID: ";
	int ID;
	bool gender;
	bool edge[2];
	cin >> ID;
	while (ID != 0) {
		cout << "Gender |1/0 (male/female)|: ";
		cin >> gender;
		a.insert(root, ID, gender, edge);
		cout << "ID: ";
		cin >> ID;
	}
	cout << endl;
	int k, x = 0, y = 0;
	cout << "k= ";
	cin >> k;
	a.findDiff(root, k, x, y);
	cout << abs(x - y) << endl;
	a.print(root, 0);

	system("pause");
}