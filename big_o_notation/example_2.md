# Example 2

##### What is the runtime of the below code?

```
void printPairs(int[] array) {
  for (int i= 0; i < array.length; i++)
  {
    for (int j = 0; j < array.length; j++)
    {
      System.out.println(array[i] + "," + array[j]);
    }
  }
}
```

##### Solution
![](https://latex.codecogs.com/svg.latex?O%28n%29%20*%20O%28n%29%20%3D%20O%28n%5E2%29)
