//
//  usingSort.cpp
//  isUnique
//
//  Created by LYT on 11/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "usingSort.hpp"
#include <iostream>

bool isUnique2(char string[], size_t stringLen)
{
    for (int i = 0; i < stringLen - 1; i++)
    {
        //        std::cout << string[i] << ' ' << string[i+1];
        //        std::cout << '\n';
        if (string[i] == string[i+1])
        {
            std::cout << "is not unque!\n";
            return false;
        }
    }
    std::cout << "is unique!\n";
    return true;
}

void testIsUnique2()
{
    char string[] = "Hello world!";
    size_t stringLen;
    stringLen = sizeof(string)/sizeof(char);
    std::cout << string << ' ';
    isUnique2(string, stringLen);
    
    
    char string2[] = "kkkkkkk";
    size_t stringLen2;
    stringLen2 = sizeof(string2)/sizeof(char);
    std::cout << string2 << ' ';
    isUnique2(string2, stringLen2);
    
    char string3[] = "abcde";
    size_t stringLen3;
    stringLen3 = sizeof(string3)/sizeof(char);
    std::cout << string3 << ' ';
    isUnique2(string3, stringLen3);
}
