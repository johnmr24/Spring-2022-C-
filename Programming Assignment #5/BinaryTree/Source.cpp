#include <iostream>
#include <cstdlib>
#include "binarySearchTree.h"

using namespace std;

int main() 
{
	int num; //num to hold the number of nodes with only one child
	bSearchTreeType<int> bt; 

	for (int i = 0; i < 10; i++) //iterates 10 times
	{
		bt.insert(rand()%100); //inserts a random integer between 0 and 100 into the binary tree
	}

	//print out the binary tree
	cout << "Printing tree using inorder traversal: " << endl;
	bt.inorderTraversal();
	cout << endl;

	//prints the number of nodes with only one child in the binary tree
	cout << "\nThe number of nodes with only one child is: " << endl;
	num = bt.singleParent();
	cout << num << endl;

	return 0;
}