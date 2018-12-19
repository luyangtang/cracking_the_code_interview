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
T(a,b) = a/b (number of loops involved)
