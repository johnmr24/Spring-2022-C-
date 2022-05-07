#pragma once
#include <string>
#include <iostream>

using namespace std;

//class to hold the product information
class Product 
{
public:
	Product(); //default constructor
	Product(int pn, string t, string d, double p); //constructor with parameters
	void displayProd(); //displays the product information
	int returnProductNum(); //returns the product number

private:
	int productNum; //holds the product number
	string title; //holds the product title
	string description; //holds the product description
	double price; //holds the product price
};

//default constructor
Product::Product() 
{
	productNum = 0;
	title = "";
	description = "";
	price = 0;
}

//constructor with parameters
Product::Product(int pn, string t, string d, double p)
{
	productNum = pn;
	title = t;
	description = d;
	price = p;
}

//displays the product information
void Product::displayProd()
{
	cout << "Title: " << title << endl;
	cout << "Description: " << description << endl;
	cout << "Price: $" << price << endl;
}

//returns the product number for use outside the class
int Product::returnProductNum()
{
	return productNum;
}