//
//  mySolution2.cpp
//  palindromePermutation
//
//  Created by LYT on 17/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution2.hpp"
#include "asciiConstants.h"
#include <iostream>


int alphabetMap(char alphabet)
{
    int mappedInt = 0;
    using namespace asciiConstants;
    if (alphabet >= MIN_LOW && alphabet <= MAX_LOW)
    {
        mappedInt = alphabet - MIN_LOW;
    }
    else if (alphabet>=MIN_CAP && alphabet <= MAX_CAP)
    {
        mappedInt = alphabet + (MIN_LOW - MIN_CAP) - MIN_LOW;
    }
    
    return mappedInt;
}


void testAlphabetMap()
{
    char const *string = "abcdefghijklmnopqrstuvwxyz";
    
    int i = 0;
    
    while(string[i])
    {
        std::cout << alphabetMap(string[i]) << ' ';
        i++;
    }
    
    std::cout << '\n';
    
    char const *string2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    i = 0;
    
    while(string2[i])
    {
        std::cout << alphabetMap(string2[i]) << ' ';
        i++;
    }
}


bool isPalindromeWord2(char const *string)
{
    int countHolder = 0;
    
    int i = 0;
    while (string[i]!='\0')
    {
        // toggle that bit
        countHolder = countHolder ^ (1 << alphabetMap(string[i]));
        i++;
    }
    
    
    
    /*
     Need to find a way to check how many 1's in the binary
     */
    
    return true;
}

