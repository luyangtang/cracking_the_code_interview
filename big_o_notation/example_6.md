# Example 6

```
void reverse(int[] array)
{
  for (int i= 0; i <array.length/ 2; i++)
  {
    int other= array.length - i - 1;
    int temp= array[i];
    array[i] = array[other];
    array[other] = temp;
  }
}
```

This is to reverse an array. The time complexity is ![O\left(\frac{N}{2}\right) = O(N)](https://latex.codecogs.com/svg.latex?O%5Cleft%28%5Cfrac%7BN%7D%7B2%7D%5Cright%29%20%3D%20O%28N%29).
