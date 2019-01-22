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
#define MAX_CHAR 256

int* buildHashTable(char const *string, int &stringLen)
{
    int *hashTbl = new int[MAX_CHAR]{0};
    int i = 0; // index to loop through the string
    while(string[i]!='\0')
    {
        // populate the hash table
        hashTbl[string[i++]]++;
        
        // update the string length
        stringLen++;
    }
    
    return hashTbl;
}




void testHashTable()
{
    char const *string1 = "pale";
    // construct the hash tabls
    int stringLen1 = 0;
    int *hashTbl1 = buildHashTable(string1,stringLen1);
    
    for (int j = 0 ; j < MAX_CHAR; j++)
    {
        std::cout << hashTbl1[j];
    }
    
    std::cout << '\n';
    std::cout << stringLen1;
}


int main() {

    char const *string1 = "pale";
    char const *string2 = "papp";

    // construct the hash tabls
    int stringLen1 = 0;
    int stringLen2 = 0;
    int *hashTbl1 = buildHashTable(string1,stringLen1);
    int *hashTbl2 = buildHashTable(string2,stringLen2);
    
    
    int differentHashTableValueCount = 0;
    int offsetSum = 0;
    if (stringLen1 == stringLen2)
    {
        // returns true only if it is a replacement
        // loop through the keys and find if one change is offset by the other (sum to 0)
        for (int i = 0; i < MAX_CHAR; i++)
        {
            if(hashTbl1[i]!=hashTbl2[i])
            {
                offsetSum += (hashTbl1[i]-hashTbl2[i]); // update offset
                if (differentHashTableValueCount++ > 2) // can't have more than 2 different values in the hash table
                {
                    break;
                    std::cout << "This can't be a replacement\n";
                }
            }
        }
        if(offsetSum==0)
        {
            std::cout << offsetSum;
            std::cout << "This may be a replacement\n";
        }
    }
    
    return 0;
}
