//
//  tests.cpp
//  myHashTable
//
//  Created by LYT on 03/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "tests.h"
#include "myHashTable.h"
#include <iostream>
#define MAX_INDEX 1000

void testHashFunction()
{
    std::cout << hashFunction("John",MAX_INDEX) << '\n';
    std::cout << hashFunction("ba",MAX_INDEX) << '\n';
    std::cout << hashFunction("abc",MAX_INDEX) << '\n';
}


void testHashTable()
{
    // the capacity of the array
    unsigned maxIndex = 1000;
    
    // create the array
    int arr[maxIndex];
    
    // define the key and value
    std::string str = "John";
    const char *s = str.c_str();
    int val = 23;
    
    // convert the key to index via hash function
    arr[hashFunction(s, maxIndex)] = val;
    
    std::cout << arr[hashFunction(s, maxIndex)];
}


void testMyHashTableOverload()
{
    myHashTable ht;
    ht.set("ab", 23);
    ht.set("cd", 76);
    std::cout << ht.getValue("ab") << '\n';
    std::cout << ht.getValue("cd") << '\n';
    std::cout << ht["ab"] << '\n';
    std::cout << ht["cd"] << '\n';
}


void testCollision()
{
    myHashTable ht;
    ht.set("ab", 23);
    std::cout << ht["ab"] << '\n';
    ht.set("ba", 76);
    std::cout << ht["ba"] << '\n';
}
