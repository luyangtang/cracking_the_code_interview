//
//  mySolution.h
//  circleDetect
//
//  Created by LYT on 27/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h


class Node
{
public:
    int data;
    Node *next;
    static int nodeCount;
    int id;
    
    // constructor by giving data
    Node(int _data, Node *_next = nullptr);
    
    // constructor by passing node
    Node(Node *_newNode);
};

class LinkedList
{
public:
    Node *head;
    int length;
    
    // constructor
    LinkedList(int arr[], int arrLen);
    
    // destructor
    ~LinkedList();
    
    // print
    void print();
    
    // print address
    void printId();
    
    
    bool testLoop();
    
    bool testLoopAlg();
    
    
    void append(Node *newNode);
    
    
    void append(int newData);
    
    
};

void testCircleDetect();

void testLinkedList();


#endif /* mySolution_h */
