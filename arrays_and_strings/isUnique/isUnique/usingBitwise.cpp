//
//  usingBitwise.cpp
//  isUnique
//
//  Created by LYT on 14/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "usingBitwise.hpp"
#include <iostream>

bool isUniqueBitwise(char const *string)
{
    int checker = 0;
    
    int i = 0; // index to go through the string
    
    int bitAtIndex = 0;
    
    while (string[i]!='\0')
    {
        // the bit of that char at i relative to a is
        bitAtIndex = string[i] - 'a';
        
        // In 32-bit integer, turn that on (i.e. shift 1 to right by that many steps
        if (checker & (1 << bitAtIndex))
        {
            // compared with checker bit by bit. if it is 1 then it means that bit has been updated alreay
            std::cout << "Not unique!";
            return false;
        }
        
        // otherwise turn that bit on.
        checker = checker | (1 << bitAtIndex);
        //        std::cout << checker;
        
        // i incremented by 1
        i++;
    }
    std::cout << "Unique!";
    return true;
}



void testIsUniqueBitwise()
{
    char const *string1 = "helloworld"; // only works for a - z
    std::cout << string1 << ' is ';
    isUniqueBitwise(string1);
    std::cout << '\n';
    
    char const *string2 = "abc"; // only works for a - z
    std::cout << string2 << ' is ';
    isUniqueBitwise(string2);
    std::cout << '\n';
    
    char const *string3 = "aaaaaaaaaaa"; // only works for a - z
    std::cout << string3 << ' is ';
    isUniqueBitwise(string3);
    std::cout << '\n';
}
