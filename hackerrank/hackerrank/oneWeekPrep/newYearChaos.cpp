//
//  newYearChaos.cpp
//  hackerrank
//
//  Created by Luyang Tang on 18/02/2023.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "hackerrank.h"

using namespace::std;
//using namespace::newYearChaos;

void newYearChaos::test(){
    
    vector<vector<int>> testCases = {
        {2, 1, 5, 3, 4},
        {2, 5, 1, 3, 4}
    };
    
    for (vector<vector<int>>::iterator it = testCases.begin(); it != testCases.end(); it++){
        
        for (vector<int>::iterator subit = it->begin(); subit != it->end(); subit++){
            cout << *subit << " ";
        }
        cout << endl;
        minimumBribes(*it);
        cout << endl;
    }

//    minimumBribes({2, 1, 5, 3, 4});
};


// comment - the fact that the person can only bribe the person next to him should ring the bell of bubble sort.
// the below algorithm is to sort the queue with bubble sorting and return how many times the swaps are done.

void newYearChaos::minimumBribes(vector<int> q){
    
    int count = 0;
    bool debugPrnt = false;
    
    while (!is_sorted(q.begin(), q.end())){
        // implement bubble sort
        
        for (vector<int>::iterator it = q.begin(); it != q.end() - 1; it++){
            
            //            cout << *it << " "<< (*(it+1)) << endl;
            
            // if the sticker - position > 2, it is too chaotic. Return the value immediately
            if (debugPrnt) cout << "Sticker value = " << *it << " and position is "<< it - q.begin() + 1 << endl;
            if (*it - (it - q.begin()) > 3) {
                cout << "Too chaotic"  << endl;
                return;
            }
            
            if (*it > *(it+1)) {
                if (debugPrnt) cout << *it << " is in wrong order and counter is " << count << endl;
                swap(*it, *(it+1));
                count++;
            }
        }
    }
    
    
    cout << count << endl;
};
