# Sum Lists

Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1's digit is at the head of the iist. Write a
function that adds the two numbers and returns the sum as a linked list.

EXAMPLE
input: `(7- > 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295`.
Output; `2 -> 1 -> 9`.That is, 912.
FOLLOW UP

Suppose the digits are stored in forward order. Repeat the above problem.
Input (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2.That is, 912.

[mySolution](./sumLists/mySolution.cpp) converts the list to an integer and cast it back to linked list via string stream. The performance may be greatly affected by long integer inputs.

[manualSum](./sumLists/manualSum.cpp) reproduce the actual steps involved when doing addition by hand, as suggested by the book itself. This does not involve multiple traverses through the lists so has a improved performance as oppose to the first approach.
