//
//  mySolution.cpp
//  partition
//
//  Created by LYT on 05/02/2019.
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
        current ->next = new Node(arr[i]);
        current = current -> next;
        len++;
    }
    
    this->print();
}


linkedList::~linkedList()
{
    Node *current = head;
    Node *tmp;
    while (current->next!=nullptr)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    len = 0;
}


void linkedList::print()
{
    Node *current = head;
    
    while(current->next!=nullptr)
    {
        std::cout << current->data << "->";
        current = current->next;
    }
    std::cout << current->data << '\n';
}


void partition(linkedList &lst, int parVal)
{
    
    /* strategy: if the node is smaller, then break and attach to the end */
    
    Node *prev = lst.head;
    Node *current = prev;
    Node *tmp;
    Node *end = current;
    // let end goes to the end
    while(end->next!=nullptr)
        end = end->next;
    
    // first check head
    if (lst.head->data >= parVal)
    {
        tmp = new Node(lst.head->data);
        lst.head = current->next;
        end->next = tmp;
        end = end->next;
        delete tmp;
    }
    else
    {
        // let current go forward
        current = current -> next;
        tmp = current;
    }
    
    //    while (current->next!=nullptr)
    for (int i = 1; i < lst.len; i++)
    {
        
        // check if data is greater or equal to parVal
        if (current->data > parVal)
        {
            // connect prev and next
            tmp = new Node(current->data);
            current = current->next;
            prev->next = current;
            
            // send tmp to the end
            end -> next = tmp;
            end = end -> next;
        }
        else // if the data is smaller then every pointer move forward by 1
        {
            current = current->next;
            prev = prev->next;
        }
        
        lst.print();
    }
    
//    lst.print();
}

// try using recursion


void testPartition()
{
    int arr[] = {0,1,2,3,4,5,6};
    linkedList lst(arr,7);
    partition(lst,5);
    int arr2[] = {3,5,8,5,10,2,1};
    linkedList lst2(arr2,7);
    partition(lst2,5);
}
