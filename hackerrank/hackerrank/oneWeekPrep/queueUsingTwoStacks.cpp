//
//  queueUsingTwoStacks.cpp
//  hackerrank
//
//  Created by Luyang Tang on 19/02/2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include "hackerrank.h"
#include <fstream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace::std;
using namespace::utils;


class Queue{
    
public:
    stack<int> *stack1;
    stack<int> *stack2;
    int flag; // 0 - stack1, 1 - stack2
    int front;
    int size;
    
    Queue(){
        stack1 = new stack<int>; stack2 = new stack<int>; flag = 0; size = 0;
    }
    
    Queue(vector<int> arr){
        stack1 = new stack<int>; stack2 = new stack<int>; flag = 0; size = arr.size(); front = arr.front();
        
        for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
            stack1->push(*it);
        }
    }
    
    ~Queue(){
        delete stack1; delete stack2;
    }
    
    int enqueue(int i){
        
        stack1->push(i);
        front = size == 0?i:front;
        size++;
        
        return i;
    }
    
    int dequeue(){
        // swap the stacks
        for (int i = 0; i < size; i++){
            stack2->push(stack1->top());
            stack1->pop();
        }
        
        // pop from stack 2
        int popped = stack2->top();
        stack2->pop(); size--;
        front = size == 0? -9999:stack2->top();
        
        // swap the stacks
        for (int i = 0; i < size; i++){
            stack1->push(stack2->top());
            stack2->pop();
        }
        
        return popped;
    }
};



ostream& operator<<(ostream &out, const Queue &q){
    
    // create a shadow stack so as to print out the queue
    stack<int> *s = new stack<int>;
    *s = *(q.stack1);
    
    vector<int> *arr = new vector<int>;
    
    int n = s->size();
    
    if (n > 0){
        for (int i = 0; i < n; i++ ){
            arr->push_back(s->top());
            s->pop();
        }
    }
    
    cout << "( ";
    for (vector<int>::iterator i = arr->end()-1; i != arr->begin()-1; i--){
        cout << *i << " ";
    }
    
    cout << ") ";
    
    delete arr; delete s;
    
    return out;
}



void queueUsingTwoStacks::test(){

    
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
    
//    Queue q({1,2,3});
    std::ifstream input("/Users/luyangtang/Documents/cracking_the_code_interview/hackerrank/queueUsingTwoStacks/testcases/queueUsingTwoStacks.txt");
  
    string n_query;
    getline(input, n_query);
    cout << n_query << endl;
    
    int n = stoi(n_query);
            // create a queue
            Queue *queue = new Queue();

        for (int i = 0; i < n; i++){
            string arr_temp_temp;
            getline(input, arr_temp_temp);

            vector<string> arr_temp = split(rtrim(arr_temp_temp));
            
            int type = stoi(ltrim(rtrim(arr_temp[0])));
            
            
            if (type == 1){
                int value = stoi(ltrim(rtrim(arr_temp[1])));
                queue->enqueue(value);
                
            } else if (type == 2){
                
                queue->dequeue();
                
            } else {
                cout << queue->front << endl;
            }
             cout << "     Type " << arr_temp_temp << *queue << " Top: " << queue->front<< endl;
//             cout << type << " " <<endl;
        }
    
    
//    Queue q;
//    cout << "size = " << q.size << ", front is " << q.front << endl;
    
//    q.enqueue(4);
//    cout << "size = " << q.size << ", front is " << q.front << endl;
    
//    q.dequeue();
//    cout << "size = " << q.size << ", front is " << q.front << endl;
    

}
