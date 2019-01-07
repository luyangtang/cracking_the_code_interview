//
//  StringBuilder.h
//  myStringBuilder
//
//  Created by LYT on 07/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef StringBuilder_h
#define StringBuilder_h

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

#endif /* StringBuilder_h */
