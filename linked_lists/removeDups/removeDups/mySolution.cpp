//
//  mySolution.cpp
//  removeDups
//
//  Created by LYT on 31/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "mySolution.h"
#include <iostream>

Node::Node(char _data, Node *_next)
{
    next = _next;
    data = _data;
}

void Node::print()
{
    std::cout << this->data;
}




linkedList::linkedList(char const *string)
{
    len = 0;
    head = new Node(string[0]);
    
    // loop through the string and populate characters
    int i = 1; // index to loop through the string
    Node *currentNode = head; // node to loop through the list
    
    while(string[i]!='\0')
    {
        len++; // record the length
        currentNode->next = new Node{string[i]};
        i++;
        currentNode = currentNode->next;
    }
    
    // off by one
    currentNode->next = new Node{string[i]};
    //        this->print();
}
    
    
    // define destructor
linkedList::~linkedList()
{
    Node *currentNode = head;
    Node *tmp;
    for (int i = 0; i < len; i++)
    {
        if (currentNode->next != nullptr)
        {
            tmp = currentNode->next;
            delete currentNode;
            currentNode = tmp;
        }
    }
    //        std::cout << "linked list destructed\n";
}
    
    
    // print method
void linkedList::print()
{
    Node *currentNode = head;
    for (int i = 0; i < len; i++)
    {
        currentNode->print();
        if (currentNode->next != nullptr)
            currentNode = currentNode->next;
    }
    currentNode->print();
    std::cout << '\n';
}
    
    // delete the ith cell
void linkedList::del(int _i)
{
    // only do for _i < len
    
    if (_i < len)
    {
        Node *currentNode = head;
        for (int i = 0; i < _i-1; i++)
        {
            currentNode = currentNode->next;
        }
        
        // use a tmp to record the one to be delete (for deallocation)
        Node *tmp = currentNode->next;
        
        // relink
        currentNode-> next = currentNode->next->next;
        
        // deallocation
        delete tmp;
        
        // update len
        len--;
        
        //            this->print();
    }
}
    
    
    // remove dups
void linkedList::removeDups()
// 1st approach: using bitvector
{
    Node *currentNode = head;
    int bitVector = 0;
    
    for (int i = 0; i < len; i++)
    {
        // if the character has never been visited,
        // turn on that vector
        if (bitVector & (1 << static_cast<int>(currentNode->data)))
        {
            bitVector ^= (1 << static_cast<int>(currentNode->data));
            // move to next node
            currentNode = currentNode->next;
        }
        else
            // else delete the current node
        {
            currentNode = currentNode->next;
            this->del(i);
        }
    }
    
    this->print();
}




void testLinkedList()
{
    linkedList myString1("Helloworld"); myString1.print();
    linkedList myString2("Follow up"); myString2.print();
    linkedList myString3("apple"); myString3.print();
}

void testDel()
{
    linkedList myString1("Helloworld"); myString1.del(3);
    linkedList myString2("Follow up"); myString2.del(0);
}

void testRemoveDups()
{
    linkedList myString1("Helloworld"); myString1.removeDups();
    linkedList myString2("Follow up"); myString2.removeDups();
    linkedList myString3("apple"); myString3.removeDups();
}
