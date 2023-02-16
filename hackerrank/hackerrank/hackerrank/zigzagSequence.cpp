//
//  zigzagSequence.cpp
//  hackerrank
//
//  Created by Luyang Tang on 15/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <iostream>
#include <vector>

using namespace::std;

void zigzagSequence::test(){
    
    vector<int> a{2, 3, 5, 1, 4, 6, 0, 10, 13, 12};
    
    findZigZagSequence(a, a.size());
    
    
}

void zigzagSequence::findZigZagSequence(vector < int > a, int n){

    
    sort(a.begin(), a.end());
    int mid = (n - 1)/2;
    swap(a[mid], a[n-1]);

    int st = mid + 1;
    int ed = n - 2;
    while(st <= ed){
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1;
    }
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}
