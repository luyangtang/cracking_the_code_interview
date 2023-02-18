//
//  gridChallenge.cpp
//  hackerrank
//
//  Created by Luyang Tang on 17/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <vector>
#include <string>
#include <iostream>

using namespace::std;

void gridChallenge::test(){
    vector<string> grid{
        "ebacd", "fghij", "olmkn", "trpqs", "xywuv"
    };
    

    
    cout << gridChallenge::gridChallenge(grid) << endl;


};

string gridChallenge::gridChallenge(vector<string> grid){
    
    // sort each row
    for (vector<string>::iterator it = grid.begin(); it != grid.end(); it++){
//        cout << *it << " ";
        sort(it->begin(), it->end());
//        cout << *it << endl;
    }
    // determine if the column is sorted
    
    int n = grid[0].size();
    
    
    for (vector<string>::iterator it = grid.begin(); it != grid.end(); ++it){
        cout << *it << endl;
    }
    
    for (vector<string>::iterator it = grid.begin() + 1; it != grid.end(); it++){
        cout << *it << " ";
        for (int j = 0; j < n; j++){
            
            if (it->substr(j,1) < (it-1)->substr(j,1)) return "NO";
            cout << "j = " << j << " " << it->substr(j,1) << " " <<(it-1)->substr(j,1) << " " << endl;
        }
        cout << endl;
    }
    

    return "YES";
};
