//
//  varLength.hpp
//  threeInOne
//
//  Created by LYT on 08/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef varLength_h
#define varLength_h
#define MAX 20

#include <stdio.h>
#include <iostream>

template <typename T, int size>
class TripleStacksV
{
private:
    T arr[size]{0};
    
    // define the tops (index of the array) for stack1
    int top1;
    
    // define the boundary for the medium stack2
    int top2; int midHead;
    
    // define the top for stack3
    int top3;
    
public:
    // consturctor
    TripleStacksV(T *_arr, int _top1, int _top2, int _midHead, int _top3):
        arr(_arr), top1(_top1), top2(_top2), midHead(_midHead), top3(_top3)
    {}
    
    // constructor from arrays
    TripleStacksV(T arr1[], int arrLen1, T arr2[], int arrLen2, T arr3[], int arrLen3)
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
    
    // move stack2 to the right
    bool canMove(int _midHead)
    {
        if (top2 + _midHead - midHead <= top3)
            return true;
        else
            return false;
    }
    
    void move2(int _midHead)
    {
        if(canMove(_midHead))
        {
            int j = midHead;
            
            // update the class members
            top2 += (_midHead - midHead); midHead = _midHead;
            
            // move the items
            for (int i = _midHead; (i < top2) && (i < top3); i++)
            {
                arr[i] = arr[j];
                if (j < _midHead)
                    arr[j++] = 0;
            }
        }
        else
        {
            // expand the size
        }
    }
    
    
    void expandArr()
    {
    }
    
};


#endif /* varLength_hpp */
