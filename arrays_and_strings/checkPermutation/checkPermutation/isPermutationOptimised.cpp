//
//  isPermutationOptimised.cpp
//  checkPermutation
//
//  Created by LYT on 15/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "isPermutationOptimised.hpp"
#include <iostream>
#define MAX_CHAR 256


bool isPermutationOptimised(char const *string1, char const *string2)
{
    int countBase[MAX_CHAR] = {0};
    
    int i = 0; // index to go through the string
    while (string1[i]!='\0')
    {
        countBase[string1[i++]]++;
    }
    
    i = 0; // reset the index
    
    while (string2[i]!='\0')
    {
        countBase[string2[i++]]--;
    }
    
    for (int j = 0; j < MAX_CHAR; j++)
    {
        if (countBase[j] != 0)
        {
            std::cout << "Not permutation\n";
            return false;
        }
    }
    
    std::cout << "Are permutation\n";
    return true;
}



void testIsPermutationOptimised()
{
    isPermutationOptimised("Hello", "World");
    isPermutationOptimised("Hello", "elloH");
    isPermutationOptimised("aaaaaaaaaa", "aa");
    isPermutationOptimised("123", "World");
}
