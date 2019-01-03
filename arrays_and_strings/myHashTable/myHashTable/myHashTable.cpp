//
//  myHashTable.cpp
//  myHashTable
//
//  Created by LYT on 03/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "myHashTable.h"
#include <stdio.h>
#include <string>
#include <iostream>
#define MAX_INDEX 1000

unsigned hashFunction(const char *s, const int maxIndex)
{
    // sum up the char (int)
    unsigned hash = 0;
    
    while(*s)
    {
        hash += *(s++);
    }
    
    return hash % maxIndex;
}

// constructor
myHashTable::myHashTable(unsigned _max_index)
{
    max_index = _max_index;
    // initial definition for arr and defined
    arr = new int[max_index]{0};
    defined = new bool[max_index]{0}; // by default none is defined
    
    std::cout << "Hash table created.\n";
};
    

// destructor
myHashTable::~myHashTable()
{
    delete arr;
    std::cout << "Hash table destructed.\n";
};
    
int myHashTable::getValue(const std::string str)
{
    unsigned hash = hashFunction(str.c_str());
    return arr[hash];
}
    
void myHashTable::set(const std::string key, const int val)
{
    unsigned hash = hashFunction(key.c_str());
    // check if the key has been defined
    if (defined[hash])
    {
        /*
         This part should be replaced by a linked list
         */
        std::cout << "the key has been defined \n";
    }
    else
    {
        arr[hash] = val;
        defined[hash] = 1; // mark 1 at this place
    }
}
    
int myHashTable::operator [] (const std::string str)
{
    return getValue(str);
}
