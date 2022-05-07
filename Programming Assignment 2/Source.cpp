#include "Inventory.h"

#include <queue>
#include <string>

using namespace std;

int main() 
{
	queue<Inventory> inventory; //a queue to hold objects of the inventory class
	string a;

	//asks for user input
	cout << "Would you like to add an item to the inventory (A)" << endl;
	cout << "take an item from the inventory (T) " << endl;
	cout << "or any other key to stop: ";
	cin >> a;

	while ((a == "a" || a == "A") || //if the user wishes to add or take from the inventory
		   (a == "t" || a == "T"))
	{
		if (a == "a" || a == "A") //if the user wishes to add
		{
			int sNum, lNum;
			string d;

			cout << endl;
			cout << "Enter the part serial number: "; //asks for the serial number
			cin >> sNum;
			cout << "Enter the part lot number: "; //asks for the lot number
			cin >> lNum;
			cout << "Enter the date manufactored" << endl << //asks for the date manufactored
				"in the format 'mm/dd/yyyy': ";
			cin >> d;

			Inventory i(sNum, lNum, d); //creates an object of Inventory and adds it to the queue
			inventory.push(i);
		}

		else //else, the user wishes to take from the inventory
		{
			if (inventory.empty()) //if the inventory is empty
			{
				cout << "Cannot take from an empty inventory." << endl;
			}
			else //else, the inventory has items
			{
				cout << endl;
				inventory.front().printDetails(); //prints out the front item details
				inventory.pop(); //delete the item from the inventory
			}
		}

		//ask for more user input
		cout << endl;
		cout << "Would you like to add an item to the inventory (A)" << endl;
		cout << "take an item from the inventory (T)" << endl;
		cout << "or any other key to stop: ";
		cin >> a;
	}

	cout << endl;
	cout << "Printing the rest of the inventory: " << endl;
	cout << endl;

	queue<Inventory> copy(inventory); //create a copy of inventory

	while (!copy.empty()) //while the copy is not empty
	{
		copy.front().printDetails(); //print the details of the item
		cout << endl;
		copy.pop(); //delete the item
	}

	return 0;
}