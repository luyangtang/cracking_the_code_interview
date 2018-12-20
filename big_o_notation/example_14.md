# Example 14

```
void allFib(int n)
{
  for (int i= 0; i < n; i++)
  {
    System.out.println(i + ": "+ fib(i));
  }
}

int fib(int n)
{
  if (n <= 0) return 0;
  else if (n == 1) return 1;
  return fib(n - 1) + fib(n - 2);
}

```

Let ![C_i](https://latex.codecogs.com/svg.latex?C_i) be the cost for `fib(i)` and ![T(n)](https://latex.codecogs.com/svg.latex?T%28n%29) be the cost for `allFib(n)`. Then
![T(n) = \sum_{i=0}^{n-1} C_i = \sum_{i=0}^{n-1} O\left(\left(\frac{1+\sqrt{5}}{2}\right)^n\right)](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D%20C_i%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D%20O%5Cleft%28%5Cleft%28%5Cfrac%7B1&plus;%5Csqrt%7B5%7D%7D%7B2%7D%5Cright%29%5En%5Cright%29)

Let ![\alpha = \frac{1+\sqrt{5}}{2}](https://latex.codecogs.com/svg.latex?%5Calpha%20%3D%20%5Cfrac%7B1&plus;%5Csqrt%7B5%7D%7D%7B2%7D)
![T(n) = O\left(\frac{(1-\alpha^{n-1}}{\alpha-1}\right) = O(\alpha^n)](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20O%5Cleft%28%5Cfrac%7B%281-%5Calpha%5E%7Bn-1%7D%7D%7B%5Calpha-1%7D%5Cright%29%20%3D%20O%28%5Calpha%5En%29)
