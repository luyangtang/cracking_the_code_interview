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
    
    using namespace std;
    
    string str = "aabcccccaaa";
    string cmpStr; // compressed string
    
    int chCount = 0;
    cmpStr[0] = str[0];
    for (int i = 1; i < str.length(); i++)
    {
        if(str[i] == str[i-1])
        {
            // if equal then add 1 to the counter
            chCount++;
        }
        else
        {
            // push the counter to the string
            str.push_back(chCount);
            
            // clear the counter
            chCount = 0;
            
            // push the next alphabet to the string
            str.push_back(str[i]);
        }
    }
    
    
    // print the string
    for (int i = 1; i < str.length(); i++)
    {
        cout << str[i];
    }
    cout << '\n';
    
    return 0;
}
