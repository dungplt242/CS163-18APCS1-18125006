#pragma once
#ifndef _DFS_H_
#define _DFS_H_

#include<iostream>
using namespace std;

class Graph {
public:
	Graph(int n) {
		this->n = n;
		a = new int*[n + 1];
		for (int i = 0; i < n + 1; i++) {
			a[i] = new int[n + 1]{ 0 };
		}
	}
	void depthFirstSearch(int x, int y);
	void dfs(int x, int y, bool* visited, bool &found);
	void insert();
	~Graph() {
		for (int i = 0; i < n + 1; i++) delete[]a[i];
		delete[]a;
	}
private:
	int** a;
	int n;
};

#endif // !
