//
//  zeroSearchBit.cpp
//  zeroMatrix
//
//  Created by LYT on 28/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#include <stdio.h>
#include "zeroSearchBit.h"
#include <iostream>

MatrixBit::MatrixBit(int _rowNum, int _colNum, int *_arr)
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
    zeroRows = 0;
    zeroCols = 0;
}

MatrixBit::~MatrixBit()
{
    // ? do i need to delete each row here?
    delete[] arr;
}

void MatrixBit::searchZero() // trick for multiple outputs
{
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            if (arr[i][j] == 0)
            {
                // record in the matrix
                zeroRows ^= (1 << i);
                zeroCols ^= (1 << j);
            }
        }
    }
    searched = true; // mark that search has been done
}


void MatrixBit::printSearchResult()
{
    if(!searched)
    {
        this->searchZero();
    }
    std::cout << "Zeros on the following rows: ";
    for (int i = 0; i < rowNum; i++)
    {
        std::cout << zeroRows << ' ';
    }
    std::cout << "\nZeros on the following columns: ";
    for (int j = 0; j < colNum; j++)
    {
        std::cout << zeroCols << ' ';
    }
    std::cout << '\n';
}

void MatrixBit::nullify()
{
    if(!searched)
    {
        this -> searchZero();
    }
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            if (((zeroRows & (1 << i)) > 0) || ((zeroCols & (1 << j)) > 0))
            {
                arr[i][j] = 0;
            }
        }
    }
}


void MatrixBit::print()
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



void testNullifyBit()
{
    int arr[] = {1,0,3,4,5,6};
    MatrixBit mtx(2,3,arr);
    mtx.print();
    std::cout << "----\n";
    mtx.nullify();
    mtx.print();
    
    std::cout << '\n';
    
    int arr2[] = {1,0,3,4,5,6,2,8,7,1,3,0};
    MatrixBit mtx2(3,4,arr2);
    mtx2.print();
    std::cout << "----\n";
    mtx2.nullify();
    mtx2.print();
}
