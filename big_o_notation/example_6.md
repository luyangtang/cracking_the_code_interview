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
i = 0
  other = n - 1

i = 1
  other = n - 2

i = 2
  other = n - 3
...

i = n/2
  other = n - 4

This is to reverse an array. The time complexity is O(N).
