# 1.6 String Compression

*String Compression:* Implement a method to perform basic string compression using the counts of repeated characters. For example, the string `aabcccccaaa` would become `a2blc5a3`. If the "compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).

[mySolution](./mySolution) Scan the string and whenever there is a change in character, the counter and the new character will be pushed to the compressed string and then reset. Otherwise the counter will keep accumulating. In my codes, such string is grouped in a class called `myString` with compression as a method.

_Remark_: In `mySolution.cpp` the strings are constructed using `<string>` library, which provides faster concatenation. Otherwise if the strings are constructed as character arrays, then the time complexity for concatenation is as much as ![O(n^2)](https://latex.codecogs.com/gif.latex?O%28n%5E2%29). Recall that what `StringBuilder` (as in Jave) doubles the size of the array whenever needed.

The book introduced another approach which checks in advance so that it is optimal for strings with very few repetitions. This is to have a string built with prescribed size so that the doubling won't happen (even behind scene).
