//
//  simpleTextEditor.cpp
//  hackerrank
//
//  Created by Luyang Tang on 22/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>

using namespace std;
using namespace utils;


class Editor{
private:
    string unappend(int);
    string undeleteElement(string, int);
    vector<string> action; // type, string, position
    
public:
    string s;
    stack<vector<string>> memory;
    
    Editor(){}
    void undo();
    string append(string);
    string deleteElement(int);
    
    void setAction(string, string, string);
    void print(int);
};


ostream &operator<<(ostream&, const stack<vector<string>> &);
ostream &operator<<(ostream &, const Editor &);




// Editor methods





void simpleTextEditor::test(){

    
    std::ifstream input("/Users/luyangtang/Documents/cracking_the_code_interview/hackerrank/simpleEditor/testcase.txt");
  
    string n_query;
    getline(input, n_query);
//    cout << n_query << endl;
    
    Editor *editor = new Editor();
    
    int n = stoi(n_query);
    
    for (int i = 0; i < n; i++){
        string arr_temp_temp;
        getline(input, arr_temp_temp);
        
        vector<string> arr_temp = split(rtrim(arr_temp_temp));
        
        int type = stoi(ltrim(rtrim(arr_temp[0])));
        string value = arr_temp[1];
        
        switch (type) {
            case 1:
                {
                    editor->append(value);
                    break;
                }
            case 2:
                {
                    int k = stoi(ltrim(rtrim(value)));
                    //s = deleteElement(s, k);
                    editor->deleteElement(k);
                    break;
                }
            case 3:
//                cout << "the " << value << "-th character of " << s << " is " << s[stoi(ltrim(rtrim(value))) - 1] << endl;
                {
                    editor->print(stoi(ltrim(rtrim(value))));
                    break;
                }
            case 4:
//                cout << value << endl;
                {
                    editor->undo();
                    break;
                }
        }
        cout << "Action type "<< type << ", action value is " << value << " String is now " << editor->s << endl;
        
    }
    
    delete editor;
    
    exit(0);
    
}
//
//ostream &operator<<(ostream &out, const vector<string> &v){
//    for (vector<string>::iterator it = v.begin(); it <= v.end(); it++){
//        cout << *it << " ";
//    }
//}


ostream &operator<<(ostream& out, const stack<vector<string>> &memory){
    /*
     vector<string> action1 = {"3", "abd"}; vector<string> action2 ={"2", "x"};
     stack<vector<string>> *memory = new stack<vector<string>>;
     memory->push(action1); memory->push(action2);
     cout << *memory << endl;
     */
    stack<vector<string>> *tmp = new stack<vector<string>>;
    vector<string> action;
    *tmp = memory;
    
    int n = memory.size();
    if (n){
        for (int i = 0; i < n; i++){ // loop through the stack
            out << "(";
            action = tmp->top();
            // loop through the action vector
            for (vector<string>::iterator it = action.begin(); it != action.end(); it++)
                {
                    out << *it << " ";
                }
            out << ")";
            tmp->pop();
        }
    }
    
    delete tmp;
    return out;
}



ostream &operator<<(ostream &out, const Editor &editor){
    out << "Editor's current string - " << editor.s << endl;
    out << "    Memory stack (newest at top): " << editor.memory << endl;
    return out;
}


string Editor::append(string w){
    // type 1
    int position = s.size();
    s.append(w);
    setAction("1", "", to_string(position));
    memory.push(action);
    return w;
}

string Editor::unappend(int k){
    s = s.substr(0, k);
    return s;
}


void Editor::print(int k){
    cout << s[k - 1] << endl;
}


void Editor::setAction(string type, string value, string pos){
    action = {type, value, pos};
}

string Editor::deleteElement(int k){
    // type 1
    string tmp;
    tmp.append(s.substr(0, s.size() - k));
//    tmp.append(s.substr(k, s.size() - k + 1));
    setAction("2", s.substr(s.size() - k, k), to_string(k)); memory.push(action);
    s = tmp;
    
    return tmp;
//
//    string tmp;
//    for (string::iterator it = s.begin(); it != s.end(); it++){
//        if ((s.end() - it) != k) tmp.push_back(*it);
//    };
//
//    return tmp;
}


string Editor::undeleteElement(string deleted, int k){
    string tmp;
    tmp.append(s.substr(0,k-1));
    tmp.append(deleted);
//    tmp.append(s.substr(k - 1,s.size() - k + 1));
    s = tmp;
    return deleted;
}

void Editor::undo(){
    const vector<string> lastAction = memory.top();
    int lastActionType = stoi(lastAction[0]);
    string lastActionValue = lastAction[1];
    int position = stoi(lastAction[2]);
//    cout << "last action type "<<lastActionType <<" ";
    switch (lastActionType){
        case 1:
            {
                unappend(position);
                memory.pop();
                break;
            }
        case 2:
            {
                undeleteElement(lastActionValue, position);
                memory.pop();
                break;
            }
        case 3:
            break;
    }
}
