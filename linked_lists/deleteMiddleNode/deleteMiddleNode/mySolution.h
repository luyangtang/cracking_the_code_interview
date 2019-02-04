//
//  mySolution.h
//  deleteMiddleNode
//
//  Created by LYT on 03/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h


class Node
{
public:
    int data;
    Node *next;
    
    // constructor
    Node(int _data, Node *_next = nullptr);
};



class linkedList
{
public:
    int len;
    Node *head;
    
    // constructor
    linkedList(int arr[], int arrLen);
    
    // desrtuctor
    ~linkedList();
    
    void print();
};

void deleteNode (linkedList &lst, Node *node);

void testDeleteNode();

#endif /* mySolution_h */
