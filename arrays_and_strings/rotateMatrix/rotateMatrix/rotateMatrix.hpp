//
//  rotateMatrix.hpp
//  rotateMatrix
//
//  Created by LYT on 29/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef rotateMatrix_hpp
#define rotateMatrix_hpp

#include <stdio.h>

class Matrix
{
public:
    int rowNum;
    int colNum;
    int **arr;
    
    Matrix(int _rowNum, int _colNum, int **_arr);
    
    Matrix(int _rowNum, int _colNum, int _arr[]);
    
    void print();
    
    
    Matrix rotate();
    
    ~Matrix();
};


void test();

#endif /* rotateMatrix_hpp */
