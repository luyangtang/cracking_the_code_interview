# Intersection

Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the `k`th node of the first linked list is the exact same node (by reference) as the `j`th node of the second linked list, then they are intersecting.

[mySolution](./intersection/mySolution.cpp) provides a brute force approach that has two runners to go through two lists one step at each time and does pairwise comparison. This has time complexity `O(mn)` where `m` and `n` are the lengths.
