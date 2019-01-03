//
//  main.cpp
//  myArrayList
//
//  Created by LYT on 02/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//



#include <iostream>
#include "myArrayList.h"


void printArray(int arr[], int arrSize)
/* this function prints out the array in one line
separated by whitespace */

{
	std::cout << '(';
	// print out each element sequentially
	for (int i = 0; i < arrSize; i++)
		std::cout << arr[i] << ',';
	// break the line at the end
	std::cout << ")\n";
}


bool doubleCapacity(const int capacity, const int arrSize)
/* Decide if adding an element will exceed the capacity
returns yes if there is a need to double capacity */
{
	if (arrSize + 1 > capacity)
		return true;
	else
		return false;
}




// define constructor
myArrayList::myArrayList(int newArrSize)
{
	// assig the array size
	arrSize = newArrSize;
	// new array object
	arr = new int[newArrSize] {0};
	// default capacity
	capacity = newArrSize;

	// dummy codes
	std::cout << "New vector constructed ";
	printArray(arr, arrSize);
}

// define destructor
myArrayList::~myArrayList()
{
	//delete arr;
	std::cout << "Object destructed\n";
}

// define pushBack()
void myArrayList::pushBack(int newVal)
{
	if (doubleCapacity(capacity, arrSize))
	{
		// create a new array with twice as big as arr
		int *newArr = new int[2 * capacity]{ 0 };

		// copy all existing elements to the new array.
		for (int i = 0; i < arrSize; i++)
		{
			newArr[i] = arr[i];
		}

		// delete arr
		delete arr;

		// replace arr by newArr
		arr = newArr;

		// update capacity
		capacity *= 2;
	}

	// add the new value
	arr[arrSize] = newVal;

	// update arrSize
	arrSize++;

	// print the array
	printArray(arr, arrSize);
}


void testPushBack()
{
	myArrayList al(2);
	for (int i = 3; i < 20; i++)
	{
		al.pushBack(i);
	}
}
