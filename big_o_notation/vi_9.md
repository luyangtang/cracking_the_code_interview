# VI.9

The `appendToNew` method appends a value to an array by creating a new, longer array and
returning this longer array.

You've used the `appendToNew` method to create a copyArray
function that repeatedly calls `appendToNew`.

How long does copying an array take?

```
int[] copyArray(int[] array)
{
  int[] copy= new int[0];
  for (int value : array)
  {
    copy= appendToNew(copy, value);
  }
  return copy;
}

int[] appendToNew(int[] array, int value)
{
// copy all elements over to new array
  int[] bigger= new int[array.length + 1];
  for (int i= 0; i < array.length; i++)
  {
    bigger[i] = array[i];
  }
  // add new element
  bigger[bigger.length - 1] = value;
  return bigger;
}
```

Suppose `array` has length ![n](http://latex.codecogs.com/gif.latex?n) and let the time complexity of `appendToNew` be ![T(n)](http://latex.codecogs.com/gif.latex?T%28n%29).

![T(n) = O(n)](http://latex.codecogs.com/gif.latex?T%28n%29%20%3D%20O%28n%29) as can seen from the `for`-block.

Let ![C(n)](http://latex.codecogs.com/gif.latex?C%28n%29) be the time complexity of `copyArray` then ![C(n) = \sum_{i=0}^{n-1}T(i) = \sum_{i=0}^{n-1}O(i) = O\left(\sum_{i=0}^{n-1}i\right) = O\left(\frac{(n-1)n}{2}\right) = O(n^2)](http://latex.codecogs.com/gif.latex?C%28n%29%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7DT%28i%29%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7DO%28i%29%20%3D%20O%5Cleft%28%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7Di%5Cright%29%20%3D%20O%5Cleft%28%5Cfrac%7B%28n-1%29n%7D%7B2%7D%5Cright%29%20%3D%20O%28n%5E2%29)

That is, the time complexity is ![O(n^2)](http://latex.codecogs.com/gif.latex?O%28n%5E2%29).
