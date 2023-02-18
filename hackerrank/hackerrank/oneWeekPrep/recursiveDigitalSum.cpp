//
//  recursiveDigitalSum.cpp
//  hackerrank
//
//  Created by Luyang Tang on 18/02/2023.
//

#include <stdio.h>
#include <iostream>
#include "hackerrank.h"

using namespace::std;

void recursiveDigitalSum::test(){
    cout << recursiveDigitalSum::superDigit("23659788316494", 10000) << endl;
};



int recursiveDigitalSum::superDigit(std::string n, int k){
    
//    long nInt = stoi(n);
    
    // base case
    if (k == 1 && n.size() == 1) return stoi(n);
    
    // otherwise calculate the superdigit
    string digitAsStr;
    long superdigit = 0;
    for (string::iterator it = n.begin(); it != n.end(); it++){
        digitAsStr = *it;
//        cout << stoi(digitAsStr) << " " << *it << " ";
        superdigit += stoi(digitAsStr);
    }
    cout << superdigit << " ";
    superdigit = superdigit * k;
    
    cout << superdigit << endl;
    
    return superDigit(to_string(superdigit), 1);
};
