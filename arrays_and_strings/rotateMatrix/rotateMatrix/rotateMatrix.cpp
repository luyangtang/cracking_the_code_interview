//
//  rotateMatrix.cpp
//  rotateMatrix
//
//  Created by LYT on 29/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include "rotateMatrix.hpp"
#include <iostream>

Matrix::Matrix(int _rowNum, int _colNum, int **_arr)
{
    rowNum = _rowNum;
    colNum = _colNum;
    arr = _arr;
}

Matrix::Matrix(int _rowNum, int _colNum, int _arr[])
{
    rowNum = _rowNum;
    colNum = _colNum;
    
    int arrInd = 0; // loop through arr to split into rows
    arr = new int *[rowNum];
    
    for (int i = 0; i < rowNum; i++)
    {
        arr[i] = new int[colNum];
        arr[i] = _arr + arrInd;
        arrInd += colNum;
    }
}

void Matrix::print()
{
    for (int i = 0; i < rowNum; i ++)
    {
        for (int j = 0; j < colNum; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


Matrix Matrix::rotate()
{
    int **newArr = new int *[colNum];
    for (int j = 0; j < colNum; j++)
    {
        newArr[j] = new int [rowNum];
        for (int i = 0; i < rowNum; i++)
        {
            newArr[j][i] = arr[rowNum-1 - i][j];
        }
    }
    Matrix newMtrx(colNum,rowNum,newArr);
    return newMtrx;
}

Matrix::~Matrix()
{
    delete [] arr;
}


void test()
{
    int _arr[] = {1,2,3,4,5,6};
    Matrix mtx(2,3,_arr);
    mtx.print();
    mtx.rotate().print();
}
