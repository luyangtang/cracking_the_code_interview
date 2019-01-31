//
//  mySolution.h
//  removeDups
//
//  Created by LYT on 31/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h

class Node
{
public:
    Node *next;
    char data;
    
    // define constructor
    Node(char _data, Node *_next = nullptr);
    
    void print();
};


class linkedList
{
public:
    Node *head;
    int len;
    
    // define constructor
    linkedList(char const *string);
    
    
    // define destructor
    ~linkedList();
    
    
    // print method
    void print();
    
    // delete the ith cell
    void del(int _i);
    
    
    // remove dups
    void removeDups();
};


void testLinkedList();
void testDel();
void testRemoveDups();

#endif /* mySolution_h */
