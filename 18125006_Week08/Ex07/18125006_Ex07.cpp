#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	int* s, *par;
	s = new int[n + 1]{ 0 };
	par = new int[n + 1]{ 0 };

	for (int i = 2; i < n + 1; i++) {
		cin >> par[i];
	}
	for (int i = 1; i < n + 1; i++) {
		cin >> s[i];
		if (s[i] == -1) s[i] = INT_MAX;
		else s[par[i]] = min(s[par[i]], s[i]);
	}

	long long temp = 0;
	for (int i = 1; i < n + 1; i++) {
		if (s[i] < s[par[i]]) {
			cout << "-1";
			return 0;
		}
		else if (s[i] != INT_MAX) temp += s[i] - s[par[i]];
	}
	cout << temp;
	system("pause");
	delete[]par;
	delete[]s;
}