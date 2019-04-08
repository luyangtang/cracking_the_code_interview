//
//  fixedLength.hpp
//  threeInOne
//
//  Created by LYT on 08/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef fixedLength_h
#define fixedLength_h
#define MAX 30

#include <stdio.h>

template <typename T>
class TripleStacks
{
private:
    T arr[MAX]{0};
    
    // define the tops (index of the array) for stack1
    int top1;
    
    // define the boundary for the medium stack2
    int top2; int midHead;
    
    // define the top for stack3
    int top3;
    
public:
    // constructor
    TripleStacks(T arr1[], int arrLen1, T arr2[], int arrLen2, T arr3[], int arrLen3)
    {
        // define the positions for these three stacks
        top1 = 0;
        midHead = (int) MAX/3; top2 = midHead; // top2 will be calculated
        top3 = MAX;
        
        // populate stack1
        for (int i = 0; i < arrLen1; i++)
        {
            arr[top1++] = arr1[i];
        }
        
        // populate stack2
        for (int i = 0; i < arrLen2; i++)
        {
            arr[top2++] = arr2[i];
        }
        
        // populate stack3
        for (int i = 0; i < arrLen3; i++)
        {
            arr[--top3] = arr3[i];
        }
    }
    
    
    // print (for testing purpose)
    void printTgt()
    {
        for (int i = 0; i < MAX; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }
    
    // push method for three stacks
    T push1(T _new)
    {
        if (top1 <= midHead)
        {
            arr[top1++] = _new;
        }
        return _new;
    }
    
    T push2(T _new)
    {
        if (top2 <= top3)
        {
            arr[top2++] = _new;
        }
        return _new;
    }
    
    T push3(T _new)
    {
        if (top3 >= top2)
        {
            arr[--top3] = _new;
        }
        return _new;
    }
    
    // pop methods for three stacks
    void pop1()
    {
        if (top1 >= 0)
            arr[--top1] = 0;
    }
    
    void pop2()
    {
        if (top2 >= 0)
            arr[--top2] = 0;
    }
    
    void pop3()
    {
        if (top3 < MAX)
            arr[top3++] = 0;
    }
    
};


void testTripleStacks();

#endif /* fixedLength_hpp */
