//
//  countingSort1.cpp
//  hackerrank
//
//  Created by Luyang Tang on 15/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <vector>
#include <iostream>

void countingSort1::test(){
    std::vector<int> arr{4,3,2,1};
    std::vector<int> outputVector = countingSort1(arr);
    
    for (std::vector<int>::iterator it = outputVector.begin(); it != outputVector.end(); it++){
        std::cout << *it << " ";
    }
    
}


std::vector<int> countingSort1::countingSort1(std::vector<int> arr) {
    
    std::vector<int> counter(100, 0);
    std::vector<int> sortedArray;
    
    // build the counter
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
        counter[*it]++;
    }
    
    // parse the counter
    for (std::vector<int>::iterator it = counter.begin(); it != counter.end(); it++){
        for (int i = 0; i < *it; i++){
            sortedArray.push_back(it - counter.begin());
        }
    }
    
    
  
    
    std::cout << std::endl;
//    return counter;
    
    return sortedArray;
}
