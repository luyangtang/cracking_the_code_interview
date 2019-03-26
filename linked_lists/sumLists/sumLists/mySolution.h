//
//  mySolution.h
//  sumLists
//
//  Created by LYT on 26/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h

class Node
{
public:
    int data;
    Node *next;
    
    // initialise
    Node(int _data = 0, Node *_next = nullptr);
    
    // copy constructor
    Node(Node *newNode);
};


class List
{
public:
    Node *head;
    int len;
    
    // constructor
    List();
    
    // initialise with an array
    List(int arr[], int _arrLen);
    
    // destructor
    ~List();
    
    // append
    void append(Node *newNode);
    
    // print
    void print() const;
    
    
    // calculate numerical value
    int getValue() const;
    
    // sum of two lists
    List* operator+ (const List&list2);
};

List* getListFromInt(int _int);

void testListFromInt();

void testOverride();

void testMySolution();

#endif /* mySolution_h */
