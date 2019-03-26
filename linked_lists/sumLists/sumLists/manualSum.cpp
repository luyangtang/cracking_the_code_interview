//
//  manualSum.cpp
//  sumLists
//
//  Created by LYT on 26/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "mySolution.h"
#include "manualSum.h"

List * manualSum(List *lst1, List *lst2)
{
    Node *current1 = lst1->head;
    Node *current2 = lst2->head;
    
    List *sum = new List;
    Node *current = sum->head;
    
    int tmp = 0;
    bool decFlag = 0;
    
    while(current1->next != nullptr & current2->next != nullptr)
    {
        tmp = current1->data + current2->data;
        
        // 进位 from prev step
        Node *tmpNode = new Node;
        tmpNode->data = decFlag ?1:0;
        
        // 进位 for current step
        decFlag = (tmp + tmpNode->data) > 9;
        tmpNode->data += (tmp + (decFlag ? (-10) : 0)); // 进位
        //        std::cout << tmpNode->data << ' ';
        // append it to the list
        sum->append(tmpNode);
        
        // move to the next
        current1 = current1 -> next;
        current2 = current2 -> next;
        //        decFlag = false;
        current = current -> next;
    }
    
    if (current1 -> next != nullptr)
    {
        tmp = current1->data + (decFlag?1:0);
        Node *tmpNode = new Node(tmp);
        sum->append(tmpNode);
    }
    else if (current2 -> next != nullptr)
    {
        tmp = current2->data + (decFlag?1:0);
        Node *tmpNode = new Node(tmp);
        sum->append(tmpNode);
    }
    
    // move the head to one step ahead
    current = sum->head;
    sum->head = sum->head->next;
    delete current;
    
    return sum;
}



void testManualSum()
{
    int arr1[] = {7,1,6,1};
    int arr2[] = {5,9,4};
    
    List *lst1 = new List(arr1,4);
    List *lst2 = new List(arr2,3);
    
    List *sum = manualSum(lst1, lst2);
    sum->print();
    
    delete lst1;
    delete lst2;
    delete sum;
}
