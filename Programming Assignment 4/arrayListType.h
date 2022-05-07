#pragma once

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator=
        (const arrayListType<elemType>&);
    //Overloads the assignment operator
    bool isEmpty();
    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty; 
    //    otherwise, returns false.
    bool isFull();
    //Function to determine whether the list is full.
    //Postcondition: Returns true if the list is full; 
    //    otherwise, returns false.
    int listSize();
    //Function to determine the number of elements in the list
    //Postcondition: Returns the value of length.
    int maxListSize();
    //Function to determine the size of the list.
    //Postcondition: Returns the value of maxSize.
    void print() const;
    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
     //   standard output device.
    bool isItemAtEqual(int location, const elemType& item);
    //Function to determine whether the item is the same 
    //as the item in the list at the position specified by
    //Postcondition: Returns true if the list[location] 
    //    is the same as the item; otherwise, 
    //               returns false.
    void insertAt(int location, const elemType& insertItem);
    //Function to insert an item in the list at the 
    //position specified by location. The item to be inserted 
    //is passed as a parameter to the function.
    //Postcondition: Starting at location, the elements of the
    //    list are shifted down, list[location] = insertItem;,
    //    and length++;. If the list is full or location is
    //    out of range, an appropriate message is displayed.
    void insertEnd(const elemType& insertItem);
    //Function to insert an item at the end of the list. 
    //The parameter insertItem specifies the item to be inserted.
    //Postcondition: list[length] = insertItem; and length++;
    //    If the list is full, an appropriate message is 
    //    displayed.
    void removeAt(int location);
    //Function to remove the item from the list at the 
    //position specified by location 
    //Postcondition: The list element at list[location] is removed
    //    and length is decremented by 1. If location is out of 
    //    range,an appropriate message is displayed.
    void retrieveAt(int location, elemType& retItem);
    //Function to retrieve the element from the list at the  
    //position specified by location. 
    //Postcondition: retItem = list[location] 
    //    If location is out of range, an appropriate message is
    //    displayed.
    void replaceAt(int location, const elemType& repItem);
    //Function to replace the elements in the list at the 
    //position specified by location. The item to be replaced 
    //is specified by the parameter repItem.
    //Postcondition: list[location] = repItem 
    //    If location is out of range, an appropriate message is
    //    displayed.
    void clearList();
    //Function to remove all the elements from the list. 
    //After this operation, the size of the list is zero.
    //Postcondition: length = 0;
    int seqSearch(const elemType& item);
    //Function to search the list for a given item. 
    //Postcondition: If the item is found, returns the location 
    //    in the array where the item is found; otherwise,
    //    returns -1.
    void insert(const elemType& insertItem);
    //Function to insert the item specified by the parameter 
    //insertItem at the end of the list. However, first the
    //list is searched to see whether the item to be inserted 
    //is already in the list. 
    //Postcondition: list[length] = insertItem and length++
    //     If the item is already in the list or the list
    //     is full, an appropriate message is displayed.
    void remove(const elemType& removeItem);
    //Function to remove an item from the list. The parameter 
    //removeItem specifies the item to be removed.
    //Postcondition: If removeItem is found in the list,
    //      it is removed from the list and length is 
    //      decremented by one.

    arrayListType(int size = 100);
    //constructor
    //Creates an array of the size specified by the 
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0, 
    //    and maxSize = size

    arrayListType(const arrayListType<elemType>& otherList);
    //copy constructor

    ~arrayListType();
    //destructor
    //Deallocates the memory occupied by the array.

    void selectionSort(); 
    void insertionSort();
    void shellSort();
    void quickSort();
    void medianQuickSort();

protected:
    elemType* list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list

    void swap(int first, int second); //swaps two positions in the list
    int minLocation(int first, int last); //returns the min location 
    int partition(int first, int last); //partitions the list for the quicksort function
    int medianPartition(int first, int last); //partitions the list for the quicksort function with median
    void recQuickSort(int first, int last); //recursive quicksort
    void medianRecQuickSort(int first, int last); //recursive median quicksort
    void intervalInsertionSort(int begin, int inc, int& comp, int& numOfItemMov); //interval insertion sort
};

template <class elemType> //returns if the list is empty
bool arrayListType<elemType>::isEmpty()
{
    return (length == 0);
}

template <class elemType> //returns if the list is full
bool arrayListType<elemType>::isFull()
{
    return (length == maxSize);
}

template <class elemType> //returns the list size
int arrayListType<elemType>::listSize()
{
    return length;
}

template <class elemType> //returns the max size of the list
int arrayListType<elemType>::maxListSize()
{
    return maxSize;
}

template <class elemType> //prints out the contents of the list
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
}

template <class elemType> //returns if the item is equal to the item at the location
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item)
{
    return(list[location] == item);
}

template <class elemType> //inserts the item at a specific location
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
        << "is out of range" << endl;
    else
        if (length >= maxSize)  //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];   //move the elements down

            list[location] = insertItem;  //insert the item at the 
                                          //specified position

            length++;     //increment the length
        }
} //end insertAt

template <class elemType> //inserts an item at the end of the list
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{

    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem;   //insert the item at the end
        length++;   //increment the length
    }
} //end insertEnd

template <class elemType> //removes the item at a specific location
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i + 1];

        length--;
    }
} //end removeAt

template <class elemType> //retrieves the item at a specific location
void arrayListType<elemType>::retrieveAt
(int location, elemType& retItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
        << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt


template <class elemType> //replaces the item at a specific location with another item
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
        << "out of range." << endl;
    else
        list[location] = repItem;

} //end replaceAt

