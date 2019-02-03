//
//  iterative.cpp
//  returnKthToLast
//
//  Created by LYT on 03/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "iterative.h"


void testBackCountIterative()
{
    int arr[] = {0,1,2,3,4,5,6};
    linkedList lst(arr,7);
    backCountIterative(lst,1);
    backCountIterative(lst,2);
    backCountIterative(lst,3);
    backCountIterative(lst,4);
}



int backCountIterative(linkedList const &lst, int k)
{
    // define two pointers running through lst k positions apart
    Node *p0 = lst.head;
    Node *p1 = lst.head;
    
    // let p1 run k positions k must be less than len
    for (int i = 0; i < k; i++)
    {
        p1 = p1->next;
    }
    
    // let p0 and p1 run simultaneously
    while (p1->next != nullptr)
    {
        p0 = p0->next;
        p1 = p1->next;
    }
    
    std::cout << p0->data << '\n';
    return p0->data;
}

