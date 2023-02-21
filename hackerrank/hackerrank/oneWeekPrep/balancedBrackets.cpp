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


string isBalanced(string s) {
    
    stack<char> brackets;
    
    if (s.size() % 2 != 0) return "NO";
    
    for (string::iterator it = s.begin(); it != s.end(); it++){
        
        if (*it == '(' || *it == '[' || *it == '{') brackets.push(*it);
        
        else if (brackets.size() == 0) return "NO";
        
        else {
            
            char prev = brackets.top();
            
            if ((prev == '(' && *it == ')') || (prev == '[' && *it == ']') || (prev == '{' && *it == '}')) brackets.pop();
            else return "NO";
        }
    }
    
    if (brackets.size() == 0) return "YES"; else return "NO";
}