template <class elemType> //clears the contents of the list by setting the size to zero
void arrayListType<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType> //sequentially searches the list for an item
int arrayListType<elemType>::seqSearch(const elemType& item)
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++) //iterates sequentially through the list
        if (list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc; //returns the location of the list
    else
        return -1;
} //end seqSearch

template <class elemType> //inserts an item into the list in no particular order
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;

    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and 
                                //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)    //the item to be inserted 
                          //does not exist in the list
            list[length++] = insertItem;
    }
} //end insert

template<class elemType> //removes a specific item from the list
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
            << endl;
    }
} //end remove

template <class elemType> //default constructor with a size parameter
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
            << "an array of size 100. " << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType> //destructor to delete the list after it goes out of scope
arrayListType<elemType>::~arrayListType()
{
    delete[] list;
}


template <class elemType> //copy constructor
arrayListType<elemType>::arrayListType
(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);         //terminate if unable to allocate
                                  //memory space

    for (int j = 0; j < length; j++)  //copy otherList
        list[j] = otherList.list[j];
} //end copy constructor

template <class elemType> //overloads the assignment operator
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
    if (this != &otherList)   //avoid self-assignment
    {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];  //create the array
        assert(list != NULL);   //if unable to allocate memory 
                                //space, terminate the program 
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }

    return *this;
}

template <class elemType> //sorts the list using the selection method
void arrayListType<elemType>::selectionSort()
{
    int minIndex;

    for (int loc = 0; loc < length - 1; loc++)
    {
        minIndex = minLocation(loc, length - 1);
        swap(loc, minIndex);
    }
}

template <class elemType> //returns the min location of the list within a range
int arrayListType<elemType>::minLocation(int first, int last)
{
    int minIndex;

    minIndex = first;

    for (int loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
} //end minLocation

template <class elemType> //swaps two items in the list
void arrayListType<elemType>::swap(int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}//end swap

template <class elemType> //sorts the list using the insertion method
void arrayListType<elemType>::insertionSort()
{
    int firstOutOfOrder, location;
    elemType temp;

    int comp = 0;
    int numOfItemMov = 0;

    for (firstOutOfOrder = 1; firstOutOfOrder < length;
        firstOutOfOrder++)
    {
        comp++;
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;

                comp++;
                numOfItemMov++;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }

    cout << "Insertion sort comparisons: " << comp << endl;
    cout << "Insertion sort number of item moves: " << numOfItemMov << endl;
} //end insertionSort


template <class elemType> //interval selection sort used for the shell sort
void arrayListType<elemType>::intervalInsertionSort(int begin, int inc,
    int& comp, int& numOfItemMov)
{
    int location;
    elemType temp;

    for (int firstOutOfOrder = begin + inc; firstOutOfOrder < length;
        firstOutOfOrder = firstOutOfOrder + inc)
    {
        comp++;

        if (list[firstOutOfOrder] < list[firstOutOfOrder - inc])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;

            do
            {
                list[location] = list[location - inc];
                location = location - inc;
                comp++;
                numOfItemMov++;
            } while (location > begin && list[location - inc] > temp);

            list[location] = temp;
        }
    }
} //end intervalInsertionSort

template <class elemType> //sorts the list using the shell method
void arrayListType<elemType>::shellSort()
{
    int inc;
    int comp = 0;
    int numOfItemMov = 0;

    for (inc = 1; inc < (length - 1) / 9; inc = 3 * inc + 1);

    do
    {
        for (int begin = 0; begin < inc; begin++)
            intervalInsertionSort(begin, inc, comp, numOfItemMov);

        inc = inc / 3;
    } while (inc > 0);

    cout << "Shell sort comparisons: " << comp << endl;
    cout << "Shell sort number of item moves: " << numOfItemMov << endl;

} //end shellSort

template <class elemType> //partitions the list for the quicksort
int arrayListType<elemType>::partition(int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(first, (first + last) / 2); //pivot is the middle element

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++) //iterates through the list, finding all items less than the pivot
    {
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index); 
        }
    }

    swap(first, smallIndex); //swaps the pivot back to its original position

    return smallIndex; //returns the index of the last item smaller than the pivot
}

template <class elemType> //partitions the list for the median quicksort
int arrayListType<elemType>::medianPartition(int first, int last)
{
    elemType pivot;

    int index, smallIndex, median, middle;

    middle = (first + last) / 2; //middle is set

    int tempList[3] = { first, middle, last }; //creates a temp list to store the first, middle, and last elements
    sort(tempList, tempList + 3); //sorts the temp list
    median = tempList[1]; //since there are 3 items in the list, the median of the first, middle, and last elements will
                          //be at index 1

    swap(first, median); //the pivot is set to the median

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++) //iterates through the list, finding all items less than the pivot
    {
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }

    swap(first, smallIndex); //swaps the pivot back to its original position

    return smallIndex; //returns the index of the last item smaller than the pivot 
}

template <class elemType> //recursively quicksorts the list
void arrayListType<elemType>::recQuickSort(int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(first, last); //finds the pivot location
        recQuickSort(first, pivotLocation - 1); //sorts the first half of the list
        recQuickSort(pivotLocation + 1, last); //sorts the second half of the list
    }
}

template<class elemType> //recursively quicksorts the list for median sort
void arrayListType<elemType>::medianRecQuickSort(int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = medianPartition(first, last); //finds the pivot location
        recQuickSort(first, pivotLocation - 1); //sorts the first half of the list
        recQuickSort(pivotLocation + 1, last); //sorts the second half of the list
    }
}

template <class elemType> //function to call the recursive quicksort
void arrayListType<elemType>::quickSort()
{
    recQuickSort(0, length - 1);
}

template<class elemType> //function to call the median quicksort
void arrayListType<elemType>::medianQuickSort()
{
    medianRecQuickSort(0, length - 1);
}
