//
//  stack.cpp
//  palindrome
//
//  Created by LYT on 02/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "mySolution.h"
#include "stack.h"
#include <iostream>

Stack::Stack()
{
    top = 0;
}
    
Stack::Stack(int _arr[], int arrLen)
{
    int i = 0;
    for (i = 0; i < arrLen; i++)
    {
        arr[i] = _arr[i];
    }
    top = i;
}
    
    // print
void Stack::print()
{
    for (int i = 0; i < top; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}
    
    // pop
int Stack::pop()
{
    if (top <= 0)
    {
        std::cout << "stack underflow\n";
        return 0;
    }
    else
    {
        int x = arr[--top];
        //            std::cout << x << " popped\n";
        return x;
    }
}
    
    
    // push
int Stack::push(int x)
{
    if (top > MAX)
    {
        std::cout << "exceed max\n";
        return 0;
    }
    else
    {
        arr[top++] = x;
        //            std::cout << x << " pushed\n";
        return x;
    }
}
    
    
    // is empty
bool Stack::isEmpty()
{
    return (top > 0);
}



void testStack()
{
    int arr[] = {0,1,2,3,3,2,1,0};
    Stack stk(arr,8);
    stk.pop();
    stk.print();
    
    stk.push(0);
    stk.print();
}




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
