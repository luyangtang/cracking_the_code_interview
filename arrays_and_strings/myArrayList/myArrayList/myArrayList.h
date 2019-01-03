
#ifndef MYARRAYLIST_H
#define MYARRAYLIST_H

bool doubleCapacity(const int capacity, const int arrSize);

template <class T>
class myArrayList
{
private:
	T *arr;
	int arrSize;
	int capacity;

public:
	// constructor (default)
	myArrayList(const int newArrSize = 1);

	// destructor
	~myArrayList();

	// add a new value to the vector
	void pushBack(const T newVal);

	// print the array
	void print();
};



#endif