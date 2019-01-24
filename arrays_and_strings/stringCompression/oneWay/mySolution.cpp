//
//  mySolution.cpp
//  oneWay
//
//  Created by LYT on 23/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution.h"
#include <iostream>
#define MAX_CHAR 256

bool isReplacement(char const *string1, char const *string2)
{
    // 0 replacement still gives true
    int i = 0; // index to loop through the string
    int diffCount = 0; // count the number of diff
    
    while(string1[i]!='\0' || string2[i]!='\0')
    {
        if (string1[i] != string2[i])
        {
            if(++diffCount > 1) return false;
        }
        i++;
    }
    
    return true;
}


void testIsReplacement()
{
    std::cout << isReplacement("pale","bale") << '\n';
    std::cout << isReplacement("pale","pble") << '\n';
    std::cout << isReplacement("pale","balep") << '\n';
    std::cout << isReplacement("pale","bal") << '\n';
    std::cout << isReplacement("pale","pale") << '\n';
}



bool isInsert(char const *originalString, char const *newString, int strLen1, int strLen2){
    
    int originalInd = 0; // index to loop through the original string
    int newInd = originalInd; // index to locate the corresponding index for newString
    int diffCount = 0; // count the number of difference found
    
    // if length differ by 1 then false immediately.
    if ((strLen2 - strLen1 > 1) || (strLen1 > strLen2)) return false;
    
    while(originalString[originalInd]!='\0'&& newString[newInd]!='\0')
    {
        // keep comparing until the first difference detected
        if (originalString[originalInd]!=newString[newInd])
        {
            // update the diffCount
            if(++diffCount > 1) return false;
            // update the newInd
            newInd++;
        }
        originalInd++;
        newInd++;
        //std::cout << originalString[originalInd] << ',' << newString[newInd] << ';';
        
    }
    
    return true;
    
}




void testIsInsert()
{
    std::cout << isInsert("apple","apples",5,6) << '\n';
    std::cout << isInsert("apple","aapple",5,6) << '\n';
    std::cout << isInsert("apple","apple",5,5) << '\n';
    std::cout << isInsert("apple","appless",5,7) << '\n';
    std::cout << isInsert("apple","applesm",5,7) << '\n';
    std::cout << isInsert("apple","apppple",5,7) << '\n';
    
}



bool isOneWay(char const *string1, char const *string2, int strLen1, int strLen2)
{
    // check if it is a replacement
    if (isReplacement(string1, string2)) return true;
    
    // check if is an insert (both way)
    if(isInsert(string1, string2, strLen1, strLen2)) return true;
    if(isInsert(string2, string1, strLen2, strLen1)) return true;
    
    // else return false
    return false;
}



void testIsOneWay()
{
    std::cout << "The following are one way\n";
    std::cout << isOneWay("apple","apples",5,6) << '\n';
    std::cout << isOneWay("apple","aapple",5,6) << '\n';
    std::cout << isOneWay("apple","apple",5,5) << '\n';
    std::cout << isOneWay("pale","ple",4,3) << '\n';
    std::cout << isOneWay("pales","pale",5,4) << '\n';
    std::cout << isOneWay("pale","bale",4,4) << '\n';
    
    std::cout << "\n ------ \nThe following are not one way\n";
    std::cout << isOneWay("apple","appless",5,7) << '\n';
    std::cout << isOneWay("apple","applesm",5,7) << '\n';
    std::cout << isOneWay("apple","apppple",5,7) << '\n';
    std::cout << isOneWay("pale","bake",4,4) << '\n';
}
