//
//  queue.cpp
//  queue
//
//  Created by LYT on 08/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "queue.h"

void testQueue()
{
    int arr[] = {0,1,2,3,4,5};
    List<int> list(arr,6);
    
    Queue<int> q(arr,6);
    q.print();
    
    q.add(6);
    q.add(7);
    q.add(8);
    q.print();
    
    q.remove();
    q.remove();
    q.print();
}
