//
//  stringRotation.cpp
//  stringRotation
//
//  Created by LYT on 29/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "stringRotation.h"
#include <iostream>
#include <string>

void print(std::string str)
{
    for (auto const &ch: str)
    {
        std::cout << ch;
    }
    std::cout << ' ';
}


bool isRotation(std::string str, std::string test)
{
    using namespace std;
    int strLen = static_cast<int>(str.length());
    str.append(str);
    
    // if lengths are different, return false immediately
    if(static_cast<int>(test.length()) != strLen)
        return false;
    
    string compare = "";
    
    // for each character in the string,
    for (int i = 0; i < strLen; i++)
    {
        // populate string compare
        for (int j = i; j < strLen + i; j++)
        {
            compare.push_back(str[j]);
        }
        if (compare == test)
        {
            // a match is found so return true
            return true;
        }
        compare = "";
        
    }
    // no return found so return false
    return false;
}



void testIsRotation()
{
    std::cout << isRotation("WaterBottle","terBottleWa") << '\n';
    std::cout << isRotation("WaterBottle","rBottleWate") << '\n';
    std::cout << isRotation("Apple","ppleA") << '\n';
    
    std::cout << "------\n";
    
    std::cout << isRotation("WaterBottle","terBottleW") << '\n';
    std::cout << isRotation("WaterBottle","rBottleWata") << '\n';
    std::cout << isRotation("Apple","pplea") << '\n';
}
