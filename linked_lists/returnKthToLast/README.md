# 2.2 Return k-th to last

Return k-th to Last: Implement an algorithm to find the k-th to last element of a singly linked list.

[mySolution](./returnKthToLast/mySolution.cpp) provides a recursion method that solves the problem. The key is to come up with a way to return two outputs: node and counter. This can be done by pass-by-reference or creating a simple class to have a static variable.

[iterative](./returnKthToLast/iterative.cpp) has two pointers running, separated by k positions so that when the front one hits the end the other one returns the desired value.
