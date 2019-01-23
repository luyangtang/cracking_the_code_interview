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



bool isInsert(char const *originalString, char const *newString){
    
    int originalInd = 0; // index to loop through the original string
    int newInd = originalInd; // index to locate the corresponding index for newString
    int diffCount = 0; // count the number of difference found
    
    while(originalString[originalInd]!='\0'|| newString[newInd]!='\0')
    {
        // keep comparing until the first difference detected
        if (originalString[originalInd]!=newString[newInd])
        {
            if(originalString[originalInd]=='\0') originalInd--;
            // update the diffCount
            if(++diffCount > 1) return false;
            // update the newInd
            newInd++;
        }
        originalInd++;
        newInd++;
        std::cout << originalString[originalInd] << ',' << newString[newInd] << ';';
        
    }
    
    return true;
    
}
