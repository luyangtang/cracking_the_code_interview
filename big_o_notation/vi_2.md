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

T(a,b) = (T(a,b-1) + O(1))1{b > 0} + O(1)
So as b -> inf
T(a,b) = T(a,b-1) + O(1)
=> T(a,b) = O(b)
