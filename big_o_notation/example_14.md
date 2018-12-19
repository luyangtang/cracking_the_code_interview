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

Let C_i be the cost for fib(i) and T(n) be the cost for allFib(n). Then
T(n) = sum_{i=0}^{n-1} C_i = sum_{i=0}^{n-1} O((1+sqrt(5))/2)^n

Let alpha = (1+sqrt(5))/2
T(n) = O((1-alpha^{n-1})/(alpha-1)) = O(alpha^n)
