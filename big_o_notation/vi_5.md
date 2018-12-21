# VI.5

The following code computes the [integer] square root of a number. If the number is not a
perfect square (there is no integer square root), then it returns -1. It does this by successive
guessing. If n is 100, it first guesses SO. Too high? Try something lower - halfway between 1
and SO. What is its runtime?

```
int sqrt(int n)
{
  return sqrt_helper(n, 1, n);
}

int sqrt_helper(int n, int min, int max)
{
  if (max < min) return -1; // no square root
  int guess = (min + max) / 2;
  if (guess *guess == n)
  { // found it!
    return guess;
  }
  else if (guess * guess < n)
  { //too low
    return sqrt_helper(n, guess + 1, max); // try higher
  } else
  { // too high
    return sqrt_helper(n, min, guess - 1); // try lower
  }
}

```

Let ![T(n)](http://latex.codecogs.com/gif.latex?T%28n%29) be the cost for `sqrt(int n)` and let ![t(i,a,b)](http://latex.codecogs.com/gif.latex?t%28i%2Ca%2Cb%29) be the cost for `sqrt_helper(i,a,b)`;

![t(i,a,b) = 1](http://latex.codecogs.com/gif.latex?t%28i%2Ca%2Cb%29%20%3D%201) if ![b < a](http://latex.codecogs.com/gif.latex?b%20%3C%20a) or ![n = \frac{a+b}{2}](http://latex.codecogs.com/gif.latex?n%20%3D%20%5Cfrac%7Ba&plus;b%7D%7B2%7D)

![t(i,a,b) = t\left(i,\frac{a+b}{2}+1,b\right)](http://latex.codecogs.com/gif.latex?t%28i%2Ca%2Cb%29%20%3D%20t%5Cleft%28i%2C%5Cfrac%7Ba&plus;b%7D%7B2%7D&plus;1%2Cb%5Cright%29) if ![\left(\frac{a+b}{2}\right)^2](http://latex.codecogs.com/gif.latex?%5Cleft%28%5Cfrac%7Ba&plus;b%7D%7B2%7D%5Cright%29%5E2)

![t(i,a,b) = t\left(i,a,\frac{a+b}{2} - 1\right)](http://latex.codecogs.com/gif.latex?t%28i%2Ca%2Cb%29%20%3D%20t%5Cleft%28i%2Ca%2C%5Cfrac%7Ba&plus;b%7D%7B2%7D%20-%201%5Cright%29) if ![\left(\frac{a+b}{2}\right)^2](http://latex.codecogs.com/gif.latex?%5Cleft%28%5Cfrac%7Ba&plus;b%7D%7B2%7D%5Cright%29%5E2)

This is a bisection method, each time the width is halved so the time complexity is ![O(\log (b-a))](http://latex.codecogs.com/gif.latex?O%28%5Clog%20%28b-a%29%29). And for `sqrt(int n)`, ![T(n) = O(\log n)](http://latex.codecogs.com/gif.latex?T%28n%29%20%3D%20O%28%5Clog%20n%29)
