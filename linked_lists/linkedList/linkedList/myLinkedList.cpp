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
    listLen = arrLen;
    
    // to loop through the _arr
    Node *currentNode = head;
    
    if(arrLen > 1)
    {
        for (int i = 1; i < arrLen; i++)
        {
            currentNode->next = new Node(_arr[i]);
            currentNode = currentNode->next;
        }
    }
}
    
    // destructor
linkedList::~linkedList()
{
    Node *currentNode = head;
    Node *tmp;
    while(currentNode!=nullptr && currentNode->next!=nullptr)
    {
        tmp = currentNode->next;
        delete currentNode;
        currentNode = tmp;
    }
    delete currentNode;
}


void linkedList::remove(int _i)
{
    // if _i = 0 shift
    if(_i > listLen)
    {
        std::cout << "Out of scope";
    }
    else if(_i == 0)
    {
        head = head->next;
    }
    else
    {
        Node *currentNode = head;
        for(int i = 0; i < _i - 1; i++) // stop right before the _i-th
        {
            currentNode = currentNode->next;
        }
        
        // redirect the next for the item before _ith
        Node *ith = currentNode->next; // for deallocation
        currentNode->next = currentNode->next->next;
        delete ith; // deallocate space
    }
    this->print();
}


void testRemove()
{
    int arr[] = {0,1,2,3,4,5};
    linkedList ls(arr,sizeof(arr)/sizeof(arr[0]));
    ls.remove(2);
    
    // delete the first
    linkedList ls2(arr,sizeof(arr)/sizeof(arr[0]));
    ls2.remove(0);
    
    // delete the final
    linkedList ls3(arr,sizeof(arr)/sizeof(arr[0]));
    ls3.remove(5);
    ls3.remove(0); // consecutive removals
    
    int arr2[] = {0};
    linkedList ls4(arr2,sizeof(arr2)/sizeof(arr2[0]));
    ls4.print();
    ls4.remove(0);
}



    
    // printout the list
void linkedList:: print()
{
    Node *currentNode = head;
    if (listLen >= 1)
    {
        while (currentNode!=nullptr && currentNode->next!=nullptr)
        {
            std::cout << currentNode->data << "->";
            currentNode = currentNode->next;
        }
    }
    // off-by-one
    if (currentNode!=nullptr)
        std::cout << currentNode->data << '\n';
}


void testLinkedList()
{
    int arr[] = {1,2,3,4,5};
    linkedList ls(arr,sizeof(arr)/sizeof(arr[0]));
    ls.print();
}



