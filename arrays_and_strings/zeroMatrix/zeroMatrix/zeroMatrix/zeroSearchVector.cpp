//
//  zeroSearchVector.cpp
//  zeroMatrix
//
//  Created by LYT on 28/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "zeroSearchVector.h"
#include <iostream>


Matrix::Matrix(int _rowNum, int _colNum, int *_arr)
{
    
    // initialise the matrix
    rowNum = _rowNum;
    colNum = _colNum;
    int arrInd = 0; // track current index for _arr
    arr = new int*[rowNum];
    
    for (int i = 0; i < rowNum; i++)
    {
        int *row = new int[colNum]{0};
        row = _arr + arrInd;
        arr[i] = row;
        arrInd += colNum;
    }
    
    // for zero searches
    searched = false;
    zeroRows = new int[rowNum]{0};
    zeroCols = new int[colNum]{0};
}

Matrix::~Matrix()
{
    // ? do i need to delete each row here?
    delete[] arr;
    delete zeroRows;
    delete zeroCols;
}

void Matrix::searchZero() // trick for multiple outputs
{
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            if (arr[i][j] == 0)
            {
                // record in the matrix
                zeroRows[i] = zeroRows[i]+1;
                zeroCols[j] = zeroCols[j]+1;
            }
        }
    }
    searched = true; // mark that search has been done
}


void Matrix::printSearchResult()
{
    if(!searched)
    {
        this->searchZero();
    }
    std::cout << "Zeros on the following rows: ";
    for (int i = 0; i < rowNum; i++)
    {
        std::cout << zeroRows[i] << ' ';
    }
    std::cout << "\nZeros on the following columns: ";
    for (int j = 0; j < colNum; j++)
    {
        std::cout << zeroCols[j] << ' ';
    }
    std::cout << '\n';
}

void Matrix::nullify()
{
    if(!searched)
    {
        this -> searchZero();
    }
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            if (zeroRows[i] > 0 || zeroCols[j] > 0)
            {
                arr[i][j] = 0;
            }
        }
    }
}


void Matrix::print()
{
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            // print the cell
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}



void testNullify()
{
    int arr[] = {1,0,3,4,5,6};
    Matrix mtx(2,3,arr);
    mtx.print();
    std::cout << "----\n";
    mtx.nullify();
    mtx.print();
    
    std::cout << '\n';
    
    int arr2[] = {1,0,3,4,5,6,2,8,7,1,3,0};
    Matrix mtx2(3,4,arr2);
    mtx2.print();
    std::cout << "----\n";
    mtx2.nullify();
    mtx2.print();
}
