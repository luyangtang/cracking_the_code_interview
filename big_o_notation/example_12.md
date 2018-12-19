# Example 12

This code counts all permutations of a string.
```

void permutation(String str)
{
  permutation(str, "");
}


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

C_s = s * (C_{s-1} + O(1)) + O(s) => C_s = O(s * s!)
