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
C(n) = C(n-1) + C(n-2) + O(1)
Solving the difference equation using auxiliary equation gives C(n) = A((1+sqrt(5))/2)^n + B((1-sqrt(5))/2)^n

If we force C(n) to be non-negative for all n, then B = 0 is the only choice. Using the algebra of limits gives

C(n) = O((1+sqrt(5))/2)^n)
