//
//  stackFromArr.h
//  stack
//
//  Created by LYT on 02/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#define MAX 100
#ifndef stackFromArr_h
#define stackFromArr_h


class Stack
{
public:
    int top;
    int arr[MAX];
    
    // construct
    Stack(int _arr[], int arrLen);
    
    // print
    void print();
    
    // pop
    int pop();
    
    // push
    int push(int x);
    
    // isEmpty
    bool isEmpty();
    
};


void testStack();


#endif /* stackFromArr_h */
