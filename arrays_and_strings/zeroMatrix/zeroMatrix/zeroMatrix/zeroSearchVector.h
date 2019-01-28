//
//  zeroSearchVector.h
//  zeroMatrix
//
//  Created by LYT on 28/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef zeroSearchVector_h
#define zeroSearchVector_h

class Matrix
{
private:
    int **arr;
    int *zeroRows;
    int *zeroCols;
    bool searched;
public:
    int rowNum;
    int colNum;
    
    // define constructors
    Matrix(int _rowNum, int _colNum, int *_arr);
    
    ~Matrix();
    
    void searchZero();
    
    void printSearchResult();
    
    void nullify();
    
    void print();
};

void testNullify();

#endif /* zeroSearchVector_h */
