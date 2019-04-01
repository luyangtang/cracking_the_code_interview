# Intersection

Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the `k`th node of the first linked list is the exact same node (by reference) as the `j`th node of the second linked list, then they are intersecting.

[mySolution](./intersection/mySolution.cpp) provides a brute force approach that has two runners to go through two lists one step at each time and does pairwise comparison. This has time complexity `O(mn)` where `m` and `n` are the lengths.


[compareTail](./compareTail.cpp) compares the tail of two linked lists. By observing list pairs with intersection, different heads will 'converge' to the same point at intersection and keep together until reach the tail. So having the same tail is a necessary and sufficient condition for the presence of intersection. On the other hand, by moving the running `Node` so that both branches start at the same level, we can easily find where two runner meet, and that is the position of intersection.
