//
//  stack.h
//  palindrome
//
//  Created by LYT on 02/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#define MAX 1000
#ifndef stack_h
#define stack_h


class Stack
{
public:
    int top;
    int arr[MAX];
    
    
    // constructor
    
    Stack();
    
    Stack(int _arr[], int arrLen);
    
    // print
    void print();
    
    // pop
    int pop();
    
    
    // push
    int push(int x);
    
    
    // is empty
    bool isEmpty();
    
};

void testStack();

void testFinal();

#endif /* stack_h */
