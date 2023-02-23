#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](auto c) {return
            !std::isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](auto c) {return
            !std::isspace(c);}).base(),
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


int main(){

    
    string n_query;
    getline(cin, n_query);
    
    Editor *editor = new Editor();
    
    int n = stoi(n_query);
    
    for (int i = 0; i < n; i++){
        string arr_temp_temp;
        getline(cin, arr_temp_temp);
        
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
    }
    
    delete editor;
    
    return 0;
    
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
    // type 2
    string tmp;
    tmp.append(s.substr(0, s.size() - k));
    setAction("2", s.substr(s.size() - k, k), to_string(k)); memory.push(action);
    s = tmp;
    
    return tmp;
}


string Editor::undeleteElement(string deleted, int k){
    string tmp;
    tmp.append(s.substr(0,k-1));
    tmp.append(deleted);
    s = tmp;
    return deleted;
}

void Editor::undo(){
    const vector<string> lastAction = memory.top();
    int lastActionType = stoi(lastAction[0]);
    string lastActionValue = lastAction[1];
    int position = stoi(lastAction[2]);
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
    }
}