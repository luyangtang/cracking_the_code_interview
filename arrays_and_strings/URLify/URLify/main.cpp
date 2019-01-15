//
//  main.cpp
//  URLify
//
//  Created by LYT on 15/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>

int main() {
    char const *string = "Mr John Smith        "; // assume there are enough space to hold %20
    
    /* My approach is to compute this mathematically.
     suppose there are spaces at ith, jth and kth
     then copy
     before 1st space: 0, 1, 2, ..., i-1 copied[index] = original[index]
     ...
     before ith space: ((i-1) + i*3), ..., ((j-1)  + i*3)
     */
    
}
