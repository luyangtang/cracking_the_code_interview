# Big O notation

For recursion, one systematic way to calculate the runtime is to solve difference equation. For the following function

```
void foo(int n)
{
  DoSomething(); // complexity T_1(n)
  foo(n-1);
}
```

Then the difference equation is ![T(n) = T_1(n) + T(n-1)](https://latex.codecogs.com/svg.latex?T%28n%29%20%3D%20T_1%28n%29%20&plus;%20T%28n-1%29)
