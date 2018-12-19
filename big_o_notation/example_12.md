# Example 12

This code counts all permutations of a string.
void permutation(String str)
{
  permutation(str, "");
}

```
void permutation(String str, String prefix)
{
  if (str.length() == 0)
  {
    System.out.println(prefix);
  }

  else
  {
    for (int i= 0; i < str.length(); i++)
    {
      String rem = str.substring(0, i) + str.substring(i + 1);
      permutation(rem, prefix + str.charAt(i));
    }
  }
}
```

Let n be the string length.

i = 0
  rem = string[0] + string[1]...

i = 1

i = 2
...
i = n

For each i, the time cost = O(1) + 
