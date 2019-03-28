//
//  main.cpp
//  circleDetect
//
//  Created by LYT on 26/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <iostream>
#include "mySolution.h"

void testCircleDetectAlg()
{
    int arr[] = {0,1,2,3,4,5};
    
    LinkedList myLst(arr,6);
    myLst.testLoopAlg();
    myLst.append(myLst.head);
    myLst.testLoopAlg();
}


int main() {
    
    testCircleDetectAlg();
    return 0;
}
