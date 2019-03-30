//
//  mySolution.cpp
//  palindrome
//
//  Created by LYT on 30/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "mySolution.h"

    
// constructor
Node::Node (int _data, Node *_next)
{
    data = _data;
    next = _next;
}

// constructor (from a node)
Node::Node (Node *_node, Node *_next)
{
    data = _node->data;
    next = _next;
}


    // constructor from an array
LinkedList::LinkedList(int arr[], int arrLen)
{
    head = new Node(arr[0]);
    Node *current = head;
    len = arrLen;
    
    for (int i = 1; i < arrLen; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
}
    
    // constructor from another head
LinkedList::LinkedList(Node *_head)
{
    head = _head;
    len = _head?1:0;
    
    Node *current = head;
    
    while (current->next != nullptr)
    {
        current = current->next;
        len++;
    }
}
    
    // destructor
LinkedList::~LinkedList()
    {
        Node *current = head;
        Node *tmp = head;
        
        while (current->next != nullptr)
        {
            current = current->next;
            delete tmp;
            tmp = current;
        }
    }
    
    //print
void LinkedList::print()
{
    Node *current = head;
    
    while (current->next != nullptr)
    {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << current->data << '\n';
}
    
    
    // create reverse
LinkedList *LinkedList::reverse()
{
    // forward direction runners
    Node *current = head;
    Node *prev = head;
    
    // backward direction runners
    Node *newHead;
    Node *newNext = nullptr;
    Node *newCurrent = new Node(current, newNext);
    
    while (current->next != nullptr)
    {
        current = current->next;
        
        newNext = new Node(prev,newNext);
        newCurrent = new Node(current,newNext);
        
        prev = current;
    }
    
    // connect to head
    newHead = new Node(current,newNext);
    // create the new linked list with newHead
    LinkedList *newLst = new LinkedList(newHead);
    
    return newLst;
}
    
    
    // is palindrome
bool LinkedList::isPalindrome()
{
    LinkedList *reversed = this->reverse();
    
    Node *fwdCurrent = this->head;
    Node *bwdCurrent = reversed->head;
    
    while (fwdCurrent->next != nullptr)
    {
        if (fwdCurrent->data != bwdCurrent->data)
        {
            std::cout << "not palindrome\n";
            return false;
        }
        fwdCurrent = fwdCurrent->next;
        bwdCurrent = bwdCurrent->next;
    }
    
    if (fwdCurrent->data != bwdCurrent->data)
    {
        std::cout << "not palindrome\n";
        return false;
    }
    else
    {
        std::cout << "is palindrome\n";
        return true;
    }
    
}



void testLinkedList()
{
    int arr[] = {0,1,2,3,4,5};
    LinkedList lst(arr,6);
    lst.print();
    
    // test creating list from another lst
    LinkedList lst2(lst.head);
    lst.print();
}

void testIsPalindrome()
{
    int arr[] = {0,1,2,3,4,5,4,3,2,1,0};
    LinkedList lst(arr,11);
    lst.isPalindrome();
}
