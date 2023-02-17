//
//  lonelyInteger.cpp
//  hackerrank
//
//  Created by Luyang Tang on 15/02/2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "hackerrank.h"

using namespace std;
using namespace lonelyInteger;

void lonelyInteger::test(){
    
    vector<int> a{1,2,3,4,3,2,1};
    cout << lonelyInteger(a) << endl;
}

int lonelyInteger::lonelyInteger(vector<int> a) {
    
    // sort the function
    std::sort(a.begin(), a.end());
    
    // if length == 1
    if (a.size() == 1) {
        return *a.begin();
    }
    
    // otherwise the vector will have at least 3 elements
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it){
        //        cout << *it << " ";
        
        // case 1 if the first entry is a lonely number (the next one is different)
        if ((it == a.begin()) && (*(it+1) != *it)) {
            return *it;
        }
        
        // case 2 if no lonely number has been found as the programme reaches the end of the vector
        else if (it == a.end()) {
            return *it;
        }
        
        // case 3 in the middle of the list
        else if ((*(it-1) != *it) && (*(it+1) != *it))
            {
            return *it;
        }
    }
    
    cout << endl;
    
    return 0;
}

