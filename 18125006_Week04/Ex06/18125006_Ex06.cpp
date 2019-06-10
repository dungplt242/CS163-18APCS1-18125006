#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, x = 1, count, parent;
	cin >> n;
	vector<vector<int>> a(1000);
	for (int i = 0; i < n - 1; i++) {
		x++;
		cin >> parent;
		a[parent].push_back(x);
	}
	for (int i = 1; i < a.size(); i++) {
		if (a[i].size() > 0 && a[i].size() < 3) {
			cout << "No";
			return 0;
		}
		else if (a[i].size() >= 3) {
			count = 0;
			for (int j = 0; j < a[i].size(); j++) {
				if (a[a[i][j]].size() == 0) count++;
				if (count == 3) break;
			}
			if (count < 3) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}