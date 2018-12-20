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
Suppose `arrayA` has length a, `arrayB` has length b then the cost is ![O(a) \cdot O(b) = O(a \cdot b)](https://latex.codecogs.com/svg.latex?O%28a%29%20%5Ccdot%20O%28b%29%20%3D%20O%28a%20%5Ccdot%20b%29)
