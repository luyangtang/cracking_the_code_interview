# Example 16

The following function prints the powers of 2 from 1 through n (inclusive). For example, if n is 4, it would
print 1, 2, and 4. What is its runtime?

```
int powers0f2(int n)
{
  if (n < 1)
  {
    return 0;
  }
  else if (n == 1)
  {
    System.out.println(l);
    return 1;
  }
  else
  {
    int prev = powers0f2(n / 2);
    int curr = prev * 2;
    System.out.println(curr);
    return curr;
  }
}
```

Let n be some power of 2 (so there exists some non negative integer ![k](https://latex.codecogs.com/svg.latex?k) such that ![2^k = n](https://latex.codecogs.com/svg.latex?2%5Ek%20%3D%20n)) then

![T\left(2^k\right) = T\left(2^{k-1})\right) + c
  = T(2^{k-2}) + 2c
  = \ldots
  = T(1) + kc = O(k) = O(\log n)
](https://latex.codecogs.com/svg.latex?T%5Cleft%282%5Ek%5Cright%29%20%3D%20T%5Cleft%282%5E%7Bk-1%7D%29%5Cright%29%20&plus;%20c%20%3D%20T%282%5E%7Bk-2%7D%29%20&plus;%202c%20%3D%20%5Cldots%20%3D%20T%281%29%20&plus;%20kc%20%3D%20O%28k%29%20%3D%20O%28%5Clog%20n%29)
