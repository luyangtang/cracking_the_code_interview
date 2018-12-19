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

T(a,b) = b * O(1) = O(b)
