//
//  fixedLength.cpp
//  threeInOne
//
//  Created by LYT on 08/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "fixedLength.h"

void testTripleStacks()
{
    int arr1[] = {0,1,2,3};
    int arr2[] = {4,5,6};
    int arr3[] = {7,8};
    
    TripleStacks<int> ts(arr1,4,arr2,3,arr3,2);
    
    ts.printTgt();
    
    // test pushes
    ts.push1(4);
    ts.push2(7);
    ts.push3(9);
    ts.printTgt();
    
    // test pop
    ts.pop1();
    ts.pop2();
    ts.pop3();
    ts.printTgt();
}
