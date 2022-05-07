#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arrayListType.h"

using namespace std;

int main() 
{
	//time variables to hold the starting and ending time of each sort
	clock_t medianBegin, medianEnd, normalBegin, normalEnd;

	arrayListType<int> list(10000); //creates an arrayListType variable to hold 10000 items

	for (int i = 0; i<10000; i++) //for loop to fill the array randomly with numbers from 1-10,000
	{
		list.insert((rand() % 10000) + 1);
	}

	arrayListType<int> list2(list); //creates and identical arrayListType variable used to compare the other sort

	medianBegin = clock(); //starts the time
	list.medianQuickSort(); //sorts the list using the median quick sort
	medianEnd = clock(); //ends the time

	normalBegin = clock(); //starts the time
	list2.quickSort(); //sorts the list using the normal quick sort
	normalEnd = clock(); //ends the time

	cout << "Printing the sorted list: " << endl; //prints out the sorted list
	cin.get();
	list.print();

	cout << endl; //prints out the cpu time for each sorting method
	cout << "Median quicksort CPU time: " << medianEnd - medianBegin << endl;
	cout << "Normal quicksort CPU time: " << normalEnd - normalBegin << endl;

	return 0;
}