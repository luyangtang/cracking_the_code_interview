# Queue Via Stacks

Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

## [Solution](./Queue.cpp):

Place two stacks `s1` and `s2`. One of them is the 'current' one which takes in all pushes. The other one is the spare one to which current will push to when a `pop()` is executed. For each `pop` performed, the role of 'current' and 'spare' gets swapped.

For each `pop()`, the cost is `2n`.


## [Solution from book](./Queue2.cpp)

Have two stacks `new` and `old`. Pour from `new` to `old` only when `old` gets emptied. And for each dequeue execution, we get the data from `old`.

