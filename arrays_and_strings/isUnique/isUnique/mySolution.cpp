//
//  mySolution.cpp
//  isUnique
//
//  Created by LYT on 07/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "mySolution.h"


bool isUnque(char const *string)
{
    int outer = 0;
    int inner = 0;
    char outerChar;
    char innerChar;
    
    // go through each character of the string
    do
    {
        outerChar = string[outer];
        inner = 0;
        
        // loop through the string again and do pairwise comparison
        do
        {
            innerChar = string[inner];
            
            if((outer!=inner) && (outerChar == string[inner]))
            {
                //std::cout << "Not Unique!\n";
                goto notUnique;
            }
            
            inner++; // iterator++
        } while(innerChar != '\0');
        
        outer++; // iterator++
        
    }while (outerChar != '\0');
    
    // if the nested while loops is to be terminated
    // use the following label for goto:
unique:
    std::cout << "Unique!\n";
    return true;
    
notUnique:
    std::cout << "Not Unique!\n";
    return false;
}


void testIsUnique()
{
    std::cout << "ABCD is " << isUnque("ABCD") << '\n';
    std::cout << "Hello World is " << isUnque("Hello World") << '\n';
    std::cout << "AAAA is " << isUnque("AAAA") << '\n';
    std::cout << "123 is " << isUnque("123") << '\n';
    std::cout << "ABCD is " << isUnque("ABCD") << '\n';
}
