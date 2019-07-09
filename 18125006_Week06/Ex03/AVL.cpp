#include "AVL.h"

Student* newStudent(int ID, bool male) {
	Student* temp = new Student;
	temp->ID = ID;
	temp->male = male;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void StudentList::display(Student * cur)
{
	if (!cur) return;
	cout << cur->ID << ": " << cur->male << endl;
	display(cur->left);
	display(cur->right);
}

void StudentList::rotate(Student *& cur, bool right)
{
	if (right) {
		Student* temp_ = cur->left->right;
		cur->left->right = cur;
		cur = cur->left;
		cur->right->left = temp_;
	}
	else {
		Student* temp_ = cur->right->left;
		cur->right->left = cur;
		cur = cur->right;
		cur->left->right = temp_;
	}
}

int StudentList::height(Student * cur)
{
	if (!cur) return 0;
	return max(height(cur->right), height(cur->left)) + 1;
}

void StudentList::insert(Student * &cur, int ID, bool male, bool edge[])
{
	// right = true ; left = false 
	if (!cur) {
		cur = newStudent(ID, male);
		return;
	}
	if (ID > cur->ID) {
		insert(cur->right, ID, male, edge);  
		edge[1] = edge[0];
		edge[0] = true;
	}
	else {
		insert(cur->left, ID, male, edge);
		edge[1] = edge[0];
		edge[0] = false;
	}
	if (abs(height(cur->right) - height(cur->left)) > 1) {
		if (edge[0] && edge[1]) rotate(cur, false); //left
		else if (!edge[0] && !edge[1]) rotate(cur, true); //right
		else if (!edge[0] && edge[1]) {
			rotate(cur->left, false);
			rotate(cur, true);
		} //left-right
		else {
			rotate(cur->right, true);
			rotate(cur, false);
		} //right-left
	}
}

void StudentList::remove(Student *& cur)
{
	if (!cur) return;
	remove(cur->left);
	remove(cur->right);
	delete cur;
}

void StudentList::update(Student *& cur, int ID)
{
	if (!cur) {
		cout << "ID not found" << endl;
		return;
	}
	if (cur->ID == ID) {
		if (!cur->male) cur->male = true;
		else cur->male = false;
		cout << "Update successfully" << endl;
	}
	else if (cur->ID > ID) update(cur->right, ID);
	else update(cur->left, ID);
}

void StudentList::findDiff(Student * cur, int k, int &male, int &female)
{
	if (!cur || cur->ID >= k) return;
	findDiff(cur->left, k, male, female);
	if (cur->male) male++;
	else female++;
	findDiff(cur->right, k, male, female);
}

void StudentList::print(Student *& cur, int height) {
	if (!cur) return;
	print(cur->right, height + 1);
	for (int i = 0; i < height; ++i) {
		cout << "       ";
	}
	cout << cur->ID << endl;
	print(cur->left, height + 1);
}

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
