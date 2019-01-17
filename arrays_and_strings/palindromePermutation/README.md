# 1.4 Palindrome Permutation

Given a string, write a function to check if it is a permutation of a palin­drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

[My Solution](./palindromePermutation/mySolution.cpp) - A word is a permutation of a Palindrome word if and only if at most 1 character has an odd count. (Not taking white space into account). By referring to ASCII table, this algorithm ignores special characters and is case insensitive.


[My Solution2](./palindromePermutation/mySolution2.cpp) - Use an integer to hold. Initially the integer is set to be 0 so that all the bits are 0. e.g. 0000000000000. Each time a char is found, we flip that bit. Finally check how many 1's are in there. (At most 1 is allowed). To find number of 1 in a binary number, please check [here](https://www.geeksforgeeks.org/count-set-bits-in-an-integer/).
