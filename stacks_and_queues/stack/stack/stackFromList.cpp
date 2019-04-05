//
//  stackFromList.cpp
//  stack
//
//  Created by LYT on 05/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "stackFromList.h"


// initialise
Node::Node (int _data, Node *_next)
{
    data = _data;
    next = _next;
}


// constructor
List::List (int arr[], int arrLen)
{
    head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < arrLen; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
}

// destructor
List::~List ()
{
    Node *current = head;
    Node *tmp = current;
    while (current->next != nullptr)
    {
        current = current->next;
        delete tmp;
        tmp = current;
    }
    delete tmp;
}

// print list
void List::print()
{
    Node *current = head;
    
    while (current->next != nullptr)
    {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << current->data << '\n';
}

// append a value (int)
int List::append(int _data)
{
    Node *current = head;
    
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(_data);
    return _data;
}

// remove a value
int List::pop()
{
    Node *current = head;
    Node *tmp = current;
    
    while (current->next != nullptr)
    {
        tmp = current;
        current = current->next;
    }
    
    int valPopped = current->data;
    
    tmp->next = nullptr;
    delete current;
    
    return valPopped;
}

// get length
int List::peek()
{
    Node *current = head;
    int count = 1;
    
    while (current->next != nullptr)
    {
        current = current->next;
        count++;
    }
    return count;
}


ListStack::ListStack(List *_lst)
{
    lst = _lst;
}

void ListStack::append(int _data)
{
    lst->append(_data);
}

void ListStack::pop()
{
    lst->pop();
}

int ListStack::peek()
{
    return lst->peek();
}

bool ListStack::isEmpty()
{
    return (this->peek() == 0);
}
