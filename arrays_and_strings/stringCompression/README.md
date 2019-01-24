# 1.6 String Compression

*String Compression:* Implement a method to perform basic string compression using the counts of repeated characters. For example, the string `aabcccccaaa` would become `a2blc5a3`. If the "compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).

[mySolution](./mySolution) Scan the string and whenever there is a change in character, the counter and the new character will be pushed to the compressed string and then reset. Otherwise the counter will keep accumulating. In my codes, such string is grouped in a class called `myString` with compression as a method.
