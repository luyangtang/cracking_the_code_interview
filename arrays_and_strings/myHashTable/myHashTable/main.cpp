//
//  main.cpp
//  myHashTable
//
//  Created by LYT on 03/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>

unsigned hashFunction(const char *s)
{
    // sum up the char (int)
    unsigned hash = 0;
    
    while(*s)
    {
        hash += *(s++);
    }
    
    return hash;
}

void testHashFunction()
{
    std::cout << hashFunction("ab") << '\n';
    std::cout << hashFunction("ba") << '\n';
    std::cout << hashFunction("abc") << '\n';
}


int main() {
    // insert code here...
    testHashFunction();
    return 0;
}
