//
//  main.cpp
//  partition
//
//  Created by LYT on 04/02/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "mySolution.h"

Node* partition2 (Node *head, int parVal)
{
    // if only one list then just return
    if (head->next == nullptr)
        return head;
    else
    {
        // given a list use recursive calls to partition from the second element
        Node *newHead = partition2(head->next, parVal);
        
        // then deal with the first element
        // start from the second element
        Node *end = newHead->next;
        while (end->next!=nullptr)
        {
            end = end->next;
        }
        
        // compare the head then send it to the back
        if (head->data > parVal)
        {
            // update end
            end->next = new Node(head->data);
            end = end->next;
            
            // remove the head
            Node *tmp = new Node(head->data);
            head = head->next;
            delete tmp;
        }
        else // keep it and link it to the rest
        {
            head->next = newHead;
        }
        return newHead;
    }
}

void testPartition2()
{
    int arr[] = {0,1,2,3,4,5,6};
    linkedList lst(arr,7);
    partition2(lst.head,5);
    lst.print();
}

int main()
{
    int arr[] = {3,5,8,5,10,2,1};
    linkedList lst(arr,7);
    partition2(lst.head,5);
    lst.print();
    return 0;
}
