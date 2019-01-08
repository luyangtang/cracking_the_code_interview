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
        a = mergeSort(a, sizeA);
//        for (int k = 0; k < sizeA; k++)
//            std::cout << a[k] << ' ';
//        std::cout << '\n';
        
        b = mergeSort(b, sizeB);
//        for (int k = 0; k < sizeB; k++)
//            std::cout << b[k] << ' ';
//        std::cout << '\n';
        
        // merge
        int *merged = merge(a, b, sizeA, sizeB);
        return merged;
    }
}


int main() {
    
    int arr[] = {94,146,28, 24,1,1, 9, 32,100000,3};
    int *sortedArr = mergeSort(arr, sizeof(arr)/sizeof(int));

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        std::cout << sortedArr[i] << ' ';
    }
    
    return 0;
}
