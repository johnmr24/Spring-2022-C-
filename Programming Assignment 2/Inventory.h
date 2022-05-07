#pragma once
#include <iostream>

using namespace std;

class Inventory {

public:
	Inventory(); //default constructor
	Inventory(int s, int l, string d); //default constructor with parameters
	void setSerialNum(int s); //sets the serial number
	void setLotNum(int l); //sets the lot number
	void setManufactDate(string d); //sets the manufactor date
	int getSerialNum() const; //returns the serial number
	int getLotNumber() const; //returns the lot number
	string getManufactDate() const; //returns the date the part was manufactored
	void printDetails() const; //prints the details of the part

private:
	int serialNum; //holds a part's serial number
	int lotNum; //holds the part's lot number
	string manufactDate; //holds the date the part was manufactored
};

Inventory::Inventory() //default constructor to set the members
{
	serialNum = 0;
	lotNum = 0;
	manufactDate = "";
}

Inventory::Inventory(int s, int l, string d) //default constructor with parameters to set the members
{
	serialNum = s;
	lotNum = l;
	manufactDate = d;
}

void Inventory::setSerialNum(int s) //sets the serial number
{
	serialNum = s;
}

void Inventory::setLotNum(int l) //sets the lot number
{
	lotNum = l;
}

void Inventory::setManufactDate(string d) //sets the date manufactored
{
	manufactDate = d;
}

int Inventory::getSerialNum() const //gets the serial number
{
	return serialNum;
}

int Inventory::getLotNumber() const //gets the lot number
{
	return lotNum;
}

string Inventory::getManufactDate() const //gets the date manufactored
{
	return manufactDate;
}

void Inventory::printDetails() const //prints the details of the part
{
	cout << "Serial Number: " << serialNum << endl;
	cout << "Lot Number: " << lotNum << endl;
	cout << "Date Manufactored: " << manufactDate << endl;
}