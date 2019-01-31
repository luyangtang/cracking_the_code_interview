# 2.1 Remove Dups

*Remove Dups*: Write code to remove duplicates from an unsorted linked list.

`FOLLOW UP`

How would you solve this problem if a temporary buffer is not allowed?

[mySolution](./removeDups/mySolution.cpp) iterates each character in the string and compare with the history. Whenever a character has been visited it will be deleted. The book suggested using a hash table (i.e., dictionary) but here I was using a bitvector to do the comparison.
