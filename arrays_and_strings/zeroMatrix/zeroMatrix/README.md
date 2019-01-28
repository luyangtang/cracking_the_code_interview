# 1.8 Zero Matrix

*Zero Matrix:* Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

From the book: At first glance, this problem seems easy: just iterate through the matrix and every time we see a cell with value zero, set its row and column to 0. There's one problem with that solution though: when we come across other cells in that row or column, we'll see the zeros and change their row and column to zero.Pretty soon, our entire matrix will be set to zeros.

[zeroSearchVector](./zeroMatrix/zeroSearchVector.cpp) keeps two vectors to track the row number and column number for zero entries, which can be optimised by using bit vector.

[zeroSearchBit](./zeroMatrix/zeroSearchBit.cpp) replaces `int *zeroSearchRow` and `int *zeroSearchCol` by `int zeroSearchRow` and `int zeroSearchCol` which saves space and avoid creating dynamically allocated variable in the heap.
