//
//  mySolution2.cpp
//  checkPermutation
//
//  Created by LYT on 15/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution2.hpp"
#include <iostream>

#define MAX_CHAR 256

bool isPermutation(char const *string1, char const *string2)
{
    int countBase1[MAX_CHAR] = {0};
    int countBase2[MAX_CHAR] = {0};
    
    
    int i = 0; // index to loop through the string
    
    while (string1[i]!='\0')
    {
        countBase1[string1[i++]]++;
    }
    
    i = 0; // reset the index for string2
    while (string1[i]!='\0')
    {
        countBase2[string2[i++]]++;
    }
    
    for (int j = 0; j < MAX_CHAR; j++)
    {
        if (countBase1[j] != countBase2[j])
        {
            std::cout << "Not permutation!\n";
            return false;
        }
    }
    
    std::cout << "are permutation!\n";
    return true;
}



void testIsPermute()
{
    isPermutation("Hello", "World");
    isPermutation("Hello", "elloH");
    isPermutation("aaaaaaaaaa", "aa");
    isPermutation("123", "World");
}
