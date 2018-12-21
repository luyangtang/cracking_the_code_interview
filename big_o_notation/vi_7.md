# VI.7

If a binary search tree is not balanced, how long might it take (worst case) to find an element
in it?


The worst case is that the tree has the following structure:

```

                *
               /
              *
             / \
            *   *
           / \
          *   *
         / \
        *   *
```

Suppose the tree has ![n](http://latex.codecogs.com/gif.latex?n) many nodes and let ![d](http://latex.codecogs.com/gif.latex?d) be the depth of the tree then we have

![1 + 1 + 2\cdot(d-2) = 2d - 2 = n](http://latex.codecogs.com/gif.latex?1%20&plus;%201%20&plus;%202%5Ccdot%28d-2%29%20%3D%202d%20-%202%20%3D%20n)

In the worst case that the node we want to find is at depth ![d](http://latex.codecogs.com/gif.latex?d), the time complexity is ![O(d) = O(2d-2) = O(n)](http://latex.codecogs.com/gif.latex?O%28d%29%20%3D%20O%282d-2%29%20%3D%20O%28n%29).
