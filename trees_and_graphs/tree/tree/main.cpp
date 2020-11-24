//
//  main.cpp
//  tree
//
//  Created by LYT on 17/11/2020.
//  Copyright © 2020 Kiki Tan. All rights reserved.
//



#include <stdio.h>
#include <iostream>

#include "Node.h"
#include "Tree.hpp"


void printTree(Node *root)
{
    //    std::cout << root->numChildren;
    
    if (root->numChildren == 0)
    {
        // no children can be found
        std::cout << root->name << " ";
    }
    else
    {
        // loop through the children of the root if there is any
        std::cout << root->name << " ";
        
        for (int i = 0; i < root->numChildren; i++)
        {
            printTree((root->children)+i);
        }
    }
    
}

class Tree{
    
public:
    Node *root;
    
    //    Contructor
    Tree(Node *_root)
    {
        root = _root;
    }
    
    //    print
    void print()
    {
//        recursively print the tree
        
        printTree(root);
        
        std::cout << '\n';
    }
};






int main(int argc, const char * argv[]) {
    
//    testTreeNode();
    Node node2 = Node(2);
    Node node3 = Node(3);
    Node node4 = Node(4);
    Node children1[] = {node2, node3};
    Node node1 = Node(1, children1, 2);
    Node children0[] = {node1, node4};
    Node *root = new Node(0, children0, 2);
    
//    Node *root = new Node(1);
//    root->printChild();
    
    Tree *tree = new Tree(root);
    tree->print();
    
//    printTree(root);
    delete root;
    
    return 0;
}
