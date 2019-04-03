# Palindrome

 Implement a function to check if a linked list is a palindrome.

 [mySolution](./palindrome/mySolution.cpp) reverses the list and have `n1` traversing the list. Have another runner `n2` from `head`. Now `n2` goes forward and `n1` goes backward and do comparison until they are half way (still order `O(n)` if they traverse in full).

 [stack](./palindrome/stack.cpp) uses a stack to store the first half of the list and compare against the rest of the list.

 [recursion](./palindrome/recursion.cpp) takes a recursive approach that compares the 'front' with the 'end' from outer to inner until the mid is hit when the node itself is returned. At each iteration, the end node is derived from the output from the previous iteration.
