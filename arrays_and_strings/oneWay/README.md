# 1.5 One way

*One Away*: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

mySolution is to compare the composition of two strings (character elements and their counts) using two bit vectors. Mark the number of differences by bitwise comparison. As we need to scan through three vectors: `sting1`, `string2` and the bit vector (invariant length), the time complexity is [O(s_1s_2)](https://latex.codecogs.com/gif.latex?O%28s_1s_2%29).
