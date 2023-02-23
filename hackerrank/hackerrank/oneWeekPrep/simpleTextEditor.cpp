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

/*
 Headers
 */


class Editor{
private:
    string unappend(int);
    string undeleteElement(string);
    vector<string> action; // type, string, position
    
public:
    string s;
    stack<vector<string>> memory;
    
    Editor(){}
    void undo();
    string append(string);
    string deleteElement(int);
    
    void setAction(string, string);
    void print(int);
};


ostream &operator<<(ostream&, const stack<vector<string>> &);
ostream &operator<<(ostream &, const Editor &);
void action(Editor *, int, string);



void simpleTextEditor::test(){

    
    std::ifstream input("/Users/luyangtang/Documents/cracking_the_code_interview/hackerrank/simpleEditor/testcase.txt");
  
    string n_query;
    getline(input, n_query);
    
    Editor *editor = new Editor();
    
    int n = stoi(n_query);
    
    for (int i = 0; i < n; i++){
        string arr_temp_temp;
        getline(input, arr_temp_temp);
        
        vector<string> arr_temp = split(rtrim(arr_temp_temp));
        
        int type = stoi(ltrim(rtrim(arr_temp[0])));
        string value = arr_temp[1];
        
        action(editor, type, value);
    }
    
    delete editor;
    
    exit(0);
    
}


void action(Editor *editor, int type, string value){

    
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
            {
                editor->print(stoi(ltrim(rtrim(value))));
                break;
            }
        case 4:
            {
                editor->undo();
                break;
            }
    }
//    cout << "Action type "<< type << ", action value is " << value << " String is now " << editor->s << endl;
}


ostream &operator<<(ostream& out, const stack<vector<string>> &memory){

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
    setAction("1", to_string(position));
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


void Editor::setAction(string type, string value){
    action = {type, value};
}

string Editor::deleteElement(int k){
    // type 2
    string tmp;
    tmp = s.substr(s.size() - k, k);
    setAction("2", tmp); memory.push(action);
    s = s.substr(0, s.size() - k);
    
    return tmp;
}


string Editor::undeleteElement(string deleted){
    s = s.append(deleted);
    return deleted;
}

void Editor::undo(){
    const vector<string> lastAction = memory.top();
    int lastActionType = stoi(lastAction[0]);
    string lastActionValue = lastAction[1];
//    int position = stoi(lastAction[2]);
    switch (lastActionType){
        case 1:
            {
                unappend(stoi(lastActionValue));
                memory.pop();
                break;
            }
        case 2:
            {
                undeleteElement(lastActionValue);
                memory.pop();
                break;
            }
        default:
            break;
    }
}
