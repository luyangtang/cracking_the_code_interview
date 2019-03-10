# 2.4 Partition

*Partition*: Write code to partition a linked list around a value `x`, such that all nodes less than `x` come before all nodes greater than or equal to `x`. If `x` is contained within the list the values of `x` only need to be after the elements less than `x` (see below). The partition element `x` can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

[mySolution](./partition/mySolution.cpp) takes an iterative approach to the problem. If any value is larger than the prescribed threshold then this node is move to the end of the list.

The book also suggest having left and right partition stored in two lists and concatenate them together.
