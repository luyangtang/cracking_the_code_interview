# Example 16

The following code prints all Fibonacci numbers from O to n. However, this time, it stores (i.e., caches) previously
computed values in an integer array. If it has already been computed, it just returns the cache. What
is its runtime?

```
void allFib(int n)
{
  int[] memo = new int[n + 1];
  for (int i= 0; i < n; i++)
  {
    System.out.println(i + ": "+ fib(i, memo));
  }
}


int fib(int n, int[] memo)
{
  if (n <= 0) return 0;
  else if (n == 1) return 1;
  else if (memo[n] > 0) return memo[n];

  memo[n] = fib(n - 1, memo)+ fib(n - 2, memo);
  return memo[n];
}
```

Let ![T(n)](https://latex.codecogs.com/svg.latex?T%28n%29) be the cost of running `allFib(n)` and ![t_i](https://latex.codecogs.com/svg.latex?t_i) be the cost of running `fib(i)`.

Then ![T(n) = \sum_{i = 0}^{n-1} t_i](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7D%20t_i) where

![t_i = (t_{i-1} + t_{i-2})\cdot\mathbf1\{i \text{ visited before}\} + O(1)](https://latex.codecogs.com/svg.latex?t_i%20%3D%20%28t_%7Bi-1%7D%20&plus;%20t_%7Bi-2%7D%29%5Ccdot%5Cmathbf1%5C%7Bi%20%5Ctext%7B%20visited%20before%7D%5C%7D%20&plus;%20O%281%29) (![\mathbf 1](https://latex.codecogs.com/svg.latex?%5Cmathbf1) is the indicator function)

So we have

![T(n) = \sum_{i = 0}^{n-1} (t_{i-1} + t_{i-2})\mathbf1\{i \text{ visited before}\} + O(1)
    = \sum_{i = 0}^{n-1} O(1) = O(n)](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7D%20%28t_%7Bi-1%7D%20&plus;%20t_%7Bi-2%7D%29%5Cmathbf1%5C%7Bi%20%5Ctext%7B%20visited%20before%7D%5C%7D%20&plus;%20O%281%29%20%3D%20%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7D%20O%281%29%20%3D%20O%28n%29) (by algebra of limit)
