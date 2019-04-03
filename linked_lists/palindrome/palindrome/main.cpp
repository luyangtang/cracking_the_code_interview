//
//  main.cpp
//  palindrome
//
//  Created by LYT on 29/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//


#include <iostream>
#include "mySolution.h"
#include "stack.h"

bool LinkedList::isPalindrome3()
{
    return true;
}


bool isPalindrome3(Node *head, int lstLen, Node **next = nullptr)
{

    
    if (lstLen == 1)
    {
        next = &head;
        return true;
    }
    else if (lstLen == 0)
    {
        next = &head;
        return true;
    }
    else
    {
        bool recursiveRes = isPalindrome3(head->next, lstLen-2, &(*next));
        *next = (*next)->next;
        
        bool res = (recursiveRes && (head->data != (*next)->data));
                std::cout << "currently " << head->data
                        << "h, " << (*next)->data << "b, " << lstLen << '\n';
        return res;
    }
}


void testRecusion()
{
//    int arr[] = {0,1,2,3,3,2,1,0};
//    LinkedList lst(arr,8);
//    std::cout << lst.isPalindrome3()<<'\n';
    
    Node **next;
    int arr2[] = {0,1,2,3,4,2,1,0};
    LinkedList lst2(arr2,8);
    std::cout << isPalindrome3(lst2.head,8,next)<<'\n';
//
//    int arr3[] = {0,1,2,3,2,1,0};
//    LinkedList lst3(arr3,7);
//    std::cout << lst3.isPalindrome3()<<'\n';
}


int main()
{
    testRecusion();
    return 0;
}
