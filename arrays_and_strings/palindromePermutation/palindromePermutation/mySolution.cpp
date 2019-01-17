//
//  mySolution.cpp
//  palindromePermutation
//
//  Created by LYT on 17/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mySolution.hpp"
#include "asciiConstants.h"
#include <iostream>


bool isPalindromeWord(char const *string)
{
    // check if a simple word is palindrome
    // word: without special characters
    // supports capitals
    using namespace asciiConstants;
    
    // a counter array to hold the count for each character
    int *counter = new int[MAX_CHAR]{0};
    
    // a counter of number of odd numbers in counter
    int oddCount = 0;
    
    char currentChar = {0};
    // go through each char of the string and mark in the counter array
    int i = 0; // index to loop through the string
    while(string[i]!='\0')
    {
        currentChar = string[i];
        // convert capitals to lower cases 65-90
        if(currentChar >= MIN_CAP && currentChar <= MAX_CAP)
        {
            currentChar += (MIN_LOW-MIN_CAP);
        }
        
        // lower case runs from 97 to 122
        // numbers run from 60 to 71
        if((currentChar >= MIN_LOW && currentChar <= MAX_LOW) ||
           (currentChar >= MIN_INT && currentChar <= MAX_INT))
        {
            counter[currentChar]++; // count the occurrance of this character
            if (counter[currentChar] % 2 == 1) // if the occurrance is odd, add the oddCount by 1
            {
                oddCount++;
            }
            else
            {
                // otherwise this count must have been toggled from an odd number so decrease by 1
                oddCount--;
            }
        }
        i++;
        
    }
    
    // delete the array from heap
    delete [] counter;
    
    if (oddCount > 1)
    {
        //        std::cout << string << " is not a parlindrome word!\n";
        std::cout << 0 << '\n';
        return false;
    }
    else
    {
        //        std::cout << string << " is a parlindrome word!\n";
        std::cout << 1 << '\n';
        return true;
    }
}


void testIsPalindromeWord()
{
    std::cout << "the following words are Pardindrome\n";
    isPalindromeWord("R...acecar");
    isPalindromeWord("repape!r");
    isPalindromeWord("soLos");
    isPalindromeWord("ra,cecar");
    isPalindromeWord("stats");
    isPalindromeWord("reddEr");
    isPalindromeWord("aaaa   Aaaaaa aaaa");
    isPalindromeWord("00000000000");
    isPalindromeWord("wasitacatisaW");
    
    std::cout << "\nthe following words are not Pardindrome\n";
    isPalindromeWord("My");
    isPalindromeWord("hello  world");
    isPalindromeWord("it!hinkyouaRewrong");
    isPalindromeWord("callmema.ybe");
    isPalindromeWord("M aybe");
    isPalindromeWord("yoU");
    isPalindromeWord("It");
    isPalindromeWord("102"); // does not work for numbers
}

