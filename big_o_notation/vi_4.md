# VI.4

The following code performs integer division.

What is its runtime (assume a and b are both positive)?

```
int div(int a, int b)
{
  int count = 0;
  int sum = b;
  while (sum <= a)
  {
    sum += b;
    count++;
  }
  return count;
}
```
![T(a,b) = \frac{a}{b}](https://latex.codecogs.com/svg.latex?T%28a%2Cb%29%20%3D%20%5Cfrac%7Ba%7D%7Bb%7D) (number of loops involved)
