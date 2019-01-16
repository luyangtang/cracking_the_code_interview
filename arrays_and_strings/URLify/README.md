# 1.3 URLify

*URLify:* Write a method to replace all spaces in a string with ``'%20'``. You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string. (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)

[My solution](./URLify/mySolution.cpp) Need to loop through the string twice so the time complexity is ![O(n)](https://latex.codecogs.com/gif.latex?O%28n%29). The first loop will record the index of each space. The second loop will copy the character or add '`%20`'. The index for URL is ahead  of index for string by ![(3-1)\cdot\text{number of spaces before }i](https://latex.codecogs.com/gif.latex?%283-1%29%5Ccdot%5Ctext%7Bnumber%20of%20spaces%20before%20%7Di)/
