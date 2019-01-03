
#include <string>
#include "tests.h"
#include "myArrayList.h"



void testInt()
{
	myArrayList<int> al(2);
	for (int i = 3; i < 20; i++)
	{
		al.pushBack(i);
		al.print();
	}

}




