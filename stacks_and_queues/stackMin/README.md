# Stack Min

## Question
How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.


## Solution
An array of the minimum is kept track of as a function with respect to the stack length so that we can get the minimum correct after popping from the stack. The minimum will be updated on each push event.


## Better solution (from the book)
Only push to the min array when the new value is smaller (*or equal*) to the min on top so that each time when an element is popped, any matching peek can be popped too.