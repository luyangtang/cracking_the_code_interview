//
//  mySolution.h
//  returnKthToLast
//
//  Created by LYT on 02/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h

class Node
{
public:
    Node *next;
    int data;
    
    // constructor
    Node(int _data, Node *_next = nullptr);
};

class linkedList
{
public:
    Node *head;
    int len;
    
    // constructor
    linkedList(int arr[], int arrLen);
    
    // destructor
    ~linkedList();
    
    // remove the last one
    void cutTail();
    
    // print
    const void print();
};


// return the kth to the last
int backCount(int arr[], int arrLen, const int k);

void testReturnKth();

#endif /* mySolution_h */
