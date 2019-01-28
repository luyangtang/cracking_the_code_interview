//
//  zeroSearchBit.h
//  zeroMatrix
//
//  Created by LYT on 28/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef zeroSearchBit_h
#define zeroSearchBit_h

class MatrixBit
{
private:
    int **arr;
    int zeroRows;
    int zeroCols;
    bool searched;
public:
    int rowNum;
    int colNum;
    
    // define constructors
    MatrixBit(int _rowNum, int _colNum, int *_arr);
    
    ~MatrixBit();
    
    void searchZero();
    
    void printSearchResult();
    
    void nullify();
    
    void print();
};

void testNullifyBit();

#endif /* zeroSearchBit_h */
