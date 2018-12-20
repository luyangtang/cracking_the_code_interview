# Example 3

##### This is very similar code to the above example, but now the inner for loop starts at i + 1.

```
void printUnorderedPairs(int[] array)
{
  for (int i= 0; i < array.length; i++)
  {
    for (int j = i + 1; j < array.length; j++)
    {
      System.out.println(array[i] + "," + array[j]);
    }
  }
}
```

##### Solution
When ![i = 0](https://latex.codecogs.com/svg.latex?i%20%3D%200)

  ![j = 1, 2, 3, 4, ..., n](https://latex.codecogs.com/svg.latex?j%20%3D%201%2C%202%2C%203%2C%204%2C%20%5Cldots%2C%20n)

When ![i = 1](https://latex.codecogs.com/svg.latex?i%20%3D%201)

  ![j = 2, 3, 4, ..., n](https://latex.codecogs.com/svg.latex?j%20%3D%202%2C%203%2C%204%2C%20...%2C%20n)

For ![i = i'](https://latex.codecogs.com/svg.latex?i%20%3D%20i%27), there are ![(n - i' + 1)](https://latex.codecogs.com/svg.latex?%28n%20-%20i%27%20&plus;%201%29) many ![j](https://latex.codecogs.com/svg.latex?j)'s

Complexity is ![\sum_{i = 0}^{n-1}O(n - i + 1)](https://latex.codecogs.com/svg.latex?%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7DO%28n%20-%20i%20&plus;%201%29) which equals ![O\left((n+1)n\right)- O\left(\frac{(n-1)^2}{2}\right) = O(n^2)](https://latex.codecogs.com/svg.latex?O%5Cleft%28%28n&plus;1%29n%5Cright%29-%20O%5Cleft%28%5Cfrac%7B%28n-1%29%5E2%7D%7B2%7D%5Cright%29%20%3D%20O%28n%5E2%29)
