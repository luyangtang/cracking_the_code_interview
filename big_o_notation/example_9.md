# Example 9

The following simple code sums the values of all the nodes in a balanced binary search tree. What is its
runtime?

```
int sum(Node node)
{
  if (node == null)
  {
    return 0;
  }
  return sum(node.left) + node.value + sum(node.right);
}
```

For a tree of depth n,

                0
              1   2
            3  4  5  6
            ...

sum(node 0)
  -> sum(node 1) + sum(node 2)
    -> sum(node 3) + sum(node 4) + sum(node 5) + sum(node 6)
      -> ...

there are altogether 2^n summations in total.

Suppose k is the number of nodes in this tree then we have th following expression/relation:

1 + 2 + 4 + ... + 2^(n-1) = k
(1-2^(n-1))/(1-2) = k
2^(n-1) - 1 = k

Thus in terms of k,
O(2^n) = O(2 * (2 ^(n-1) - 1) + 1) = O(2*k - 1) = O(k)
