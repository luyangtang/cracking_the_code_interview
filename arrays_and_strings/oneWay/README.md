# 1.5 One way

*One Away*: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

- mySolution: sort characters in both strings. We need four integer arrays and two bit vectors to compare.
  1. Scan both `string1` and `string2` and for each string, record the unique characters in order, the number of occurrence of the characters, represented by a *hash table* and the size of the string `int stringLen`.
  2. If two sizes are the same, then we need to check if it is a replacement using a bit vector which should have exactly 1 `1`.
  3. If two sizes differ by 1, then only 1 key is allowed to have a different value, which can't differ by more than 2.
