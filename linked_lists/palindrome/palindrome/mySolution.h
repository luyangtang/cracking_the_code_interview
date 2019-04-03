//
//  mySolution.h
//  palindrome
//
//  Created by LYT on 30/03/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_h
#define mySolution_h

class Node
{
public:
    int data;
    Node *next;
    
    // constructor
    Node (int _data, Node *_next = nullptr);
    
    // constructor (from a node)
    Node (Node *_node, Node *_next = nullptr);
};


class LinkedList
{
public:
    Node *head;
    int len;
    
    LinkedList(int arr[], int arrLen);
    LinkedList(Node *_head);
    ~LinkedList();
    void print();
    LinkedList *reverse();
    
    // my solution
    bool isPalindrome();
    
    // using stack
    bool isPalindrome2();
    
    // using recursion
    bool isPalindrome3();
    
};


void testLinkedList();
void testIsPalindrome();

#endif /* mySolution_h */
