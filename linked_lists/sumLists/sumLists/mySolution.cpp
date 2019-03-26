//
//  mySolution.cpp
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


// initialise
Node::Node(int _data, Node *_next)
{
    data = _data;
    next = _next;
}

// copy constructor
Node::Node(Node *newNode)
{
    data = newNode->data;
    next = newNode->next;
}

List::List()
{
    head = new Node();
    len = 1;
}

// initialise with an array
List::List(int arr[], int _arrLen)
{
    head = new Node(*arr);
    Node *current = head;
    len = _arrLen;
    for (int i = 0; i < _arrLen; i++)
    {
        current -> next = new Node(*(arr+i+1));
        //std::cout << current->data << ' ';
        current = current -> next;
    }
}

// destructor
List::~List()
{
    Node *current = this->head;
    Node *tmp = current->next;
    for (int i = 0; i < len; i++)
    {
        delete current;
        current = tmp;
        tmp = current->next;
        len--;
    }
}

// append
void List::append(Node *newNode)
{
    Node *current = this->head;
    while(current->next!=nullptr)
    {
        current = current->next;
    }
    current->next = new Node(newNode);
    len++;
    
}

// print
void List::print() const
{
    Node *current = this->head;
    for (int i = 0; i < len; i++)
    {
        if (current != nullptr)
        {
            std::cout << current->data << ' ';
            current = current -> next;
        }
    }
}


// calculate numerical value
int List::getValue() const
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += pow(10,(i-1)) * i;
    }
    //        this->print();
    //        std::cout << sum << '\n';
    return sum;
}

// sum of two lists
List* List::operator+ (const List&list2)
{
    int sum = this->getValue() + list2.getValue();
    List *sumList = getListFromInt(sum);
    return sumList;
}


void testOverride()
{
    int arr[] = {0,1,2,3,4,5};
    int arr2[] = {1,2,3};
    List list1(arr,6);
    List list2(arr2,3);
    std::cout << list1 + list2 << '\n';
    
}



List* getListFromInt(int _int)
{
    using namespace std;
    // use a string cast to get the digits
    string outString;
    stringstream ss;
    ss << _int;
    outString = ss.str();
    
    // for each digit in the list, put the digit in the list;
    List *outList = new List();
    outList->head->data = stoi(static_cast<string>(outString.substr(0,1)));
    Node *tmp;
    for (int i = 1; i < outString.length(); i++)
    {
        tmp = new Node(stoi(outString.substr(i,1)));
        outList->append(tmp);
        delete tmp;
    }
    
    return outList;
}


void testListFromInt()
{
    List *myList = getListFromInt(123);
    myList->print();
}


void testMySolution()
{
    int arr[] = {0,1,2,3,4,5};
    int arr2[] = {1,2,3};
    List list1(arr,6);
    List list2(arr2,3);
    List *sumList = list1 + list2;
    sumList->print();
}
