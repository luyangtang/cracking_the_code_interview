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





bool LinkedList::isPalindrome2()
{
    Stack stk;
    
    Node *slow = this->head;
    Node *fast = this->head;
    
    while (fast->next->next != nullptr)
    {
        stk.push(slow->data);
        
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;
    stk.push(slow->data);
    
    while (slow->next != nullptr)
    {
        if (stk.pop() != slow->data)
        {
            std::cout << "not palindrome\n";
            return false;
        }
        slow = slow->next;
    }
    std::cout << "is palindrome\n";
    return true;
}



void testFinal()
{
    int arr[] = {0,1,2,3,3,2,1,0};
    LinkedList lst(arr,8);
    lst.isPalindrome2();
    
    int arr2[] = {0,1,2,3,4,2,1,0};
    LinkedList lst2(arr2,6);
    lst2.isPalindrome2();
}

int main()
{
    testFinal();
    return 0;
}
