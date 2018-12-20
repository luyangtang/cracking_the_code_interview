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

`sum(node 0)`

  -> `sum(node 1)` + `sum(node 2)`
  
    -> `sum(node 3)` + `sum(node 4)` + `sum(node 5)` + `sum(node 6)`
    
      -> ...

there are altogether ![2^n](https://latex.codecogs.com/svg.latex?2%5En) summations in total.

Suppose ![k](https://latex.codecogs.com/svg.latex?k) is the number of nodes in this tree then we have th following expression/relation:

![k = 1 + 2 + 4 + \ldots + 2^{n-1} = \frac{1-2^{n-1}}{1-2} = 2^{n-1} - 1](https://latex.codecogs.com/svg.latex?k%20%3D%201%20&plus;%202%20&plus;%204%20&plus;%20%5Cldots%20&plus;%202%5E%7Bn-1%7D%20%3D%20%5Cfrac%7B1-2%5E%7Bn-1%7D%7D%7B1-2%7D%20%3D%202%5E%7Bn-1%7D%20-%201)

Thus in terms of ![k](https://latex.codecogs.com/svg.latex?k),
![O(2^n) = O\left(2 * (2 ^{n-1} - 1) + 1\right) = O(2\cdot k - 1) = O(k)](https://latex.codecogs.com/svg.latex?O%282%5En%29%20%3D%20O%5Cleft%282%20*%20%282%20%5E%7Bn-1%7D%20-%201%29%20&plus;%201%5Cright%29%20%3D%20O%282%5Ccdot%20k%20-%201%29%20%3D%20O%28k%29)
