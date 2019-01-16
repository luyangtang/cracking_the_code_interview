//
//  mySolution.cpp
//  URLify
//
//  Created by LYT on 16/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution.hpp"
#include <iostream>



char const* urlify(char const *string, int stringLen)
{
    /* My approach is to compute this mathematically.
     suppose there are spaces at ith, jth and kth
     then copy
     before 1st space: 0, 1, 2, ..., i-1 copied[index] = original[index]
     ...
     before ith space: ((i-1) + i*3), ..., ((j-1)  + i*3)
     */
    
    int i = 0; // index to loop through the string
    int spaceCount = 0;
    
    // create a array to record the index of space
    int *spaceHolder = new int[stringLen];
    
    
    // get the location for all spaces
    while (string[i]!='\0')
    {
        //        std::cout << string[i] << '\n';
        if (string[i]==' ' && string[i-1]!=' ')
        {
            //            std::cout << "There is a space here at  " << i << "!\n";
            spaceHolder[spaceCount] = i;
            spaceCount++;
        }
        i++;
    }
    spaceCount--; // final one does not count
    
    
    // create a new character array to hold urlified string
    char *url = new char[stringLen] {0};
    
    
    // start with copying and pasting
    i = 0; // reset the index
    spaceCount = 0; // jth space found
    int spaceInd = spaceHolder[spaceCount];
    //    std::cout << spaceInd;
    
    for(i; i < stringLen; i++)
    {
        // before the space, copy as usual.
        // url's index will be i + (3-1)*spaceCount ahead
        // at the space replace with '%20'
        if(i < spaceInd && spaceInd!=0)
        {
            *(url + i + 2*spaceCount) = string[i];
            //            std::cout << url[i] << ' ';
            //            spaceInd = spaceHolder[spaceCount++];
        }
        else
        {
            *(url+ i + 2*spaceCount) = '%';
            *(url+ i + 2*spaceCount + 1) = '2';
            *(url+ i + 2*spaceCount + 2) = '0';
            spaceInd = spaceHolder[++spaceCount];
        }
        
    }
    
    return url;
}


void printString(char const *string)
{
    int i = 0;
    while(string[i]!='\0')
    {
        std::cout << string[i++];
    }
    std::cout << '\n';
}
