//
//  myHashTable.h
//  myHashTable
//
//  Created by LYT on 03/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef myHashTable_h
#define myHashTable_h
#define MAX_INDEX 1000
#include <string>

unsigned hashFunction(const char *s, const int maxIndex = MAX_INDEX);

class myHashTable
{
private:
    int max_index; // the size of the hash table
    bool *defined; // an array keep track of keys defined
public:
    int *arr;
    
    // constructor
    myHashTable(unsigned _max_index = MAX_INDEX);
    
    // destructor
    ~myHashTable();
    
    int getValue(const std::string str);
    
    void set(const std::string key, const int val);
    
    /* to be overloaded by operator [] */
    int operator [] (const std::string str);
};



#endif /* myHashTable_h */
