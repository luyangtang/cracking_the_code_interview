# VI.6

The following code computes the [integer] square root of a number. If the number is not
a perfect square (there is no integer square root), then it returns -1. It does this by trying
increasingly large numbers until it finds the right value (or is too high).
What is its runtime?

```
int sqrt(int n)
{
  for (int guess = 1; guess * guess <= n; guess++)
  {
    if (guess * guess == n)
    {
      return guess;
    }
  }
  return -1;
}

```

Each step `guess` has an increment of 1 which will be bound by ![\sqrt n](http://latex.codecogs.com/gif.latex?%5Csqrt%20n) so the time complexity is ![O(\sqrt n)](http://latex.codecogs.com/gif.latex?O%28%5Csqrt%20n%29).
