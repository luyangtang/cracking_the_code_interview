//
//  myLinkedList.h
//  linkedList
//
//  Created by LYT on 30/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef myLinkedList_h
#define myLinkedList_h


class Node
{
public:
    Node *next;
    int data;
    
    // constructor - data only
    Node(int _data = 0);
    
    Node(Node *_next, int _data = 0);
};


class linkedList
{
public:
    Node *head;
    
    //constructor
    linkedList(int *_arr, int arrLen);
    
    // destructor
    ~linkedList();
    
    // printout the list
    void print();
    
};

void testLinkedList();

#endif /* myLinkedList_h */
