//
//  mySolution.cpp
//  circleDetect
//
//  Created by LYT on 27/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "mySolution.h"

int Node::nodeCount = 0;

// constructor by giving data
Node::Node(int _data, Node *_next)
{
    data = _data;
    next = _next;
    
    id = nodeCount++;
    
}
    
// constructor by passing node
Node::Node(Node *_newNode)
{
    data = _newNode->data;
    next = _newNode->next;
    
    id = nodeCount++;
}


// constructor
LinkedList::LinkedList(int arr[], int arrLen)
{
    head = new Node(arr[0]);
    length = arrLen;
    
    Node *current = head;
    for (int i = 1; i < arrLen; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
}

// destructor
LinkedList::~LinkedList()
{
    Node *current = head;
    Node *tmp = current;
    while(current->next!=nullptr)
    {
        current = current->next;
        delete tmp;
        tmp = current;
    }
}
    
// print
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
    
// print address
void LinkedList::printId()
{
    Node *current = head;
    while (current->next != nullptr)
    {
        std::cout << current->id << ' ';
        current = current->next;
    }
    std::cout << current->id << '\n';
}
    
    
bool LinkedList::testLoop()
{
    Node *current = head;
    
    // assume the integer is big enough to accommodate list id as a bit vector
    int bitVector = 0;
    bool circleFlag = false;
    
    while (current->next!=nullptr)
    {
        // if the id has been seen before then return error
        if (bitVector & (1 << current->id))
        {
            circleFlag = true;
            break;
        }
        else
        {
            bitVector |= (1 << current->id);
            current = current->next;
        }
    }
    
    if (circleFlag)
    {
        std::cout << "circle found\n";
    }
    else
    {
        std::cout << "no loop detected\n";
    }
    
    return circleFlag;
}
    
    
void LinkedList::append(Node *newNode)
{
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(newNode);
    length++;
}
    
    
void LinkedList::append(int newData)
{
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(newData);
    length++;
}



void testLinkedList()
{
    int arr[] = {0,1,2,3,4,5};
    LinkedList myLst(arr,6);
    myLst.print();
    myLst.printId();
    
    Node *newNode = new Node(6);
    myLst.append(newNode);
    myLst.print();
    
    myLst.append(7);
    myLst.print();
    
    delete newNode;
}



void testCircleDetect()
{
    int arr[] = {0,1,2,3,4,5};
    
    LinkedList myLst(arr,6);
    myLst.testLoop();
    myLst.append(myLst.head);
    myLst.testLoop();
}
