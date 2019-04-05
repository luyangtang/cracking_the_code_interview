//
//  recursion.cpp
//  palindrome
//
//  Created by LYT on 05/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "recursion.h"



bool isPalindrome3(Node *head, int lstLen, Node **next)
{
    
    // avoid malloc problem
    if (next == nullptr)
    {
        Node *tmp = new Node(0);
        next = &tmp;
    }
    
    // base case
    if (lstLen <= 1)
    {
        *next = head->next;
        return true;
    }
    
    // for all other cases
    else
    {
        bool recursiveRes;
        
        // call the function with one loop inner
        recursiveRes = isPalindrome3(head->next, lstLen-2, next);
        
        // compare the new head and new tail
        bool headTail = (head->data == (*next)->data);
        
        // update the next (call by address to update the value)
        *next = (*next)->next;
        
        // return the value
        return (recursiveRes && headTail);
    }
}


void testRecusion()
{
    int arr2[] = {0,1,2,3,4,4,2,1,0};
    LinkedList lst2(arr2,9);
    std::cout << isPalindrome3(lst2.head,9) <<'\n';
    
    int arr3[] = {0,1,2,3,4,3,2,1,0};
    LinkedList lst3(arr3,9);
    std::cout << isPalindrome3(lst3.head,9)<<'\n';
}
