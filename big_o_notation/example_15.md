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

Let T(n) be the cost of running allFib(n) and t_i be the cost of running fib(i).

Then T(n) = sum_{i = 0}^{n-1} t_i where

t_i = (t_{i-1} + t_{i-2})\*1{i visited before} + O(1) (1 is the indicator function)

So we have

T(n) = sum_{i = 0}^{n-1} (t_{i-1} + t_{i-2})\*1{i visited before} + O(1)
    = sum_{i = 0}^{n-1} O(1) = O(n) (by algebra of limit)
