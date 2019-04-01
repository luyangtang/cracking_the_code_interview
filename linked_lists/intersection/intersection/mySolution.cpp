//
//  mySolution.cpp
//  intersection
//
//  Created by LYT on 01/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "mySolution.h"
#include <iostream>


Node::Node(int _data, Node *_next)
{
    data = _data;
    next = _next;
}

// constructor - from another node
Node::Node(Node *_node)
{
    data = _node->data;
    next = _node->next;
}


LinkedList::LinkedList(int arr[], int arrLen)
{
    head = new Node(arr[0]);
    
    Node *current = head;
    for (int i = 1; i < arrLen; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
}

// constructor - from another linkedList
LinkedList::LinkedList(LinkedList *lst)
{
    head = lst->head;
}

//    // destructor
//    LinkedList::~LinkedList()
//    {
//        Node *current = head;
//        Node *tmp = current;
//
//        while (current->next != nullptr)
//        {
//            tmp = current;
//            current = current->next;
//            delete tmp;
//            tmp = nullptr;
//        }
//    }
//
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

void LinkedList::printAddress()
{
    Node *current = head;
    
    while (current->next!=nullptr)
    {
        std::cout << &current << ' ';
        current = current->next;
    }
    std::cout << &current << '\n';
}
    



void testLinkedListFromArr()
{
    int arr1[] = {0,1,2,3,4,5};
    LinkedList lst(arr1,6);
    lst.print();
}

bool isIntersect(LinkedList &lst1, LinkedList &lst2)
{
    // use brute force
    Node *c1 = lst1.head;
    Node *c2 = lst2.head;
    
    while (c1->next != nullptr)
    {
        while (c2->next != nullptr)
        {
            if (c1 == c2)
            {
                // flag it and quit the inner while
                std::cout << "there is intersection\n";
                return true;
            }
            c2 = c2->next;
        }
        c2 = lst2.head;
        c1 = c1->next;
    }
    
    std::cout << "there is no intersection\n";
    return false;
}

void testIsIntersection()
{
    int arr1[] = {0,1,2,3,4,5};
    LinkedList lst(arr1,6);
    
    int arr2head[] = {0,1,2,3,4,5};
    LinkedList lst2head(arr2head,6);
    
    std::cout << isIntersect(lst,lst2head);
    
    LinkedList lst2 = lst2head;
    Node *current = lst2head.head;
    while(current->next!=nullptr)
    {
        current = current->next;
    }
    current->next = lst.head;
    
    //    lst2.printAddress();
    lst2.print();
    
    
    std::cout << isIntersect(lst,lst2);
    
}
