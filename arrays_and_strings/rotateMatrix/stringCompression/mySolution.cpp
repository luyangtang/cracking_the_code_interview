//
//  mySolution.cpp
//  stringCompression
//
//  Created by LYT on 23/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution.h"
#include <iostream>
#include <string>

std::string stringCompression(std::string str)
{
    using namespace std;
    string cmpStr; // compressed string
    
    int chCount = 1;
    cmpStr.push_back(str[0]);
    for (int i = 1; i < str.length() + 1; i++)
    {
        if(str[i] == str[i-1])
        {
            // if equal then add 1 to the counter
            chCount++;
        }
        else
        {
            // push the counter to the string
            cmpStr.append(to_string(chCount));
            
            // clear the counter
            chCount = 1;
            
            // push the next alphabet to the string
            cmpStr.push_back(str[i]);
        }
    }
    
    return cmpStr;
}



myString::myString(std::string str_): str(str_)
{
}


// compression method
myString myString::compress()
{
    myString cmpStr(stringCompression(str));
    return cmpStr;
}
    

// print method
void myString::print()
{
    for (auto ch:str)
    {
        std::cout << ch;
    }
    std::cout << '\n';
}
