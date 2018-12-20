# VI.1

The following code computes the product of a and b. What is its runtime?

```
int product(int a, int b)
{
  int sum = 0;
  for (int i= 0; i < b; i++)
  {
    sum += a;
  }
  return sum;
}
```

![T(a,b) = b \cdot O(1) = O(b)](https://latex.codecogs.com/svg.latex?T%28a%2Cb%29%20%3D%20b%20%5Ccdot%20O%281%29%20%3D%20O%28b%29)
