//
//  main.cpp
//  oneWay
//
//  Created by LYT on 22/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

/* One Away: There are three types of edits that can be performed on strings:
    insert a character, remove a character, or replace a character.
 Given two strings, write a function to check if they are one edit (or zero edits) away.
 */


#include <iostream>
// #include <bitset>
#define MAX_CHAR 256

void countChar(char const *string, int charCounter[])
{
    int i = 0; // index to loop through the string
    while(string[i]!='\0')
    {
        charCounter[string[i++]]++;
    }
}


bool checkExactlyOneNoneZero(int bitVector)
{
    return ((bitVector & (bitVector - 1)) == 0);
}


bool checkOneWay(char const *string1, char const *string2)
{
    int charCounter1[MAX_CHAR] = {0};
    int charCounter2[MAX_CHAR] = {0};
    
    countChar(string1,charCounter1);
    countChar(string2,charCounter2);
    
    int bitCompare = 0; // bit vector to compare charCounter1 and charCounter2
    
    for (int j = 0; j < MAX_CHAR; j++)
    {
        if(charCounter1[j]!=charCounter2[j])
        {
            // if the pair are not equal, then 'toggle' the j-th entry in the bit vector
            // toggle is the same as turn on because we only scan it in the same direction once
            bitCompare |= (1 << j);
        }
    }
    
    //    std::bitset<32> x(bitCompare);
    //    std::cout << x << '\n';
    
    // check if there is exactly one 1 in the bit vector
    return checkExactlyOneNoneZero(bitCompare);
}


int main() {
//
//    char const *string1 = "pale";
//    char const *string2 = "ale";
    
    // test insertion
    // ---
    std::cout << (checkOneWay("pale", "palet")? 'y':'n') << '\n';
    std::cout << (checkOneWay("tiger", "ttiger")? 'y':'n') << '\n';
    std::cout << (checkOneWay("flower", "flowers")? 'y':'n') << '\n';
    // ---
    std::cout << (checkOneWay("pale", "bppale")? 'n':'y') << '\n';
    std::cout << (checkOneWay("pale", "baale")? 'n':'y') << '\n';
    std::cout << (checkOneWay("pale", "balee")? 'n':'y') << '\n';
    
    
    // test removal
    // ----
    std::cout << (checkOneWay("pale", "ale")? 'y':'n') << '\n';
    std::cout << (checkOneWay("tiger", "tige")? 'y':'n') << '\n';
    std::cout << (checkOneWay("ginger", "inger")? 'y':'n') << '\n';
    std::cout << (checkOneWay("pales", "pale")? 'y':'n') << '\n';
    // ----
    
    // test replacement
    std::cout << (checkOneWay("pale", "bale")? 'y':'n') << '\n';
    std::cout << (checkOneWay("pale", "pole")? 'y':'n') << '\n';
    std::cout << (checkOneWay("pale", "pald")? 'y':'n') << '\n';
    
    
    
    return 0;
}
