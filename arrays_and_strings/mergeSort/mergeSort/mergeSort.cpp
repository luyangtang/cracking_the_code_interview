//
//  mergeSort.cpp
//  mergeSort
//
//  Created by LYT on 10/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "mergeSort.hpp"
#include <iostream>
#include "tests.hpp"


int* merge(int *a, int *b, int sizeA, int sizeB)
{
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
        // if b has remaining entries then populate it to arr
        while (bInd < sizeB)
        {
            arr[i++] = b[bInd++];
        }
    }
    else
    {
        // if a has remaining entries then populate it to arr
        while (aInd < sizeA)
        {
            arr[i++] = a[aInd++];
        }
    }
    
    return arr;
}



int* mergeSort(int arr[], int arrSize)
{
    if(arrSize == 1)
    {
//        printArray(arr, arrSize);
//        std::cout << "; that's it.\n";
        return arr;
    }
    else
    {
        int splitInd = arrSize/2;
        int *a = new int[splitInd];
        int *b = new int[arrSize - splitInd];
        for (int i = 0; i < arrSize; i++)
        {
            if(i < splitInd)
                a[i] = arr[i];
            else
                b[i - splitInd] = arr[i];
        }
        
        a = mergeSort(a, splitInd);
        b = mergeSort(b, arrSize - splitInd);
//        printArray(arr, arrSize);
//        std::cout << " splits into ";
//        printArray(a, splitInd);
//        std::cout << " and ";
//        printArray(b, arrSize - splitInd);
//        std::cout << '\n';
        
        
        // merge a and b
        int *newarr = merge(a, b, splitInd, arrSize - splitInd);
        
        delete[] a;
        delete[] b;
        
//        std::cout << ", which merge in to ";
//        printArray(newarr, arrSize);
//        std::cout << "\n\n";
        
        return newarr;
    }
}
