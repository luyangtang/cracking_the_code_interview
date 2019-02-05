//
//  mySolution.h
//  partition
//
//  Created by LYT on 05/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h

class Node
{
public:
    
    int data;
    Node *next;
    
    Node(int _data, Node *_next = nullptr);
};


class linkedList
{
public:
    Node *head;
    int len;
    
    linkedList(int arr[], int arrLen);
    
    ~linkedList();
    
    void print();
};

void partition(linkedList &lst, int parVal);

void testPartition();

#endif /* mySolution_h */
