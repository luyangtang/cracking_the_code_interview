//
//  mergeTwoSortedLinkedList.cpp
//  hackerrank
//
//  Created by Luyang Tang on 19/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <iostream>
#include <vector>

using namespace::std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << endl;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode *mergedHead = new SinglyLinkedListNode(0);
    SinglyLinkedListNode *mergedRunner = mergedHead;
    SinglyLinkedListNode *runner1 = head1;
    SinglyLinkedListNode *runner2 = head2;
    
    bool test = true;
    
    while (runner1 != nullptr || runner2 != nullptr){
        
        if (runner1 == nullptr){
            if (test) {cout << "Case 1 " << "Runner 2 = " << runner2->data  << "(" << runner2 << ") "<< endl;}
            mergedRunner->next = new SinglyLinkedListNode(runner2->data);
            runner2 = runner2->next;
        }
        else if (runner2 == nullptr){
            if (test) {cout << "Case 2 "  << "Runner 1 = " << runner1->data << "(" << runner1 <<  ") "<< endl;}
            mergedRunner->next = new SinglyLinkedListNode(runner1->data);
            runner1 = runner1->next;
        }
        else {
            if (test) {cout << "Case 3 "  << "Runner 1 = " << runner1->data << "(" << runner1 << "),  Runner 2 = " << runner2->data  << "(" << runner2 << "); " <<endl;}
            if (runner1->data < runner2->data){
                mergedRunner->next = new SinglyLinkedListNode(runner1->data); runner1 = runner1->next;
            }
            
            else {
                mergedRunner->next = new SinglyLinkedListNode(runner2->data); runner2 = runner2->next;
            }
        }
        mergedRunner = mergedRunner->next;
    }
    
    return mergedHead->next;
}



void mergeTwoSortedLinkedList::test(){
    
//    vector<int> v1 = {1,3,7};
//    vector<int> v2 = {1,2};
    
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {3,4};
//
//    vector<int> v1 = {4,5,6};
//    vector<int> v2 = {1,2,10};
    
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    SinglyLinkedList* llist2 = new SinglyLinkedList();


    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        llist1->insert_node(*it);
    }
    
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        llist2->insert_node(*it);
    }
    
    print_singly_linked_list(llist1->head, " ");
    print_singly_linked_list(llist2->head, " ");
    
    SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
    print_singly_linked_list(llist3, " ");
    
}
