# Example 5

```
void printUnorderedPairs(int[] arrayA, int[] arrayB)
{
  for (int i= 0; i < arrayA.length; i++)
  {
    for (int j = 0; j < arrayB.length; j++)
    {
      for (int k = 0; k < 100000; k++)
      {
        System.out.println(arrayA[i] + "," + arrayB[j]);
      }
    }
  }
}
```
Suppose arrayA has length a, arrayB has length b.
O(a) \* O(b) \* 100000 = O(a \* b)
