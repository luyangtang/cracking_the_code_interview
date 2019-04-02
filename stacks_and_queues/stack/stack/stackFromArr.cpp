//
//  stackFromArr.cpp
//  stack
//
//  Created by LYT on 02/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "stackFromArr.h"


    Stack::Stack(int _arr[], int arrLen)
    {
        int i = 0;
        for (i = 0; i < arrLen; i++)
        {
            arr[i] = _arr[i];
        }
        top = i;
    }


void Stack::print()
{
    for (int i = 0; i < top; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}
    
    // pop
int Stack::pop()
{
    if (top < 0)
    {
        std::cout << "stack underflow\n";
        return 0;
    }
    else
    {
        int x = arr[--top];
        std::cout << x << " popped from the stack\n";
        return x;
    }
}
    
    // push
int Stack::push(int x){
    if (top > MAX)        {
        std::cout << "exceeding max length\n";
        return 0;
    }
    else
    {
        std::cout << x << "pushed into the stack\n";
        arr[top++] = x;
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}


void testStack()
{
    int arr[] = {0,1,2,3,4,5};
    Stack stk(arr,6);
    stk.print();
    
    // test push
    stk.push(7);
    stk.push(8);
    stk.print();
    
    // test pop
    stk.pop();
    stk.pop();
    stk.print();
}
