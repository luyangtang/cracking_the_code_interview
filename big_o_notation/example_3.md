# Example 3

##### This is very similar code to the above example, but now the inner for loop starts at i + 1.

```
void printUnorderedPairs(int[] array)
{
  for (int i= 0; i < array.length; i++)
  {
    for (int j = i + 1; j < array.length; j++)
    {
      System.out.println(array[i] + "," + array[j]);
    }
  }
}
```

##### Solution
When i = 0
  j = 1, 2, 3, 4, ..., n

When i = 1
  j = 2, 3, 4, ..., n

For i = i', there are (n - i' + 1) many j's

Complexity is sum(O(n - i + 1)) for i from 0 to n - 1 which equals O((n+1)\*n)- O((n-1)\*(n-1)/2) = O(n^2);
