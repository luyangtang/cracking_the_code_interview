//
//  StringBuilder.cpp
//  myStringBuilder
//
//  Created by LYT on 07/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "StringBuilder.h"
#include <iostream>



StringBuilder::~StringBuilder()
{
    
}


StringBuilder::StringBuilder(char baseStr[])
{
    string = baseStr;
    
    // calculate the length of the string
    length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    
    // initially capacity of the container is equal to length of the string
    capacity = length;
    
}


void StringBuilder::print(){
    
    // print the string at each index
    for (int i = 0; i < length + 1; i++)
    {
        std::cout << string[i];
    }
    
    // a new line
    std::cout << '\n';
}


void StringBuilder::append(char const *appendStr)
{
    // index to go through the string to be appended
    int i = 0;
    
    // proposed new length
    int newLength = length;
    
    while (appendStr[i] != '\0')
    {
        newLength++; // the new length is supposed to be increased by 1
        
        if (newLength <= capacity) // can still hold more
        {
            string[newLength] = appendStr[i];
        }
        else
        {
            // otherwise double the capacity
            //std:: cout << "The capacity has increased from " << capacity;
            capacity *= 2;
            //std:: cout << " to "<<capacity << '\n';
            
            // have a new array with 2*capacity
            char *newString = new char[capacity];
            
            // copy everything from string to newString
            for (int j = 0; j < newLength; j++)
            {
                newString[j] = string[j];
            }
            
            // add the final bit in
            newString[newLength] = appendStr[i];
            
            
            // replace the string with newString
            string = newString;
            delete [] newString;
        }
        
        length = newLength;
        
        /*
         // print the string
         this->print();
         */
        
        // std::cout << appendStr[i];
        i++;
    }
}


