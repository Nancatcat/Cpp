#define  _CRT_SECURE_NO_WARNINGS
#include"BinarySearchTree.h"


int main()
{
	BSTree<int> Tree;

	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		Tree.Insert(e);
	}
	Tree.InOrder();

	Tree.Erase(8);
	Tree.InOrder();

	Tree.Erase(14);
	Tree.InOrder();

	Tree.Erase(4);
	Tree.InOrder();

	Tree.Erase(6);
	Tree.InOrder();

	for (auto e : a)
	{
		Tree.Erase(e);
		Tree.InOrder();
	}
	return 0;


}