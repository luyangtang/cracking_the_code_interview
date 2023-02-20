#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

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
        if (stack1->getTop() == 0 && stack2->getTop() == 0) top = i;
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
            cout << queue->getTop() << endl;
        }
        // cout << " Type " << type <<" Queue: " << *queue << " Top: " << queue->getTop() << endl;
        // cout << type << " " <<endl;
    }
    
    return 0;
}
