# Example 8


Suppose we had an algorithm that took in an array of strings, sorted each string, and then sorted the full
array. What would the runtime be?

Suppose the array have size L and s being the length of the longest string. Then to sort L strings the complexity is
![O(L) \cdot O(s \log s) = O(L \cdot s \cdot \log s)](https://latex.codecogs.com/svg.latex?O%28L%29%20%5Ccdot%20O%28s%20%5Clog%20s%29%20%3D%20O%28L%20%5Ccdot%20s%20%5Ccdot%20%5Clog%20s%29)

Sorting an array of size ![L](https://latex.codecogs.com/svg.latex?L) has complexity involves ![O(L \log L)](https://latex.codecogs.com/svg.latex?O%28L%20%5Clog%20L%29) many comparisons and each comparison has time complexity ![O(s)](https://latex.codecogs.com/svg.latex?O%28s%29) so the total complexity is ![O(L \cdot s \cdot \log L)](https://latex.codecogs.com/svg.latex?O%28L%20%5Ccdot%20s%20%5Ccdot%20%5Clog%20L%29).

Combining the two gives time complexity of
![O(L \cdot s \cdot (\log s + \log L))](https://latex.codecogs.com/svg.latex?O%28L%20%5Ccdot%20s%20%5Ccdot%20%28%5Clog%20s%20&plus;%20%5Clog%20L%29%29).
