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
Suppose `arrayA` has length `a`, `arrayB` has length `b`.
Then the time complexity is 
![O(a) \cdot O(b) \cdot 100000 = O(a \cdot b)](https://latex.codecogs.com/svg.latex?O%28a%29%20%5Ccdot%20O%28b%29%20%5Ccdot%20100000%20%3D%20O%28a%20%5Ccdot%20b%29)
