//
//  Node.hpp
//  tree
//
//  Created by LYT on 24/11/2020.
//  Copyright © 2020 Kiki Tan. All rights reserved.
//



#ifndef Node_h
#define Node_h



#include <iterator>
#include <stdio.h>
#include <iostream>


class Node {
public:
    int name;
    Node *children;
    int numChildren;
    
    //    constructor
    Node(int _name, Node _children[] = nullptr, int _numChildren = 0);
    
    //    print tree child
    void printChild();
};


void testTreeNode();



#endif /* Node_hpp */
