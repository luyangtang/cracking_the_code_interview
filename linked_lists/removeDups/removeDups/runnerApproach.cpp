//
//  runnerApproach.cpp
//  removeDups
//
//  Created by LYT on 31/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "mySolution.h"
#include <iostream>

void linkedList::removeDups2()
{
    // if the length is 1 then we don't need to do anything
    if (len > 1)
    {
        Node *currentNode = head;
        int currentNodeInd = 0;
        Node *runner = head->next;
        int runnerInd = 1;
        
        // for each character in the string, use runner to compare the following string
        while (currentNode->next != nullptr)
        {
            while(runner->next != nullptr)
            {
                // compare currentNode and runner
                if (currentNode->next->data == runner->next->data)
                {
                    // delete runner
                    runner->next = runner->next->next;
                }
                else
                {
                    // move forward
                    runner = runner->next;
                    runnerInd++;
                }
            }
            currentNode = currentNode->next;
            runnerInd = ++currentNodeInd;
            runner = currentNode->next;
        }
        
        this->print();
    }
    
}


void testRemoveDup2()
{
    linkedList myString1("Helloworld"); myString1.removeDups2();
    linkedList myString2("Follow up"); myString2.removeDups2();
    linkedList myString3("apple"); myString3.removeDups2();
}
