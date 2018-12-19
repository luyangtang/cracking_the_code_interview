# Example 4

```
void printUnorderedPairs(int[] arrayA, int[] arrayB)
{
  for (int i= 0; i < arrayA.length; i++)
  {
    for (int j = 0; j < arrayB.length; j++)
    {
      if (arrayA[i] < arrayB[j]) {
        System.out.println(arrayA[i] + "," + arrayB[j]);
      }
    }
  }
}
```
Suppose `arrayA` has length a, `arrayB` has length b then the cost is O(a) \* O(b) = O(a \* b)
