#pragma once
#ifndef _AVL_H_
#define _AVL_H_

#include<iostream>
using namespace std;

struct Student {
	int ID;
	bool male;
	Student* right;
	Student* left;
};

int max(int x, int y);
Student* newStudent(int ID, bool male);

class StudentList {
public:
	Student* getRoot() {
		return root;
	}
	void display(Student* cur);
	void rotate(Student* &cur, bool right);
	int height(Student* cur);
	void insert(Student * &cur, int ID, bool male, bool edge[]);
	void remove(Student*& cur);
	void update(Student*& cur, int ID);
	void findDiff(Student* cur, int k, int &male, int &female);
	void print(Student*&cur, int height);
	~StudentList() {
		remove(root);
	}
private:
	Student* root = NULL;
};

#endif