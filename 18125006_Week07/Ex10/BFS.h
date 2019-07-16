#pragma once
#ifndef _BFS_H_
#define _BFS_H_

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* newNode(int x);

struct Queue {
	void enqueue(int x);
	int dequeue();
	void remove();
	Node* head = NULL;
	Node* tail = NULL;
};

class Graph {
public:
	Graph(int n) {
		this->n = n;
		a = new int*[n + 1];
		for (int i = 0; i < n + 1; i++) {
			a[i] = new int[n + 1] { 0 };
		}
	}
	void insert();
	void breadthFirstSearch(int x, int y);
	void bfs(int y, bool* visited, Queue q);
	~Graph() {
		for (int i = 0; i < n + 1; i++) delete[]a[i];
		delete[]a;
	}
private:
	int** a;
	int n;
};

#endif