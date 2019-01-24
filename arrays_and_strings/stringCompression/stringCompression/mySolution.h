//
//  mySolution.hpp
//  stringCompression
//
//  Created by LYT on 23/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h

#include <stdio.h>
#include <string>

std::string stringCompression(std::string str);

class myString
{
private:
    std::string str;
    
public:
    // constructor
    myString(std::string str_);
    
    // compression method
    myString compress();
    
    // print method
    void print();
};

#endif /* mySolution_h */
