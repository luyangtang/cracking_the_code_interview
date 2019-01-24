//
//  oneWay.cpp
//  oneWay
//
//  Created by LYT on 24/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "oneWay.h"
#include <iostream>
#include <string>



bool oneEditAway(std::string string1, std::string string2)
{
    using namespace std;
    
    int len1 = static_cast<int>(string1.length());
    int len2 = static_cast<int>(string2.length());
    
    // if lengths differ by more than one then false for sure
    if (len1 - len2 > 1|| len1 - len2 < -1)
    {
        return false;
    }
    
    // define shorter and loner
    string shorter = len1 > len2 ? string2:string1;
    string longer = len1 <= len2 ? string2:string1;
    
    // indices to loop through the strings
    int shorterInd = 0;
    int longerInd = 0;
    
    // to record if diff has been spot
    bool foundDiff = false;
    
    // start looking for diff
    while(shorterInd < static_cast<int>(shorter.length()) && longerInd < static_cast<int>(longer.length()))
    {
        // if a difference is found
        if (shorter[shorterInd] != longer[longerInd])
        {
            if (foundDiff) return false; // only one diff is allowed
            
            // otherwise toggle foundDiff
            foundDiff = true;
            
            // if it is a potential replacement then let shortInd move by 1
            if (static_cast<int>(shorter.length()) == static_cast<int>(longer.length()))
            {
                shorterInd++;
            }
        }
        else
        {
            // if matches, compare the next position
            shorterInd++;
        }
        longerInd++; // longer string always move by 1
    }
    
    // if no further diff found, return true
    return true;
}


void testOneEditAway()
{
    std::cout << "The following are one way\n";
    std::cout << oneEditAway("apple","apples") << '\n';
    std::cout << oneEditAway("apple","aapple") << '\n';
    std::cout << oneEditAway("apple","apple") << '\n';
    std::cout << oneEditAway("pale","ple") << '\n';
    std::cout << oneEditAway("pales","pale") << '\n';
    std::cout << oneEditAway("pale","bale") << '\n';
    
    std::cout << "\n ------ \nThe following are not one way\n";
    std::cout << oneEditAway("apple","appless") << '\n';
    std::cout << oneEditAway("apple","applesm") << '\n';
    std::cout << oneEditAway("apple","apppple") << '\n';
    std::cout << oneEditAway("pale","bake") << '\n';
}
