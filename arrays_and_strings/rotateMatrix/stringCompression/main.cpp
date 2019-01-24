//
//  main.cpp
//  stringCompression
//
//  Created by LYT on 23/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "mySolution.h"
#include <string>


int main() {
    
    myString str("aabcccccaaa");
    myString cmpStr = str.compress();
    cmpStr.print();
    
    return 0;
}
