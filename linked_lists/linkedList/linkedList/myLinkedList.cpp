//
//  myLinkedList.cpp
//  linkedList
//
//  Created by LYT on 30/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "myLinkedList.h"
#include <iostream>


Node::Node(int _data)
{
    next = nullptr;
    data = _data;
}
    
Node::Node(Node *_next, int _data)
{
    next = _next;
    data = _data;
}


linkedList::linkedList(int *_arr, int arrLen)
{
    head = new Node(_arr[0]);
    
    // to loop through the _arr
    Node *currentNode = head;
    
    for (int i = 1; i < arrLen; i++)
    {
        currentNode->next = new Node(_arr[i]);
        currentNode = currentNode->next;
    }
}
    
    // destructor
linkedList::~linkedList()
{
    Node *currentNode = head;
    Node *tmp;
    while(currentNode->next!=nullptr)
    {
        tmp = currentNode->next;
        delete currentNode;
        currentNode = tmp;
    }
    delete currentNode;
}
    
    // printout the list
void linkedList:: print()
{
    Node *currentNode = head;
    do
    {
        std::cout << currentNode->data << "->";
        currentNode = currentNode->next;
    }
    while (currentNode->next!=nullptr);
    
    // off-by-one
    std::cout << currentNode->data << '\n';
}


void testLinkedList()
{
    int arr[] = {1,2,3,4,5};
    linkedList ls(arr,sizeof(arr)/sizeof(arr[0]));
    ls.print();
}



