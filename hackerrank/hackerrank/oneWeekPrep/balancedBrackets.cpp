//
//  balancedBrackets.cpp
//  hackerrank
//
//  Created by Luyang Tang on 21/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <iostream>
#include <string>
#include <stack>

using namespace::std;

string isBalanced(string);

void balancedBrackets::test(){
    
    vector<string> testCases = {
        "{(([])[])[]}",
        "{(([])[])[]]}",
        "{(([])[])[]}[]",
        "(((((((",
        "{()({}[[{}]]()(){[{{}{[[{}]{}((({[]}{}()[])))]((()()))}(()[[[]]])((()[[](({([])()}))[]]))}]})}",
        "][[{)())))}[)}}}}[{){}()]([][]){{{{{[)}]]{([{)()][({}[){]({{"
    };
    
    for (vector<string>::iterator it = testCases.begin(); it != testCases.end(); ++it)
        cout << isBalanced(*it) << endl;
}

class Bracket{
public:
    string symbol;
    int side; // 0 - left, 1 - right
    int group; // 0 - (, 1 - [, 2 - {

    
    Bracket(char s){
        symbol = s;
        if (s == '{' || s == '[' || s == '(') {side = 0;} else {side = 1;}
        if (s == '{' || s == '}') group = 2; else if (s == '[' || s == ']') group = 1;
    }
};

string isBalanced(string s) {
    
    stack<Bracket *> brackets;
    
    if (s.size() % 2 != 0) return "NO";
    
    for (string::iterator it = s.begin(); it != s.end(); it++){
        
        Bracket *bracket = new Bracket(*it);
        
        cout << bracket->group << " ";
        
        // if it is the first entry or the stack is 0, just push to the stack
        if (it == s.begin() || brackets.size() == 0){
            if (bracket->side == 1) return "NO";
            else brackets.push(bracket);
        }
        
        // if the side is opposite to the top of the stack
        else if (brackets.top()->side != bracket->side){
            // when the new bracker is of the same group, pop the top out
            if(brackets.top()->group == bracket->group) brackets.pop();
            // otherwise return "no"
            else return "NO";
        }
            
        // else push the bracket
        else brackets.push(bracket);
        
    }
    
    if (brackets.size() > 0) { return "NO";}

    return "YES";
}
