# Example 16

The following function prints the powers of 2 from 1 through n (inclusive). For example, if n is 4, it would
print 1, 2, and 4. What is its runtime?

```
int powers0f2(int n)
{
  if (n < 1)
  {
    return 0;
  }
  else if (n == 1)
  {
    System.out.println(l);
    return 1;
  }
  else
  {
    int prev = powers0f2(n / 2);
    int curr = prev * 2;
    System.out.println(curr);
    return curr;
  }
}
```

Let n be some power of 2 (so there exists some non negative integer k such that 2^k = n) then

T(2^k) = T(2^(k-1)) + c
  = T(2^(k-2)) + 2c
  = ...
  = T(1) + kc = O(k) = O(log n)
