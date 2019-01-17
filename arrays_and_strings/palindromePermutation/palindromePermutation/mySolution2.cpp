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
    using namespace asciiConstants;
    
    int countHolder = 0;
    
    int i = 0;
    while (string[i]!='\0')
    {
        // toggle that bit, ignore special characters
        
        if ((string[i] >= MIN_LOW && string[i] << MAX_LOW) ||
            (string[i] >= MIN_CAP && string[i] << MAX_CAP))
        countHolder = countHolder ^ (1 << alphabetMap(string[i]));
        i++;
    }
    
    if ((checkExactlyOneNonZero(countHolder) || countHolder == 0))
    {
        std::cout << 1 << '\n';
        return true;
    }
    else
    {
        std::cout << 0 << '\n';
        return false;
    }
}


bool checkExactlyOneNonZero(int bitInt)
{
    return ((bitInt & (bitInt-1)) == 0);
}



void testCheckExactlyOneNonZero()
{
    std::cout << checkExactlyOneNonZero(2) << '\n';
    std::cout << checkExactlyOneNonZero(3) << '\n';
    std::cout << checkExactlyOneNonZero(4) << '\n';
    std::cout << checkExactlyOneNonZero(5) << '\n';
}
