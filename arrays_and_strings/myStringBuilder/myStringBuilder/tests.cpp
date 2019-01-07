//
//  tests.cpp
//  myStringBuilder
//
//  Created by LYT on 07/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "tests.h"
#include "StringBuilder.h"

void manualConcat()
{
    // concatenate two char *
    /* using char const * rather than char * because
     ISO C++11 does not allow conversion from string literal to 'char *' */
    char baseStr[20] = "Hello";
    char const *appendStr = " World";
    
    int i = 0; // index that iterates through a char const * string
    while(appendStr[i]!='\0')
    {
        baseStr[5+i] = appendStr[i];
        i++;
    }
    
    i = 0;
    while (baseStr[i] != '\0')
    {
        std::cout << baseStr[i];
        i++;
    }
    
    std::cout << '\n';
    std::cout << "String has length " << i << '\n';
}


void testMyStringBuilder()
{
    char base[] = "Hello";
    StringBuilder string(base);
    string.append("WorldWorldWorldWorld");
    string.print();
}
