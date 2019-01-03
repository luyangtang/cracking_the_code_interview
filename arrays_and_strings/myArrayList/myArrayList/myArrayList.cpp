//
//  myArrayList.cpp
//  myArrayList
//
//  Created by LYT on 02/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "myArrayList.h"




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
template <class T>
myArrayList<T>::myArrayList(const int newArrSize)
{
	// assig the array size
	arrSize = newArrSize;
	// new array object
	arr = new T[newArrSize] {0};
	// default capacity
	capacity = newArrSize;

	// dummy codes
	std::cout << "New vector constructed ";

	// print the array
	this->print();
}



// define destructor
template <class T>
myArrayList<T>::~myArrayList()
{
	//delete arr;
	std::cout << "Object destructed\n";
}




// define pushBack()
template <class T>
void myArrayList<T>::pushBack(const T newVal)
{
	if (doubleCapacity(capacity, arrSize))
	{
		// create a new array with twice as big as arr
		T *newArr = new T[2 * capacity]{ 0 };

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

}




template <class T>
void myArrayList<T>::print()
{
	std::cout << '(';

	// print each of the entries
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << ',';
	}

	std::cout << ")\n";
}


void myArrayListTmpFunc()
{
	// to trick the linker
	myArrayList<int> al;
	al.pushBack(0);
}
