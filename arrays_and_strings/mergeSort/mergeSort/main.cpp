//
//  main.cpp
//  mergeSort
//
//  Created by LYT on 08/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>

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
    
    
//    // see the result
//    for (int j = 0; j < fullSize; j++)
//    {
//        std::cout << arr[j] << ' ';
//    }
    
    int *merged = arr;
    delete[] arr;
    return merged;
}


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

int* mergeSort(int arr[], int arrSize)
{
    int midInd = (arrSize + 1) / 2; // half of the length
    int sizeA = midInd; int sizeB = arrSize - midInd;

    if (arrSize == 1)
    {
        return arr;
    }
    else
    {
        // split the array into two
        int *a = new int[midInd];
        int *b = new int[arrSize - midInd];
        
        // copy over a and b
        int i = 0;
        for (i; i < sizeA; i++)
        {
            a[i] = arr[i];
        }
        for (int j = 0; j < sizeB; j++)
        {
            b[j] = arr[i++];
        }
        
        // call recursion
//        int *newA = a;
//        int *newB = b;
        int *newA = mergeSort(a, sizeA);
        for (int k = 0; k < sizeA; k++)
            std::cout << newA[k] << ' ';
        std::cout << '\n';
        
        int *newB = mergeSort(b, sizeB);
        for (int k = 0; k < sizeB; k++)
            std::cout << newB[k] << ' ';
        std::cout << '\n';
        
        // merge
        int *merged = merge(newA, newB, sizeA, sizeB);
        
 //       delete[] a;
 //       delete[] b;
        
        return merged;
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


void splitArrayFull(int arr[], int arrSize)
{
    if(arrSize == 1)
    {
        printArray(arr, arrSize);
        std::cout << "; that's it.\n";
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
        printArray(arr, arrSize);
        std::cout << " splits into ";
        printArray(a, splitInd);
        std::cout << " and ";
        printArray(b, arrSize - splitInd);
        std::cout << '\n';
    }
}

void testSplitArrayfull()
{
    int arr1[] = {1,4,2,4,6,8,4,2,6,8};
    splitArrayFull(arr1,sizeof(arr1)/sizeof(int));
    int arr2[] = {1,4,2,4,6,8,4,2,6,18};
    splitArrayFull(arr2,sizeof(arr2)/sizeof(int));
    int arr3[] = {1,4,2,4,6,8,4,2,6,18,124,12};
    splitArrayFull(arr3,sizeof(arr3)/sizeof(int));
    int arr4[] = {1,4,2,4,6,8,4,2,6,18,235};
    splitArrayFull(arr4,sizeof(arr4)/sizeof(int));
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

int main() {
    
//    int arr[] = {1,2,3,4,5,2,3,4,5,6,7};
//    int *sortedArr = mergeSort(arr, sizeof(arr)/sizeof(int));
//
//    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
//    {
//        std::cout << sortedArr[i] << ' ';
//    }
    testSplitArrayfull();
    
    return 0;
}
