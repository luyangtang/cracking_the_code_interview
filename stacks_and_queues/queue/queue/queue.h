//
//  queue.hpp
//  queue
//
//  Created by LYT on 08/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef queue_h
#define queue_h
#define MAX 1000
#include <stdio.h>
#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    
    Node(T _data, Node *_next = nullptr): data(_data), next(_next){}
};


template <typename T>
class List
{
public:
    Node<T> *head;
    
    
    // constructor
    List(Node<T> *_head=nullptr): head(_head){}
    List(T arr[], int arrLen)
    {
        head = new Node<T>(arr[0]);
        Node<T> *current = head;
        
        for (int i = 1; i < arrLen; i++)
        {
            current->next = new Node<T>(arr[i]);
            current = current->next;
        }
    }
    
    // destructor
    ~List()
    {
        Node<T> *current = head;
        Node<T> *tmp = current;
        
        while (current->next != nullptr)
        {
            current = current->next;
            delete tmp;
            tmp = current;
        }
        delete tmp;
        tmp = nullptr;
    }
    
    // print
    void print()
    {
        Node<T> *current = head;
        
        while (current->next != nullptr)
        {
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << current->data << '\n';
    }
};

template <typename T>
class Queue
{
private:
    List<T> *list;
    
public:
    Queue(){}
    Queue(T arr[], int arrLen)
    {
        list = new List<T>(arr,arrLen);
    }
    
    ~Queue()
    {
        delete list;
    }
    
    // member functions
    T add(T _new)
    {
        Node<T> *current = list->head;
        
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node<T>(_new);
        
        return _new;
    }
    
    T remove()
    {
        Node<T> *tmp = list->head;
        if (list->head->next != nullptr)
            list->head = list->head->next;
        else
            list->head = nullptr;
        return tmp->data;
    }
    
    void print()
    {
        list->print();
    }
};

void testQueue();

#endif /* queue_hpp */
