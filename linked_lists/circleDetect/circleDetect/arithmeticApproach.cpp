//
//  arithmeticApproach.cpp
//  circleDetect
//
//  Created by LYT on 28/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "mySolution.h"

bool LinkedList::testLoopAlg()
{
    Node *n1 = head;
    Node *n2 = head;
    
    while(n2 != nullptr)
    {
        n1 = n1->next;
        n2 = n2->next->next;
        
        // will break the loop if they ever meet
        if (n1 == n2)
        {
            std::cout << "there is loop. ";
            
            // decide where is the loop
            // now n1 and n2 are together
            n1 = head;
            while (n1 != n2)
            {
                n1 = n1->next;
                n2 = n2->next;
            }
            std::cout << "loop is at " << n1->data << '\n';
            return true;
        }
    }
    std::cout << "no loop\n";
    return false;
}


void testCircleDetectAlg()
{
    int arr[] = {0,1,2,3,4,5};
    
    LinkedList myLst(arr,6);
    myLst.testLoopAlg();
    myLst.append(myLst.head);
    myLst.testLoopAlg();
}
