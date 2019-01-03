
#ifndef MYARRAYLIST_H
#define MYARRAYLIST_H

void printArray(int arr[], int arrSize);

bool doubleCapacity(const int capacity, const int arrSize);

class myArrayList
{
private:
	int *arr;
	int arrSize;
	int capacity;

public:
	// constructor (default)
	myArrayList(int newArrSize = 1);

	// destructor
	~myArrayList();

	// add a new value to the vector
	void pushBack(int newVal);
};

void testPushBack();

#endif
