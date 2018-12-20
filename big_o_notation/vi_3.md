# VI.3

The following code computes a % b.
What is its runtime?

```
int mod(int a, int b)
{
  if (b <= 0)
  {
    return -1;
  }
  int div = a / b;
  return a - div * b;
}

```
![T(a,b) = O(1)](https://latex.codecogs.com/svg.latex?T%28a%2Cb%29%20%3D%20O%281%29)
