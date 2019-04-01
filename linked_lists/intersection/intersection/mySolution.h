//
//  mySolution.h
//  intersection
//
//  Created by LYT on 01/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h


class Node
{
public:
    int data;
    Node *next;
    
    // constructor - from data
    Node(int _data, Node *_next = nullptr);
    
    // constructor - from another node
    Node(Node &_node);
};


class LinkedList
{
public:
    Node *head;
    
    
    // constructor - from array
    LinkedList(int arr[], int arrLen);
    
    // constructor - from another linkedList
    LinkedList(LinkedList *lst);
    
    const int getLen ()const;
    
    const Node *getTail() const;
    
    //    // destructor
    //    ~LinkedList();
    //
    void print();
    
    void printAddress();
    
    
    
};


void testLinkedListFromArr();

bool isIntersect(const LinkedList &lst1, const LinkedList &lst2);

void testIsIntersection();


#endif /* mySolution_h */
