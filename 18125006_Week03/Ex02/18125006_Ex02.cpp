#include "Header.h"

int main() {
	BinarySearchTree bst;
	bst.build();

	int** view;
	view = new int*[4];
	for (int i = 0; i < 4; i++) view[i] = new int[500]{ 0 };

	bst.print(view);

	system("pause");

	for (int i = 0; i < 3; i++) delete[]view[i];
	delete[]view;
	return 0;
}