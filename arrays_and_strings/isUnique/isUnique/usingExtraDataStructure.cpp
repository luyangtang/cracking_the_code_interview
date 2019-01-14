//
//  usingExtraDataStructure.cpp
//  isUnique
//
//  Created by LYT on 14/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "usingExtraDataStructure.hpp"
#include <iostream>
#define MAX_CHAR 256

bool isUniqueExtraData(char const *string)
{
    char occurance[MAX_CHAR] = {0}; //bool array be to acount occurance
    
    int i = 0; // index to go through the string
    
    while (string[i]!='\0')
    {
        // check if length has exceeded MAX_CHAR
        if (i > 256)
        {
            std::cout << "Not unique!";
            return false;
        }
        
        
        // check if that char has occurred already
        if (occurance[string[i]] == 1)
        {
            std::cout << "Not unique!";
            return false;
        }
        
        // i is incremented by 1
        occurance[string[i++]] = 1;
        
    }
    std::cout << "Unique!";
    return true;
}


void testIsUniqueExtraData()
{
    char const *string1 = "Hello world!";
    std::cout << string1 << " is ";
    isUniqueExtraData(string1);
    std::cout<<'\n';
    
    char const *string2 = "aaaaaaaaaaaaaaaa";
    std::cout << string2 << " is ";
    isUniqueExtraData(string2);
    std::cout<<'\n';
    
    char const *string3 = "abcABC";
    std::cout << string3 << " is ";
    isUniqueExtraData(string3);
    std::cout<<'\n';
    
    char const *string4 = "abc";
    std::cout << string4 << " is ";
    isUniqueExtraData(string4);
    std::cout<<'\n';
}
