# 1.1 Is Unique

*Is Unique:* Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?

# isUnque

In [`mySolution.cpp`](./isUnique/mySolution.cpp) I used nested while-loop to do pairwise comparison so the time complexity is ![O(n^2)](https://latex.codecogs.com/svg.latex?O%28n%5E2%29).
Unfortunately it has the worst performance.

[Geeks for geeks](https://www.geeksforgeeks.org/determine-string-unique-characters/) has provided multiple approaches:
 - Approach 2 – Sorting
 - Approach 3 – Use of Extra Data Structure
 - Approach 4 – Without Extra Data Structure
