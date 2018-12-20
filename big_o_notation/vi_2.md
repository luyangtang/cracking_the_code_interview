# VI.2

The following code computes a^b. What is its runtime?
```
int power(int a, int b)
{
  if (b < 0)
  {
    return 0; // error
  }
  else if (b == 0)
  {
    return 1;
  }
  else
  {
    return a* power(a, b - 1);
  }
}
```

![T(a,b) = (T(a,b-1) + O(1))\mathbf 1\{b > 0\} + O(1)](https://latex.codecogs.com/svg.latex?T%28a%2Cb%29%20%3D%20%28T%28a%2Cb-1%29%20&plus;%20O%281%29%29%5Cmathbf%201%5C%7Bb%20%3E%200%5C%7D%20&plus;%20O%281%29)

So as ![b \rightarrow \inf](https://latex.codecogs.com/svg.latex?b%20%5Crightarrow%20%5Cinf)
![T(a,b) = T(a,b-1) + O(1)
\Rightarrow  T(a,b) = O(b)
](https://latex.codecogs.com/svg.latex?T%28a%2Cb%29%20%3D%20T%28a%2Cb-1%29%20&plus;%20O%281%29%20%5CRightarrow%20T%28a%2Cb%29%20%3D%20O%28b%29)
