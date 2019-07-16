#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

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
	void dfs(int x, bool* visited);
	int count();
	void insert();
	~Graph() {
		for (int i = 0; i < n + 1; i++) delete[]a[i];
		delete[]a;
	}
private:
	int** a;
	int n;
};

#endif