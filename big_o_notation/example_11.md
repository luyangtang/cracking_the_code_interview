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
factorial(n)
  -> n \* factorial(n-1)
    -> n \* (n-1) \* factorial(n-2)
      -> ...
        -> n \* (n-1) \* ... \* 1
        
Time complexity is O(n).
