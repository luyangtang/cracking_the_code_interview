# Example 13

The following code computes the Nth Fibonacci number.

```
int fib(int n)
{
  if (n <= 0) return 0;
  else if (n == 1) return 1;
  return fib(n - 1) + fib(n - 2);
}
```

![C(n) = C(n-1) + C(n-2) + O(1)](https://latex.codecogs.com/svg.latex?C%28n%29%20%3D%20C%28n-1%29%20&plus;%20C%28n-2%29%20&plus;%20O%281%29)

Solving the difference equation using auxiliary equation gives ![C(n) = A\left(\frac{1+\sqrt(5)}{2}\right)^n + B\left(\frac{1-\sqrt(5)}{2}\right)^n](https://latex.codecogs.com/svg.latex?C%28n%29%20%3D%20A%5Cleft%28%5Cfrac%7B1&plus;%5Csqrt%285%29%7D%7B2%7D%5Cright%29%5En%20&plus;%20B%5Cleft%28%5Cfrac%7B1-%5Csqrt%285%29%7D%7B2%7D%5Cright%29%5En)

If we force ![C(n)](https://latex.codecogs.com/svg.latex?C%28n%29) to be non-negative for all ![n](https://latex.codecogs.com/svg.latex?n), then ![B = 0](https://latex.codecogs.com/svg.latex?B%20%3D%200) is the only choice. Using the algebra of limits gives

![C(n) = O\left(\left(\frac{1+\sqrt(5)}{2}\right)^n\right)](https://latex.codecogs.com/svg.latex?C%28n%29%20%3D%20O%5Cleft%28%5Cleft%28%5Cfrac%7B1&plus;%5Csqrt%285%29%7D%7B2%7D%5Cright%29%5En%5Cright%29)
