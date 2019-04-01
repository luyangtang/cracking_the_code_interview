//
//  compareTail.cpp
//  intersection
//
//  Created by LYT on 01/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "compareTail.h"
#include <iostream>


const int LinkedList::getLen() const
{
    Node *current = head;
    int len = 1;
    while (current->next!=nullptr)
    {
        current = current->next;
        len++;
    }
    return len;
}

const Node *LinkedList::getTail() const
{
    Node *current = head;
    while (current->next!=nullptr)
    {
        current = current->next;
    }
    return current;
}

bool isIntersect2(const LinkedList &lst1, const LinkedList &lst2)
{
    // get the length of the list and tails
    Node *c1 = lst1.head;
    int len1 = lst1.getLen();
    
    Node *c2 = lst2.head;
    int len2 = lst2.getLen();
    
    // compare the tails
    if (lst1.getTail() == lst2.getTail())
    {
        std::cout << "there is intersection\n";
        
        // ------
        // figure out where the intersection begins
        // ------
        
        int lenDiff = (len1 > len2)?(len1 - len2):(len2 - len1);
        
        // truncate the longer one
        while((lenDiff--) > 0)
        {
            if (len1 > len2)
                c1 = c1->next;
            else
                c2 = c2->next;
        }
        
        // run until c1 and c2 meet
        while (c1 != c2)
        {
            c1 = c1->next;
            c2 = c2->next;
        }
        Node *intersect = c1;
        std::cout << "intersection is at " << &(c1->data) << '\n';
        
        return true;
    }
    std::cout << "there is no intersection\n";
    return false;
}



void testIsIntersection2()
{
    int arr1[] = {0,1,2,3,4,5};
    LinkedList lst(arr1,6);
    
    int arr2head[] = {0,1,2,3,4,5};
    LinkedList lst2head(arr2head,6);
    
    std::cout << isIntersect2(lst,lst2head);
    
    LinkedList lst2 = lst2head;
    Node *current = lst2head.head;
    while(current->next!=nullptr)
    {
        current = current->next;
    }
    current->next = lst.head;
    
    //    lst2.printAddress();
    lst2.print();
    
    
    std::cout << isIntersect2(lst,lst2);
    
}
