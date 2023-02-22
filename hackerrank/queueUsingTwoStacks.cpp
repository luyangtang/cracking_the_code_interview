#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


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
        if (flag) stack2->push(i); else stack1->push(i);
        front = size == 0? i: front; size++;
        return i;
    }
    
    int dequeue(){
        stack<int> *tmpNonEmpty = flag?stack2:stack1;
        stack<int> *tmpEmpty = flag?stack1:stack2;
        
        // swap the stacks
        int n = tmpNonEmpty->size();
        int moved;
        for (int i = 0; i < n; i++){
            moved = tmpNonEmpty->top();
            tmpNonEmpty->pop();
            tmpEmpty->push(moved);
        } flag = !flag; size--;
        
        // after swapping, pop from the other stack
        int popped = tmpEmpty->top();
        tmpEmpty->pop(); front = tmpEmpty->size() > 0?tmpEmpty->top():-999999;
        return popped;
    }
};


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    

    string n_query;
    getline(cin, n_query);

    int n = stoi(ltrim(rtrim(n_query)));
        // create a queue
        Queue *queue = new Queue();

    for (int i = 0; i < n; i++){
        string arr_temp_temp;
        getline(cin, arr_temp_temp);

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
        // cout << " Type " << type <<" Queue: " << *queue << " Top: " << queue->getTop() << endl;
        // cout << type << " " <<endl;
    }
    
    return 0;
}
