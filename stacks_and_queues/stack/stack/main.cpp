//
//  main.cpp
//  stack
//
//  Created by LYT on 02/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "stackFromArr.h"
#include "stackFromList.h"



void testLinkedList()
{
    int arr[] = {0,1,2,3,4};
    List lst(arr,5);
    lst.print();
    lst.append(5);
    lst.print();
    lst.pop();
    lst.print();
    
    std::cout << lst.peek() << '\n';
}


void testStack2()
{
    int arr[] = {0,1,2,3,4,5};
    List *lst = new List(arr,6);
    ListStack stck(lst);
    
    std::cout << stck.isEmpty() << '\n';
    
    delete lst;
    
}



int main(int argc, const char * argv[]) {
    
    testStack2();
    
    return 0;
}
