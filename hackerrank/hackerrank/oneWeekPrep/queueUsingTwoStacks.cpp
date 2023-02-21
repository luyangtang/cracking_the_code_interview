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
    int flag;
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
        flag = 0;
    }
    
    int getTop() const{
        return top;
    }
    
    int enqueue(int i){
        
        if (stack1->getTop() == 0 && stack2->getTop() == 0) top = i;
        
        Stack *tmp = flag ? stack2 : stack1;
        tmp->push(i);
        
        return i;
    }
    
    int dequeue(){
        
        Stack *tmpNonEmpty;
        Stack *tmpEmpty;

        
        tmpNonEmpty = flag ? stack2 : stack1;
        tmpEmpty = flag ? stack1 : stack2;
        
        flag =  1 - flag;
        
        int n = tmpNonEmpty->getTop();
        for (int i = 0; i < n; i++){
            
            // when i = 0, update the top
            if (flag == 0 && i == 0){
                top = tmpNonEmpty->getTop() >0 ? tmpNonEmpty->getArr()->back() : 0;
            }
            
            tmpEmpty->push(tmpNonEmpty->pop());
        }

        // pop from the 'empty'
        int popped = tmpEmpty->pop(); n--;
        if (flag == 1){
            top = tmpEmpty->getTop() >0 ? tmpEmpty->getArr()->back() : 0;
        }
        return popped;
    }
    
    
    vector<int>* getArr() const{
        return flag ? stack2->getArr():stack1->getArr();
    }
};


ostream& operator<<(ostream &out, const Queue &s){
    
    out << "flag " << s.flag << " ";
    out << "(";
    
    if (!s.flag){
        for (vector<int>::iterator it = s.getArr()->end()-1; it != s.getArr()->begin()-1; it--){
            out << *it << " ";
        }
    }else{
        for (vector<int>::iterator it = s.getArr()->begin(); it != s.getArr()->end(); it++){
            out << *it << " ";
        }
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
    
//    Queue *queue = new Queue({1,2,3});
    
    
    /*
     STDIN   Function
     -----   --------
     10      q = 10 (number of queries)
     1 42    1st query, enqueue 42
     2       dequeue front element
     1 14    enqueue 42
     3       print the front element
     1 28    enqueue 28
     3       print the front element
     1 60    enqueue 60
     1 78    enqueue 78
     2       dequeue front element
     2       dequeue front element
     */
    
    Queue *queue = new Queue();
    cout << *queue << " Top: " << queue->getTop() << endl;
    
    queue->enqueue(42);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(14);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(28);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(60);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(78);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(14);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(28);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->enqueue(50);
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
    
    queue->dequeue();
    cout << *queue << " Top: " << queue->getTop()<< endl;
}
