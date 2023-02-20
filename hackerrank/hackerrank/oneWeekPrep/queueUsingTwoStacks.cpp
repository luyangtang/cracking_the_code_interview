//
//  queueUsingTwoStacks.cpp
//  hackerrank
//
//  Created by Luyang Tang on 19/02/2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "hackerrank.h"

using namespace::std;



class Stack{
private:
    vector<int> *arr;
public:
    ~Stack(){
        delete arr;
    }
    Stack(){
        arr = new vector<int>();
    }
    
    Stack(vector<int> a){
        arr = new vector<int>(a);
    }
    
    int push(int i){
        arr->insert(arr->end(), i);
        return i;
    }
    
    int pop(){
        int i = arr->back();
        arr->pop_back();
        return i;
    }
    
    int getTop() const {
        if (arr){
            return arr->end() - arr->begin();
        }
        else
        {
            return 0;
        }
    }
    
    vector<int>* getArr() const {
        return arr;
    }
    
};


class Queue{
    
private:
    Stack *stack1;
    Stack *stack2;
    int top;
    
public:
    ~Queue(){
        delete stack1;
        delete stack2;
    }
    
    Queue(){
        stack1 = new Stack();
        stack2 = new Stack();
    }
    
    Queue(vector<int> arr){
        stack1 = new Stack(arr);
        stack2 = new Stack();
        top = stack1->getArr()->front();
    }
    
    int getTop(){
        return top;
    }
    
    int enqueue(int i){
        
        Stack *tmp = stack1->getTop() < 1 ? stack2 : stack1;
        tmp->push(i);
        
        return i;
    }
    
    int dequeue(){
        
        Stack *tmpNonEmpty = stack1->getTop() < 1 ? stack2 : stack1;
        Stack *tmpEmpty =stack1->getTop() < 1 ? stack1 : stack2;
        
//        cout << "Before transferring ";
//        for (vector<int>::iterator it = tmpNonEmpty->getArr()->begin(); it!= tmpNonEmpty->getArr()->end(); it++){
//            cout << *it << " ";
//        }
//        cout << " (total " << tmpNonEmpty->getTop() << ")" << endl;
        
        // move everything from non-empty stack to empty stack
        int n = tmpNonEmpty->getTop();
        for (int i = 0; i < n; i++){
            tmpEmpty->push(tmpNonEmpty->pop());
        }

        // pop from the 'empty'
        int popped = tmpEmpty->pop(); n--;
        
        for (int i = 0; i < n; i++){
            int tmp = tmpEmpty->pop();
            if (i == 0) top = tmp; // take a note of the first one
            tmpNonEmpty->push(tmp);
        }
        
        return popped;
    }
    
    
    vector<int>* getArr() const{
        Stack *tmpNonEmpty = stack1->getTop() < 1 ? stack2 : stack1;
        return tmpNonEmpty->getArr();
    }
};


ostream& operator<<(ostream &out, const Queue &s){
    out << "(";
    for (vector<int>::iterator it = s.getArr()->begin(); it != s.getArr()->end(); it++){
        out << *it << " ";
    }
    out << ")";
    
    return out;
}

ostream& operator<<(ostream &out, const Stack &s){
    out << "(";
    for (vector<int>::iterator it = s.getArr()->begin(); it != s.getArr()->end(); it++){
        out << *it << " ";
    }
    out << ")";
    
    return out;
}


void queueUsingTwoStacks::test(){

//    Stack *stack = new Stack({1,2,3});
//    cout << *stack;
//
//    for (int i = 0; i < 3; i++){
//        stack->pop();
//    }
//    cout << *stack;
//    cout <<endl;
    
    Queue *queue = new Queue({1,2,3});
    cout << *queue << " Top: " << queue->getTop() << endl;
    
    queue->enqueue(5);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(10);
    cout << *queue << " Top: " << queue->getTop()<< endl;
}
