//
//  main.cpp
//  isUnique
//
//  Created by LYT on 07/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
//#include "mySolution.h"




int main() {
    
    int a[] = {1,2,6,7,8};
    int sizeA = 5;
    int b[] = {2,3,6,10,14,15};
    int sizeB = 6;
    int fullSize = sizeA + sizeB;
    
    // aInd and bInd are the running index for a and b
    int aInd = 0; int bInd = 0;
    // i is the index for the full array
    int i = 0;
    
    // create an empty array for both
    int *arr = new int[fullSize];
    
    while(aInd < sizeA && bInd < sizeB)
    {
        // compare current aInd and bInd
        if (a[aInd] < b[bInd])
        {
            arr[i++] = a[aInd++];
        }
        else
        {
            arr[i++] = b[bInd++];
        }
        
    }
    
    // last entry check
    if (aInd == sizeA)
    {
        while (bInd < sizeB)
        {
            arr[i++] = b[bInd++];
        }
    }
    else
    {
        while (aInd < sizeA)
        {
            arr[i++] = a[aInd++];
        }
    }
        
    
    // see the result
    for (int j = 0; j < fullSize; j++)
    {
        std::cout << arr[j] << ' ';
    }
    
    
    delete[] arr;
    
    // define char const *string
//    char string[] = "Hello world!";
//
//    int i = 0;
//    while(string[i] != '\0')
//    {
//        std::cout << static_cast<int>(string[i]) << ' ';
//        i++;
//    }
    
    return 0;
    
    
}
