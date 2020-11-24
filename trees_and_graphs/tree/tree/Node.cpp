//
//  Node.cpp
//  tree
//
//  Created by LYT on 24/11/2020.
//  Copyright © 2020 Kiki Tan. All rights reserved.
//

#include "Node.h"

Node::Node(int _name, Node _children[], int _numChildren){
    name = _name;
    children = _children;
    numChildren = _numChildren;
}


void Node::printChild()
{
    std::cout << "Node " << name << ", Children(" ;
    for (int i = 0; i < numChildren; i++)
    {
        std::cout << (children + i)->name << ",";
    }
    
    std::cout << ")\n";
}



void testTreeNode()
{
    Node node2 = Node(2);
    Node node3 = Node(3);
    Node children[] = {node2, node3};
    Node *node = new Node(1, children, 2);
    
    node->printChild();
    delete node;
}
