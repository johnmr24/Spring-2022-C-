#pragma once
#include <iostream>
#include "Product.h"

using namespace std;

class Inventory 
{
public:
	Inventory();
	Inventory(Product p);
	void getProdNum(string pn);
	void addItem(Product p);
	int search(string s);

private:
	Product inventory[100];

};

Inventory::Inventory()
{

}

Inventory::Inventory(Product p)
{
	inventory[0] = p;
}

void getProdNum(string pn)
