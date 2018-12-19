# Example 10


The following method checks if a number is prime by checking for divisibility on numbers less than it.

It only needs to go up to the square root of n because if n is divisible by a number greater than its square root then
it's divisible by something smaller than it.

For example, while 33 is divisible by 11 (which is greater than the square root of 33), the "counterpart"to 11
is 3 (3 * 11 = 33). 33 will have already been eliminated as a prime number by 3.

What is the time complexity of this function?

```
boolean isPrime(int n)
{
  for (int x = 2; x * x <= n; x++)
  {
    if (n % X == 0) {
      return false;
    }
  }
  return true;
}
```
x = 2

x = 3

x = 4

...

x = floor(sqrt(n))

So time complexity is O(floor(sqrt(n))) = O(n^0.5)
