# Example 11

The following code computes n ! (n factorial). What is its time complexity?

```
int factorial(int n)
{
  if (n < 0)
  {
    return -1;
  }
  else if (n == 0)
  {
    return 1;
  } else
  {
    return n * factorial(n - 1);
  }
}
```

Let ![T(n)](https://latex.codecogs.com/svg.latex?T%28n%29) be the cost of `factorial(n)` then the difference equation for the recursion is 
![T(n) = O(1) + T(n-1)](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20O%281%29%20&plus;%20T%28n-1%29) 
which gives ![T(n) = O(n)](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20O%28n%29). So Time complexity is ![O(n)](https://latex.codecogs.com/svg.latex?O%28n%29).


'''
factorial(n)
  -> n \* factorial(n-1)
    -> n \* (n-1) \* factorial(n-2)
      -> ...
        -> n \* (n-1) \* ... \* 1
        
'''
