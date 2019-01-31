# 2.1 Remove Dups

*Remove Dups*: Write code to remove duplicates from an unsorted linked list.

`FOLLOW UP`

How would you solve this problem if a temporary buffer is not allowed?

[mySolution](./removeDups/mySolution.cpp) iterates each character in the string and compare with the history. Whenever a character has been visited it will be deleted. The book suggested using a hash table (i.e., dictionary) but here I was using a bit vector to do the comparison.

[runnerApproach.cpp](./removeDups) provides a 'brute-force' approach to the problem which works under strict space limit. For each character, it is compared to each one of the remaining string. My solution is longer than the one provided in the book because deallocation is needed and thus we also need to track the 'prev-' node `runner` visited.
