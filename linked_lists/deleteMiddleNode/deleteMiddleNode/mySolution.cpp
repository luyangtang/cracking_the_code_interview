//
//  mySolution.cpp
//  deleteMiddleNode
//
//  Created by LYT on 03/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "mySolution.h"

Node::Node(int _data, Node *_next)
{
    data = _data;
    next = _next;
}

linkedList::linkedList(int arr[], int arrLen)
{
    head = new Node(arr[0]);
    Node *current = head;
    len = 1;
    
    for (int i = 1; i < arrLen; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
        len++;
    }
    this -> print();
}

linkedList::~linkedList()
{
    Node *current = head;
    Node *tmp;
    while(current->next!=nullptr)
        // cannot use for loop because of removal
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
}


void linkedList::print()
{
    Node *current = head;
    for (int i = 0; i < len - 1; i++)
    {
        std::cout << current->data << "->";
        current = current->next;
    }
    std::cout  << current->data << '\n';
}



void deleteNode (linkedList &lst, Node *node)
{
    Node *prev = node;
    Node *next = prev -> next;
    
    // move the data to the front
    while (next != nullptr)
    {
        prev -> data = next -> data;
        prev = prev -> next;
        next = prev -> next;
    }
    
    // delete the final node
    prev->next = nullptr;
    delete prev;
    lst.len--;
    
    lst.print();
}


void testDeleteNode()
{
    int arr[] = {0,1,2,3,4,5};
    linkedList lst(arr,6);
    deleteNode(lst, lst.head->next->next->next);
}
