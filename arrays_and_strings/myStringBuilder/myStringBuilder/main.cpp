//
//  main.cpp
//  myStringBuilder
//
//  Created by LYT on 07/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>

class StringBuilder
{
private:
    char *string;
    int length;
    int capacity;
    
public:
    
    // constructor
    StringBuilder(char baseStr[]);
    
    // destructor
    ~StringBuilder();
    
    // print
    void print();
    
    // append
    void append(char const *appendStr);
};

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
    for (int i = 0; i < length; i++)
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
            capacity *= 2;
            
            // have a new array with 2*capacity
            char *newString = new char[capacity];
            
            // copy everything from string to newString
            for (int j = 0; j < length; j++)
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
        // std::cout << appendStr[i];
        i++;
    }
}


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



int main() {
    
    char base[] = "HelloWorld!!!!!!!";
    StringBuilder string(base);
    string.append("WorldWorldWorldWorld");
    string.print();
    return 0;
}
