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
    arr = new int[max_index]{0};
    std::cout << "Hash table created.\n";
};
    

// destructor
myHashTable::~myHashTable()
{
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
    arr[hash] = val;
}
    
int myHashTable::operator [] (const std::string str)
{
    return getValue(str);
}
