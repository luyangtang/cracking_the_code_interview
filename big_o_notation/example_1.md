# Example 1

##### What is the runtime of the below code?
```
void foo(int[] array) {
  int sum = 0;
  int product = 1;
  for (int i= 0; i < array.length; i++) {
    sum += array[i];
    }
  for (int i= 0; i < array.length; i++) {
    product*= array[i];
  }
System.out.println(sum + ", " + product);
}
```
##### Solution

![](https://latex.codecogs.com/svg.latex?O%28n%20&plus;%20n%29%20%3D%20O%282%20%5C*%20n%29%20%3D%202%20%5C*%20O%28n%29%20%3D%20O%28n%29)
