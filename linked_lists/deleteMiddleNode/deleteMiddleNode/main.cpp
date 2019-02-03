//
//  main.cpp
//  deleteMiddleNode
//
//  Created by LYT on 03/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    
    // constructor
    Node(int _data, Node *_next = nullptr);
};

Node::Node(int _data, Node *_next)
{
    data = _data;
    next = _next;
}

class linkedList
{
public:
    int len;
    Node *head;
    
    // constructor
    linkedList(int arr[], int arrLen);
    
    // desrtuctor
    ~linkedList();
    
    void print();
};

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
    for (int i = 0; i < len; i++)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    delete current;
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



int main() {
    int arr[] = {0,1,2,3,4,5};
    linkedList lst(arr,6);
    return 0;
}
