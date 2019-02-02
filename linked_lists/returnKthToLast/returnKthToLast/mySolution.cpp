//
//  main.cpp
//  returnKthToLast
//
//  Created by LYT on 31/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//


// add remove as a method so that len can be decreased while keeping it a private member

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
        len = 0;
        
        for (int i = 1; i < arrLen; i++)
        {
            current->next = new Node(arr[i]);
            current = current->next;
            len++;
        }
//        this->print();
    }
    
    // destructor
linkedList::~linkedList()
    {
        Node *current = head;
        Node *tmp;
        for (int i = 0; i < len; i++)
        {
            tmp = current;
            current = current->next;
            delete tmp;
        }
    }
    
    // remove the last one
void linkedList::cutTail()
    {
        if (head->next!=nullptr)
        {
            Node *current = head;
            Node *prev = current;
            for (int i = 0; i < len; i++)
            {
                prev = current;
                current = current->next;
            }
            prev->next = nullptr;
            delete current;
            len--;
        }
    }
    
    // print
const void linkedList::print()
    {
        Node *current = head;
        for (int i = 0; i < len; i++)
        {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << current->data << '\n';
    }


// return the kth to the last
int backCount(int arr[], int arrLen, const int k)
{
    linkedList lst(arr, arrLen);
    
    // if k = 0 then travel to the back and return value
    if (k == 0)
    {
        Node *current = lst.head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        return current->data;
    }
    else
    {
        // the kth to the last is the (k-1)th to the last without tail
        
        // remove the last one
        lst.cutTail();
//        lst.print();
        return backCount(arr, arrLen-1, k-1);
    }
}



void testReturnKth()
{
    // insert code here...
    int arr[] = {0,1,2,3,4,5};
    int arrLen = 6;
    std::cout << backCount(arr,arrLen,0) << '\n';
    std::cout << backCount(arr,arrLen,1) << '\n';
    std::cout << backCount(arr,arrLen,2) << '\n';
    std::cout << backCount(arr,arrLen,3) << '\n';
    std::cout << backCount(arr,arrLen,4) << '\n';
    std::cout << backCount(arr,arrLen,5) << '\n';
    // if k too large, it returns the first one
    std::cout << backCount(arr,arrLen,6) << '\n';
    
}

