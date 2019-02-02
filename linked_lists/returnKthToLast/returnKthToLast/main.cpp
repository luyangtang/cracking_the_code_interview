//
//  main.cpp
//  returnKthToLast
//
//  Created by LYT on 31/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//


// add remove as a method so that len can be decreased while keeping it a private member

#include <iostream>
class Node
{
public:
    Node *next;
    int data;
    
    // constructor
    Node(int _data, Node *_next = nullptr)
    {
        data = _data;
        next = _next;
    }
};

class linkedList
{
public:
    Node *head;
    int len;
    
    // constructor
    linkedList(int arr[], int arrLen)
    {
        head = new Node(arr[0]);
        Node *current = head;
        
        for (int i = 1; i < arrLen; i++)
        {
            current->next = new Node(arr[i]);
            current = current->next;
            len++;
        }
        this->print();
    }
    
    // destructor
    ~linkedList()
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
    
    // print
    void print()
    {
        Node *current = head;
        for (int i = 0; i < len; i++)
        {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << current->data << '\n';
    }
};


// return the kth to the last
int backCount(linkedList &lst,int k)
{
    // if only one line just return the value of head
    if (lst.head->next == nullptr)
    {
        return lst.head->data;
    }
    else
    {
        // the kth to the last is the (k-1)th to the last without tail
        
        // remove the last one
        Node *current = lst.head;
        Node *prev = current;
        while (current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }
        
        // delete
        delete current;
        prev->next = nullptr;
        
        return backCount(lst,k-1);
    }
}


int main()
{
    
    // insert code here...
    int arr[] = {0,1,2,3,4,5};
    linkedList lst(arr,6);
    std::cout << backCount(lst,2);
    
}
