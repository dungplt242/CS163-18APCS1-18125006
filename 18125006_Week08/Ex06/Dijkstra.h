#pragma once
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include<iostream>
#include<vector>
using namespace std;

class Graph {
public:
	Graph(int n);

	void print(int* prev, int x, int y);

	void build();

	void findShortestPath(int x, int y);

	void dijkstra(int x, int y, int* path, int* prev, bool* visited);

	~Graph();
private:
	int** a;
	int n;
};

#endif