# Sort Stacks

## Question
Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
an additional temporary stack, but you may not copy the elements into any other data structure
(such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.


## My solution:
If we can have unlimited stacks, we can do multiple sorted mini stacks and stitch them together .


## [From the text book](./sortStack.h)
Use a helper stack to achieve O(n^2) time complexity and O(n) space complexity.

If we were allowed to use unlimited stacks, we could implement a modified quicksort or mergesort.

With the [merge sort](./mergeSort.h) solution, we would create two extra stacks and divide the stack into two parts. We would recursively sort each stack, and then merge them back together in sorted order into the original stack. Note that this would require the creation of two additional stacks per level of recursion.

With the [quick sort](./quickSort.h) solution, we would create two additional stacks and divide the stack into the two stacks based on a pivot element. The two stacks would be recursively sorted, and then merged back together into the original stack. Like the earlier solution, this one involves creating two additional stacks per level of recursion.
