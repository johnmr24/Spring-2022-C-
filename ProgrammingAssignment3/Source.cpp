#include "Product.h"
#include <iostream>
#include <string>

using namespace std;

int getProdNum(); //asks the user to enter a product number
void search(int n, Product[]); //searches the inventory for a product number

int main()
{
	string response;

	Product inventory[10] //initializes an inventory of size 10
	{
		//sets all of the products within the inventory
		{1001, "Black Beans", "Beans", 1.99},
		{1002, "Refried Beans", "Beans", 2.99},
		{1003, "Peaches", "Fruit", 3.99},
		{1004, "Strawberries", "Fruit", 4.99},
		{1005, "White Bread", "Bread", 0.99},
		{1006, "Bike", "Toy", 149.99},
		{1007, "Couch", "Home Living", 599.99},
		{1008, "Milk", "Dairy", 2.99},
		{1009, "Carrots", "Vegetable", 3.99},
		{1010, "Shampoo", "Hygiene", 4.99}
	};
	
	//do while loops allows the user to repeat the program
	do 
	{
		int num = getProdNum(); //gets the product number from the user
		search(num, inventory); //searches the inventory for a product number

		//asks the user if they want to run the program again
		cout << endl;
		cout << "Would you like to search for another product? (Y) ";
		cin >> response;
		cout << endl;

	} while (response == "y" || response == "Y");

	return 0;
}

//gets the product number from the user
int getProdNum()
{
	int number;

	//asks the user for input
	cout << "Enter a product number: ";
	cin >> number;

	//while the user entered a value outside the range
	while (number < 1001 || number > 1010) 
	{
		//ask for new input within the range
		cout << "Invalid product number, enter a valid product number: ";
		cin >> number;
	}

	//return the number
	return number;
}

//searches the inventory for a product number
void search(int n, Product inv[])
{
	//iterates sequentially through the inventory
	for (int i = 0; i <= 10; i++)
	{
		//if the user entered product number is equal to the inventory product number
		if (n == inv[i].returnProductNum())
		{
			//display the product information
			inv[i].displayProd();
			break;
		}
	}
}
