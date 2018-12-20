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

![C_s = s \cdot (C_{s-1} + O(1)) + O(s)](https://latex.codecogs.com/svg.latex?C_s%20%3D%20s%20%5Ccdot%20%28C_%7Bs-1%7D%20&plus;%20O%281%29%29%20&plus;%20O%28s%29) gives ![C_s = O(s \cdot s!)](https://latex.codecogs.com/svg.latex?C_s%20%3D%20O%28s%20%5Ccdot%20s%21%29)
