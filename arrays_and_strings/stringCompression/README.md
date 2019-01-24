# 1.5 One way

*One Away*: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

- [mySolution](./oneWay/mySolution.cpp): first check replacement and then check if it is insertion (one function can check both insertion and removal by symmetry). If string length is known then the time complexity is linear with the length of the shorter string otherwise the time complexity is proportional to that of the longer string.
