//
//  stackFromList.h
//  stack
//
//  Created by LYT on 05/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//


#ifndef stackFromList_h
#define stackFromList_h


class Node
{
public:
    int data;
    Node *next;
    
    // initialise
    Node (int _data, Node *_next=nullptr);
};

class List
{
public:
    Node *head;
    
    // constructor
    List (int arr[], int arrLen);
    
    // destructor
    ~List ();
    
    // print list
    void print();
    
    // append a value (int)
    int append(int _data);
    
    // remove a value
    int pop();
    
    // get length
    int peek();
};

class ListStack
{
private:
    List *lst;
    
public:
    // construct from a list
    ListStack(List *_lst);
    
    void append(int _data);
    
    void pop();
    
    int peek();
    
    bool isEmpty();
};


void testLinkedList();

void testStack2();


#endif /* stackFromList_h */
