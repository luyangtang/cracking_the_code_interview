//
//  main.cpp
//  palindromePermutation
//
//  Created by LYT on 17/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "asciiConstants.h"
//#include "mySolution.hpp"
#include "mySolution2.hpp"



int main() {
    
    /* during my first attempt, seems we only need to look at alphabets,
     in particular, lower case alphabets
     need a function to map character to 0 to 25
     */
    
//    isPalindromeWord2("hello");
    
    
    std::cout << "the following words are Pardindrome\n";
    isPalindromeWord2("R...acecar");
    isPalindromeWord2("repape!r");
    isPalindromeWord2("soLos");
    isPalindromeWord2("ra,cecar");
    isPalindromeWord2("stats");
    isPalindromeWord2("reddEr");
    isPalindromeWord2("aaaa   Aaaaaa aaaa");
    isPalindromeWord2("00000000000");
    isPalindromeWord2("wasitacatisaW");
    
    std::cout << "\nthe following words are not Pardindrome\n";
    isPalindromeWord2("My");
    isPalindromeWord2("hello  world");
    isPalindromeWord2("it!hinkyouaRewrong");
    isPalindromeWord2("callmema.ybe");
    isPalindromeWord2("M aybe");
    isPalindromeWord2("yoU");
    isPalindromeWord2("It");
    isPalindromeWord2("102"); // does not work for numbers
    
    
    
    
    
    return 0;
    
}
