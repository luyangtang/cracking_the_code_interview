//
//  mySolution.cpp
//  checkPermutation
//
//  Created by LYT on 14/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution.hpp"
#include <iostream>
#include <utility>
#include <string>


bool isPermutation(std::string string1, std::string string2)
{
    using namespace std;
    
    // sort both strings and compare
    int len1 = string1.length();
    int len2 = string2.length();
    
    if (len1 == len2)
    {
        sort(string1.begin(),string1.end());
        sort(string2.begin(),string2.end());
        
        if(string1 == string2)
        {
            std::cout << "Permutation!\n";
            return true;
        }
    }
    
    std::cout << "Not permutation\n";
    return false;
}


void testMySolution()
{
    isPermutation("Hello","elloH");
    isPermutation("Hello","ello");
    isPermutation("Hello","abcde");
}
