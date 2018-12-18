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

O(n + n) = O(2 \* n) = 2 \* O(n) = O(n)
