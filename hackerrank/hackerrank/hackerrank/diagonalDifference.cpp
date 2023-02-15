//
//  diagonalDifference.cpp
//  hackerrank
//
//  Created by Luyang Tang on 15/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <vector>
#include <iostream>


void diagonalDifference::test(){
    
    std::vector<std::vector<int>> a{
        {1,2,3}, {4,5,6}, {9,8,9}
    };
    
    std::cout << diagonalDifference(a) << std::endl;
    
}


int diagonalDifference::diagonalDifference(std::vector<std::vector<int>> arr){
    
    int l2rDiagonalSum(0);
    int r2lDiagonalSum(0);
    
    for (std::vector<std::vector<int>>::iterator i = arr.begin(); i != arr.end(); ++i){
        for (std::vector<int>::iterator j = i->begin(); j != i->end(); ++j){
            
            int l2rDiagonal = (j - i->begin()) - (i - arr.begin());
            int r2lDiagonal = (j - i->begin()) - (arr.size() - (i - arr.begin()));
            
            std::cout << *j << " (" << l2rDiagonal << " " << r2lDiagonal <<  ")" << r2lDiagonalSum << " ";
            
            l2rDiagonalSum += (l2rDiagonal == 0 ? *j : 0);
            r2lDiagonalSum += (r2lDiagonal == -1 ? *j : 0);
        }
        
        std::cout << l2rDiagonalSum << " " <<  r2lDiagonalSum << std::endl;
    }
    return std::abs(l2rDiagonalSum - r2lDiagonalSum);
    
}
