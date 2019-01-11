//
//  tests.cpp
//  mergeSort
//
//  Created by LYT on 10/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "tests.hpp"
#include "mergeSort.hpp"
#include <iostream>

void testMerge()
{
    int a[] = {1,2,6,7,8,100,240,560};
    int b[] = {2,3,6,10,14,15};
    int *arr = merge(a,b,sizeof(a)/sizeof(int),sizeof(b)/sizeof(int));
    for (int i = 0; i < sizeof(a)/sizeof(int)+sizeof(b)/sizeof(int); i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void printArray(int arr[], int arrSize)
{
    std::cout << '[';
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << ']';
}


void splitArray(int arrSize)
{
    if (arrSize == 1)
        std::cout << "Don't split: use the arr as it is\n";
    else if (arrSize > 1)
    {
        int splitInd = arrSize/2;
        std::cout << splitInd << " for an array of length of " << arrSize << '\n';
    }
}


void testSplitArray()
{
    splitArray(1);
    splitArray(2);
    splitArray(3);
    splitArray(4);
    splitArray(5);
    splitArray(6);
    splitArray(7);
    splitArray(8);
}


void testMergeSort()
{
    int arr1[] = {3,6,2,4,7,4,5};
    int *sortedArr = mergeSort(arr1, sizeof(arr1)/sizeof(int));
    printArray(sortedArr, sizeof(arr1)/sizeof(int));
    
    std::cout << '\n';
    
    int arr2[] = {0,0,0,0,0,0};
    int *sortedArr2 = mergeSort(arr2, sizeof(arr2)/sizeof(int));
    printArray(sortedArr2, sizeof(arr2)/sizeof(int));
    
    std::cout << '\n';
    
    int arr3[] = {9,8,7,6,5,4,3,2,1};
    int *sortedArr3 = mergeSort(arr3, sizeof(arr3)/sizeof(int));
    printArray(sortedArr3, sizeof(arr3)/sizeof(int));
}

